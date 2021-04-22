#include "widget.h"

int main() {
  Widget w(7);
  const Widget w2(8);
  w.draw();
  w2.draw();
  return 0;
}
