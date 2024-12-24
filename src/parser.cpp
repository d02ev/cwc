#include "cwc/parser.h"

int Parser::parse_c_arg(std::ifstream &file) noexcept {
  char ch;
  int num_of_bytes = 0;

  while (file.get(ch)) {
    ++num_of_bytes;
  }

  return num_of_bytes;
}

int Parser::parse_l_arg(std::ifstream &file) noexcept {
  std::string line;
  int num_of_lines = 0;

  while (std::getline(file, line)) {
    ++num_of_lines;
  }

  return num_of_lines;
}

int Parser::parse_w_arg(std::ifstream &file) noexcept {
  std::string word;
  int num_of_words = 0;

  while (file >> word) {
    ++num_of_words;
  }

  return num_of_words;
}
