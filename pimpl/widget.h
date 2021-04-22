#include <iostream>
#include <memory>

class Widget {
 public:
  Widget(int);
  ~Widget();

  Widget(const Widget&) = delete;
  Widget& operator=(const Widget&) = delete;

  Widget(Widget&&);
  Widget& operator=(Widget&&);

  void draw() const;
  void draw();
  bool shown() const { return true; }

 private:
  class WidgetImpl;
  std::unique_ptr<WidgetImpl> m_impl;
};
