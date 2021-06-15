#include "CLI/CLI.hpp"

int main(int argc, char *argv[]) try {
  CLI::App app{"test"};

  // 0:trace, 1:debug, 2:info, 3:warn, 4:error, 5:critical, 6:off
  int32_t log_level = 2;
  app.add_option("-l,--log", log_level,
                 "log level, 0:trace, 1:debug, 2:info, 3:warn, 4:error, "
                 "5:critical, 6:off");

  CLI11_PARSE(app, argc, argv);

  return 0;
} catch (std::exception &e) {
  std::cerr << e.what() << std::endl;
}
