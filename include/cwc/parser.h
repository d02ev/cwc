#ifndef PARSER_H
#define PARSER_H

#include <fstream>

class Parser {
  public:
  Parser() = default;
  ~Parser() = default;

  static int parse_c_arg(std::ifstream &file) noexcept;
  static int parse_l_arg(std::ifstream &file) noexcept;
  static int parse_w_arg(std::ifstream &file) noexcept;
};

#endif // PARSER_H
