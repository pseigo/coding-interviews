#include "toolbelt.hpp"

// BEGIN UTILITIES
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

#define PRINT(x) std::cout << "DEBUG: " << x << std::endl;
#define PRINT_VALUE(x) std::cout << "DEBUG: " << #x << " => " << x << std::endl;
#define MAX_VALUE(x) std::cout << "DEBUG: Type " << #x << " is " << sizeof(x) << " byte" << (sizeof(x) > 1 ? "s" : "") << " (" << CHAR_BIT << " bits each) with a max value of 2^" << sizeof(x) * CHAR_BIT << " = " << std::pow(2, sizeof(x) * CHAR_BIT) << std::endl

constexpr size_t ce_pow(size_t a, size_t b)
{
  if (b == 0) return 1;
  const size_t a_init(a);
  for (size_t i = 0; i < (b - 1); i++) a *= (a_init);
  return a;
}
// END UTILITIES

#include <sstream>
#include <string>

namespace PAJS
{
  std::vector<std::string> Toolbelt::tokenize(const std::string &str, char delimiter)
  {
    std::vector<std::string> tokens;
    std::istringstream strStream(str);

    std::string tmp;
    while (std::getline(strStream, tmp, delimiter)) {
        if (!tmp.empty() && tmp.at(0) != delimiter) {
          tokens.push_back(tmp);
        }
    }

    return tokens;

    // An approach for space delimiters:
    // std::copy(std::istream_iterator<std::string>(strStream),
    //  std::istream_iterator<std::string>(),
    //  std::back_inserter(tokens));
  }
}
