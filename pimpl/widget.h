#include <iostream>
#include <memory>

class widget {
  class impl;
  std::unique_ptr<impl> pImpl;

 public:
  void draw() const;
  void draw();
  bool shown() const { return true; }
  widget(int);
  ~widget();
  widget(widget&&);
  widget(const widget&) = delete;
  widget& operator=(widget&&);
  widget& operator=(const widget&) = delete;
};
