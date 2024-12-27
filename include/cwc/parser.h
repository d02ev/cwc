#ifndef PARSER_H
#define PARSER_H

#include <fstream>

class Parser {
  public:
  Parser() = default;
  ~Parser() = default;

  static size_t parse_c_arg(std::ifstream &file) noexcept;
  static size_t parse_l_arg(std::ifstream &file) noexcept;
  static size_t parse_w_arg(std::ifstream &file) noexcept;
  static size_t parse_m_arg(std::wifstream &file) noexcept;
  // static size_t parse_std_input(std::wifstream &file) noexcept;
};

#endif // PARSER_H
