// BEGIN UTILITIES
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

#define PRINT(x) std::cout << "DEBUG: " << x << std::endl;
#define PRINT_VALUE(x) std::cout << "DEBUG: " << #x << " => " << x << std::endl;
#define MAX_VALUE(x) std::cout << "DEBUG: Type " << #x << " is " << sizeof(x) << " byte" << (sizeof(x) > 1 ? "s" : "") << " (" << CHAR_BIT << " bits each) with a max value of 2^" << sizeof(x) * CHAR_BIT << " = " << std::pow(2, sizeof(x) * CHAR_BIT) << std::endl
// END UTILITIES

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define USE_ARRAY_IMPL 1
#define USE_MAP_IMPL !USE_ARRAY_IMPL

class Solution {
public:
    /*
     * O(n) time, O(m) space (m = 256)
     *
     * Runtime: 8 ms, faster than 91.54% of C++ online submissions for Longest Substring Without Repeating Characters.
     * Memory Usage: 7.3 MB, less than 5.05% of C++ online submissions for Longest Substring Without Repeating Characters.
     *
     * Observations:
     * - Both pointers only move forward (for left, guaranteed by max()).
     */
    #if USE_ARRAY_IMPL == 1
    int lengthOfLongestSubstring(string s)
    {
      size_t maxLength = 0;
      size_t lastSeenIndex[256];
      memset(lastSeenIndex, -1, sizeof(lastSeenIndex));

      for (size_t left = 0, right = 0; right < s.length(); right++) {
        const size_t thisChar = s[right];
        const size_t lastSeenIndexForThisChar = lastSeenIndex[thisChar];

        if (lastSeenIndexForThisChar != -1ul) {
          left = max(left, lastSeenIndexForThisChar + 1);
        }

        lastSeenIndex[thisChar] = right;
        maxLength = max(maxLength, right - left + 1);
      }

      return maxLength;
    }
    #endif

    /*
     * O(n) time, O(min(n, m)) space (m = 256)
     *
     * Runtime: 24 ms, faster than 73.25% of C++ online submissions for Longest Substring Without Repeating Characters.
     * Memory Usage: 9 MB, less than 5.05% of C++ online submissions for Longest Substring Without Repeating Characters.
     */
    #if USE_MAP_IMPL == 1
    int lengthOfLongestSubstring(string s)
    {
      unordered_map<char, size_t> lastSeenIndex;
      size_t maxLength = 0;

      for (size_t left = 0, right = 0; right < s.length(); right++) {
        if (lastSeenIndex.find(s[right]) != lastSeenIndex.end()) {
          left = max(left, lastSeenIndex.at(s[right]) + 1);
        }

        lastSeenIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
      }

      return maxLength;
    }
    #endif

private:

};

// TEST SOLUTION

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }
  test_case_number++;
}

int main()
{
  Solution s;

  check(3, s.lengthOfLongestSubstring("abc"));
  check(3, s.lengthOfLongestSubstring("aabc"));
  check(2, s.lengthOfLongestSubstring("aabb"));
  check(5, s.lengthOfLongestSubstring("poiihjkl"));
  check(5, s.lengthOfLongestSubstring("asdf  123"));
  check(4, s.lengthOfLongestSubstring("12342"));
  check(3, s.lengthOfLongestSubstring("dvdf"));
  check(2, s.lengthOfLongestSubstring("abba"));
  check(3, s.lengthOfLongestSubstring("abcca"));
}
