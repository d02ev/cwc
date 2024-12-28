#include <format>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include "cwc/parser.h"

int main(int argc, char *argv[]) {
  std::unordered_set<std::string> valid_cmd_args = {"-l", "-w", "-c", "-m"};

  if (argc == 2) {
    // value from stdin
    if (valid_cmd_args.contains(argv[1])) {
      std::string arg = &argv[1][0];
      if (arg == "-c") {
        size_t c_arg = Parser::parse_c_arg(std::cin);

        std::cout << c_arg << std::endl;
        std::cin.clear();

        return EXIT_SUCCESS;
      }
      if (arg == "-l") {
        size_t l_arg = Parser::parse_l_arg(std::cin);

        std::cout << l_arg << std::endl;
        std::cin.clear();

        return EXIT_SUCCESS;
      }
      if (arg == "-w") {
        size_t w_arg = Parser::parse_w_arg(std::cin);

        std::cout << w_arg << std::endl;
        std::cin.clear();

        return EXIT_SUCCESS;
      }
      if (arg == "-m") {

      }
    } else {
      std::ifstream file(argv[1], std::ios::binary);
      size_t c_arg = Parser::parse_c_arg(file), l_arg = Parser::parse_l_arg(file), w_arg = Parser::parse_w_arg(file);
      std::string res =
              std::format("{} {} {} {}", std::to_string(c_arg), std::to_string(l_arg), std::to_string(w_arg), argv[1]);

      std::cout << res << std::endl;
      file.close();

      return EXIT_SUCCESS;
    }
  }
  if (argc == 3) {
    std::ifstream file(argv[2], std::ios::binary);
    std::string arg = &argv[1][0];

    if (arg == "-c") {
      size_t c_arg = Parser::parse_c_arg(file);
      std::string res = std::format("{} {}", std::to_string(c_arg), argv[2]);

      std::cout << res << std::endl;
      file.close();

      return EXIT_SUCCESS;
    }
    if (arg == "-l") {
      size_t l_arg = Parser::parse_l_arg(file);
      std::string res = std::format("{} {}", std::to_string(l_arg), argv[2]);

      std::cout << res << std::endl;
      file.close();

      return EXIT_SUCCESS;
    }
    if (arg == "-w") {
      size_t w_arg = Parser::parse_w_arg(file);
      std::string res = std::format("{} {}", std::to_string(w_arg), argv[2]);

      std::cout << res << std::endl;
      file.close();

      return EXIT_SUCCESS;
    }
    if (arg == "-m") {
      std::wifstream file_(argv[2], std::ios::binary);
      size_t m_arg = Parser::parse_m_arg(file_);
      std::string res = std::format("{} {}", std::to_string(m_arg), argv[2]);

      std::cout << res << std::endl;
      file_.close();

      return EXIT_SUCCESS;
    }
  }


  // for file inputs
  // if (std::cin.peek() == EOF) {
  //   // argc == 2
  //   // cwc text.txt
  //   // -c -l -w text.txt
  //   if (argc == 2) {
  //     std::ifstream file(argv[1], std::ios::binary);
  //     size_t c_arg = Parser::parse_c_arg(file), l_arg = Parser::parse_l_arg(file), w_arg = Parser::parse_w_arg(file);
  //     std::string res =
  //             std::format("{} {} {} {}", std::to_string(c_arg), std::to_string(l_arg), std::to_string(w_arg), argv[1]);
  //
  //     std::cout << res << std::endl;
  //     file.close();
  //
  //     return EXIT_SUCCESS;
  //   }
  //   // argc = 3
  //   // cwc -l|-w|-c test.txt
  //   // -l|-w|-c test.txt
  //   if (argc == 3) {
  //     std::ifstream file(argv[2], std::ios::binary);
  //     char *arg = &argv[1][0];
  //
  //     if (arg == "-c") {
  //       size_t c_arg = Parser::parse_c_arg(file);
  //       std::string res = std::format("{} {}", std::to_string(c_arg), argv[2]);
  //
  //       std::cout << res << std::endl;
  //       file.close();
  //
  //       return EXIT_SUCCESS;
  //     }
  //     if (arg == "-l") {
  //       size_t l_arg = Parser::parse_l_arg(file);
  //       std::string res = std::format("{} {}", std::to_string(l_arg), argv[2]);
  //
  //       std::cout << res << std::endl;
  //       file.close();
  //
  //       return EXIT_SUCCESS;
  //     }
  //     if (arg == "-w") {
  //       size_t w_arg = Parser::parse_w_arg(file);
  //       std::string res = std::format("{} {}", std::to_string(w_arg), argv[2]);
  //
  //       std::cout << res << std::endl;
  //       file.close();
  //
  //       return EXIT_SUCCESS;
  //     }
  //     if (arg == "-m") {
  //       std::wifstream file_(argv[2], std::ios::binary);
  //       size_t m_arg = Parser::parse_m_arg(file_);
  //       std::string res = std::format("{} {}", std::to_string(m_arg), argv[2]);
  //
  //       std::cout << res << std::endl;
  //       file_.close();
  //
  //       return EXIT_SUCCESS;
  //     }
  //   }
  // } else {
  //   char *arg = &argv[1][0];
  //   if (arg == "-c") {
  //     size_t c_arg = Parser::parse_c_arg(std::cin);
  //
  //     std::cout << c_arg << std::endl;
  //     std::cin.clear();
  //
  //     return EXIT_SUCCESS;
  //   }
  //   if (arg == "-l") {
  //     size_t l_arg = Parser::parse_l_arg(std::cin);
  //
  //     std::cout << l_arg << std::endl;
  //     std::cin.clear();
  //
  //     return EXIT_SUCCESS;
  //   }
  //   if (arg == "-w") {
  //     size_t w_arg = Parser::parse_w_arg(std::cin);
  //
  //     std::cout << w_arg << std::endl;
  //     std::cin.clear();
  //
  //     return EXIT_SUCCESS;
  //   }
  //   if (arg == "-m") {
  //   }
  // }

  return EXIT_FAILURE;
}
