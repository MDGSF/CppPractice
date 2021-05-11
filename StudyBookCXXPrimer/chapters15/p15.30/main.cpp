// Copyright 2021 <HuangJian 1342042894@qq.com>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <fstream>     // ifstream
#include <functional>  // function object, bind
#include <iostream>    // cin, cout, cerr
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double pri) : bookNo(book), price(pri) {}
  virtual ~Quote() = default;

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

  virtual std::ostream &debug(std::ostream &os) const {
    os << "Quote::bookNo " << bookNo << " Quote::price " << price;
    return os;
  }

 protected:
  double price = 0.0;

 private:
  std::string bookNo;
};

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double pri, std::size_t qty, double disc)
      : Quote(book, pri), quantity(qty), discount(disc) {}

  double net_price(std::size_t n) const = 0;

  std::ostream &debug(std::ostream &os) const override {
    Quote::debug(os) << " Disc_quote::quantity " << quantity
                     << " Disc_quote::discount " << discount;
    return os;
  }

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double pri, std::size_t qty, double disc)
      : Disc_quote(book, pri, qty, disc) {}

  double net_price(std::size_t n) const override {
    if (n >= quantity) {
      return n * price * (1 - discount);
    } else {
      return n * price;
    }
  }
  Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
  Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};

class Limit_quote : public Disc_quote {
 public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double pri, std::size_t qty, double disc)
      : Disc_quote(book, pri, qty, disc) {}

  double net_price(std::size_t n) const override {
    if (n <= quantity) {
      return n * price * (1 - discount);
    } else {
      return (n - quantity) * price + quantity * price * (1 - discount);
    }
  }
  Limit_quote *clone() const & override { return new Limit_quote(*this); }
  Limit_quote *clone() && override { return new Limit_quote(std::move(*this)); }
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

class Basket {
 public:
  void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
  void add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }

  double total_receipt(std::ostream &) const;

 private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }

  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(std::ostream &os) const {
  double sum = 0;
  for (auto it = items.cbegin(); it != items.cend();
       it = items.upper_bound(*it))
    sum += print_total(os, **it, items.count(*it));
  os << "Total sale: " << sum << std::endl;
  return sum;
}

int main() {
  Basket basket;
  for (auto i = 0; i < 20; ++i) basket.add_item(Quote("abc", 5));
  for (auto i = 0; i < 20; ++i) basket.add_item(Bulk_quote("def", 5, 10, 0.2));
  for (auto i = 0; i < 20; ++i) basket.add_item(Limit_quote("ghi", 5, 10, 0.2));

  // FIXME Note that if we add book with same ISBN but different type (i.e.
  // price, discount type), then the type of the first added book with same
  // ISBN will be used as the type for all other same ISBN books. e.g.:
  basket.add_item(Bulk_quote("jkl", 5, 10, 0.2));
  for (auto i = 0; i < 5; ++i) basket.add_item(Quote("jkl", 5));
  for (auto i = 0; i < 4; ++i) basket.add_item(Limit_quote("jkl", 5, 10, 0.2));

  basket.total_receipt(std::cout);

  return 0;
}

