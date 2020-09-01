#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe() {
  std::cout << "use_count == " << gw.use_count() << ": ";
  if (auto spt = gw.lock()) {
    std::cout << *spt << "\n";
  } else {
    std::cout << "gw is expired\n";
  }
}

int main() {
  {
    auto sp = std::make_shared<int>(42);
    gw = sp;
    observe();
  }
  observe();
  return 0;
}
