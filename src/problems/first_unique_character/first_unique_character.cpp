#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;

class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> frequencies = tally_char_frequencies(s);

    for (size_t index = 0; index < s.size(); index++) {
      const char & c = s[index];

      auto elem = frequencies.find(c);

      if (elem != frequencies.end() && elem->second == 1) {
        return index;
      }
    }

    return -1;
  }

private:
  map<char, int> tally_char_frequencies(const string & s) {
    map<char, int> frequencies;

    for (const char & c : s) {
      auto elem = frequencies.find(c);

      if (elem != frequencies.end()) {
        frequencies[c] += 1;
      } else {
        frequencies[c] = 1;
      }
    }

    return frequencies;
  }
};

///// Test cases /////
using std::cout;
using std::endl;

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void assert_equal(int expected, int output) {
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";

  if (output == expected) {
    cout << rightTick << " Test #" << test_case_number << " (PASSED)\n";
  } else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }

  test_case_number++;
}

int main()
{
  using std::vector;
  using std::pair;
  using std::make_pair;

  vector<pair<string, int>> test_data = {
    make_pair("leetcode", 0),
    make_pair("loveleetcode", 2),
    make_pair("aabb", -1)
    // make_pair("", ),
  };

  Solution impl;

  for (const auto & test_case : test_data) {
    const string input = test_case.first;
    const int expected_output = test_case.second;
    const int actual_output = impl.firstUniqChar(input);

    assert_equal(actual_output, expected_output);
  }
}
