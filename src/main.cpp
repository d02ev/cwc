#include <format>
#include <fstream>
#include <iostream>
#include "cwc/parser.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    // TODO: Print Usage doc
  }
  if (argc == 2) {
    const std::string filename = argv[1];
    std::ifstream file(filename);

    size_t c_arg_res = Parser::parse_c_arg(file), l_arg_res = Parser::parse_l_arg(file),
           w_arg_res = Parser::parse_w_arg(file);

    std::cout << std::format("{} {} {} {}\n", c_arg_res, l_arg_res, w_arg_res, filename);

    return 0;
  }
  if (argc == 3) {
    const std::string filename = argv[2];
    std::ifstream file(filename, std::ios::binary);

    if (const std::string cmd_line_arg(argv[1]); cmd_line_arg == "-c") {
      std::cout << Parser::parse_c_arg(file) << " " << filename << std::endl;
    } else if (cmd_line_arg == "-l") {
      std::cout << Parser::parse_l_arg(file) << " " << filename << std::endl;
    } else if (cmd_line_arg == "-w") {
      std::cout << Parser::parse_w_arg(file) << " " << filename << std::endl;
    } else if (cmd_line_arg == "-m") {
      file.close();
      std::wifstream file_(filename, std::ios::binary);
      std::cout << Parser::parse_m_arg(file_) << " " << filename << std::endl;
    }

    file.close();
    return 0;
  }


  return 0;
}
