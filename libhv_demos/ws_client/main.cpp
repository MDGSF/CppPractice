#include "WebSocketClient.h"
using namespace hv;

int main(int argc, char** argv) {
  WebSocketClient ws;
  ws.onopen = []() { printf("onopen\n"); };
  ws.onmessage = [](const std::string& msg) {
    printf("onmessage: %.*s\n", (int)msg.size(), msg.data());
  };
  ws.onclose = []() { printf("onclose\n"); };

  // reconnect: 1,2,4,8,10,10,10...
  reconn_setting_t reconn;
  reconn_setting_init(&reconn);
  reconn.min_delay = 1000;
  reconn.max_delay = 10000;
  reconn.delay_policy = 2;
  ws.setReconnect(&reconn);

  ws.open("ws://127.0.0.1:9999/test");

  std::string str;
  while (std::getline(std::cin, str)) {
    if (!ws.isConnected()) break;
    if (str == "quit") {
      ws.close();
      break;
    }
    ws.send(str);
  }

  return 0;
}
