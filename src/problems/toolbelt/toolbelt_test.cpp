#include "toolbelt.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace PAJS;

std::string tokenize(const std::string &str, char delimiter)
{
  std::vector<std::string> tokens = Toolbelt::tokenize(str, delimiter);
  std::string concatenated;
  for (const auto &e : tokens) {
    std::cout << e << std::endl;
    concatenated += e;
  }
  return concatenated;
}

int main()
{
  tokenize("", ' ');
  tokenize("Hello, world! This    is   a  test. !!", ' ');
  tokenize("Some\nnewline delimited\ntext,   of    course.", '\n');
  tokenize(tokenize("Composable\nnewline delimited\ntext,   of    course!", '\n'), ' ');
}
