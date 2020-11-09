#if !defined(CODING_INTERVIEWS_PROBLEMS_TOOLBELT)
#define CODING_INTERVIEWS_PROBLEMS_TOOLBELT

#include <string>
#include <vector>

namespace PAJS
{
  class Toolbelt
  {
  public:
    static std::vector<std::string> tokenize(const std::string&, char delimiter);
  };
}

#endif
