#include "toolbelt.hpp"

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
