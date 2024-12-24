#include <iostream>
#include <fstream>
#include "cwc/parser.h"

int main(int argc, char* argv[]) {
  const std::string filename = argv[2];
  std::ifstream file(filename, std::ios::in);

  if (const std::string cmd_line_arg(argv[1]); cmd_line_arg == "-c") {
    std::cout << parse_c_arg(file) << std::endl;
  } else if (cmd_line_arg == "-l") {
    std::cout << parse_l_arg(file) << std::endl;
  } else if (cmd_line_arg == "-w") {
    std::cout << parse_w_arg(file) << std::endl;
  }

  file.close();

  return 0;
}
