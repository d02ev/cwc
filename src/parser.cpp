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

// size_t Parser::parse_std_input(std::ifstream &file) noexcept { return 0; }
