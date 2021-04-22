#include "widget.h"

class Widget::WidgetImpl {
 public:
  WidgetImpl(int n) : n(n) {}

  void draw(const Widget& w) const {
    // this call to public member function requires the back-reference
    if (w.shown()) {
      std::cout << "drawing a const Widget " << n << '\n';
    }
  }

  void draw(const Widget& w) {
    if (w.shown()) {
      std::cout << "drawing a non-const Widget " << n << '\n';
    }
  }

 private:
  int n;
};

Widget::Widget(int n) : m_impl{new WidgetImpl(n)} {}

Widget::~Widget() = default;

Widget::Widget(Widget&&) = default;

Widget& Widget::operator=(Widget&&) = default;

void Widget::draw() const { m_impl->draw(*this); }

void Widget::draw() { m_impl->draw(*this); }

