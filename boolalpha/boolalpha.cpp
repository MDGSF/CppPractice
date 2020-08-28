#include <iostream>
#include <locale>
#include <sstream>

int main() {
  std::cout << std::boolalpha << "boolalpha true: " << true << '\n'
            << "boolalpha false: " << false << '\n';
  std::cout << std::noboolalpha << "noboolalpha true: " << true << '\n'
            << "noboolalpha false: " << false << '\n';

  bool b1;
  bool b2;
  std::istringstream is("true false");
  is >> std::boolalpha >> b1 >> b2;
  std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';
  return 0;
}

