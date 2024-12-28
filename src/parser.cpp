#include "cwc/parser.h"

#include <codecvt>
#include <iostream>
#include <locale>

size_t Parser::parse_c_arg(std::ifstream &file) noexcept {
  char ch;
  int num_of_bytes = 0;

  while (file.get(ch)) {
    ++num_of_bytes;
  }

  file.clear();
  file.seekg(0, std::ios::beg);

  return num_of_bytes;
}

size_t Parser::parse_c_arg(std::istream &std_input) noexcept {
  char ch;
  int num_of_bytes = 0;

  while (std_input.get(ch)) {
    ++num_of_bytes;
  }

  std_input.clear();
  std_input.seekg(0, std::ios::beg);

  return num_of_bytes;
}

size_t Parser::parse_l_arg(std::ifstream &file) noexcept {
  std::string line;
  int num_of_lines = 0;

  while (std::getline(file, line)) {
    ++num_of_lines;
  }

  file.clear();
  file.seekg(0, std::ios::beg);

  return num_of_lines;
}

size_t Parser::parse_l_arg(std::istream &std_input) noexcept {
  std::string line;
  int num_of_lines = 0;

  while (std::getline(std_input, line)) {
    ++num_of_lines;
  }

  std_input.clear();
  std_input.seekg(0, std::ios::beg);

  return num_of_lines;
}

size_t Parser::parse_w_arg(std::ifstream &file) noexcept {
  std::string word;
  int num_of_words = 0;

  while (file >> word) {
    ++num_of_words;
  }

  file.clear();
  file.seekg(0, std::ios::beg);

  return num_of_words;
}

size_t Parser::parse_w_arg(std::istream &std_input) noexcept {
  std::string word;
  int num_of_words = 0;

  while (std_input >> word) {
    ++num_of_words;
  }

  std_input.clear();
  std_input.seekg(0, std::ios::beg);

  return num_of_words;
}

size_t Parser::parse_m_arg(std::wifstream &file) noexcept {
  file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

  size_t num_of_bytes_loc = 0;
  wchar_t ch;

  while (file.get(ch)) {
    ++num_of_bytes_loc;
  }

  file.clear();
  file.seekg(0, std::ios::beg);

  return num_of_bytes_loc;
}

size_t Parser::parse_m_arg(const std::string &std_input) noexcept {
  size_t num_of_char_mult = 0;

  for (const char& ch : std_input) {
    if ((ch & 0xC0) != 0x80) {
      ++num_of_char_mult;
    }
  }

  return num_of_char_mult;
}
