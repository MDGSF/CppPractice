#include <iostream>
#include <vector>

struct Noisy {
  Noisy() { std::cout << "constructed\n"; }
  Noisy(const Noisy&) { std::cout << "copy-constructed\n"; }
  Noisy(Noisy&&) { std::cout << "move-constructed\n"; }
  ~Noisy() { std::cout << "destructed\n"; }
};

std::vector<Noisy> f() {
  std::vector<Noisy> v = std::vector<Noisy>(3);
  return v;
}

void g(std::vector<Noisy> arg) {
  std::cout << "arg.size() = " << arg.size() << std::endl;
}

int main() {
  std::vector<Noisy> v = f();
  g(f());
  // g(v);
  // g(std::move(v));
  return 0;
}
