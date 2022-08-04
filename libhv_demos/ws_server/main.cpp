#include "WebSocketServer.h"
using namespace hv;

int main(int argc, char** argv) {
  WebSocketService ws;
  ws.onopen = [](const WebSocketChannelPtr& channel, const std::string& url) {
    printf("onopen: GET %s\n", url.c_str());
  };
  ws.onmessage = [](const WebSocketChannelPtr& channel,
                    const std::string& msg) {
    printf("onmessage: %.*s\n", (int)msg.size(), msg.data());
  };
  ws.onclose = [](const WebSocketChannelPtr& channel) { printf("onclose\n"); };

  WebSocketServer server;
  server.registerWebSocketService(&ws);
  server.setPort(9999);
  server.setThreadNum(4);
  server.run();
  return 0;
}
