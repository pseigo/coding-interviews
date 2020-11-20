#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> words)
    {
        unordered_set<string> wordsSeen;
        copy(words.begin(), words.end(), inserter(wordsSeen, wordsSeen.end()));
        vector<string> concatenatedWords;

        for (const auto & word : words) {
          if (word.empty()) {
            continue;
          }

          wordsSeen.erase(word);
          if (isConcatenation(word, wordsSeen)) {
            concatenatedWords.push_back(word);
          }
          wordsSeen.insert(word);
        }

        return concatenatedWords;
    }

private:
    bool isConcatenation(string word, const unordered_set<string> &wordsSeen)
    {
        bool *canSplitAt = new bool[word.length() + 1];
        memset(canSplitAt, false, word.length() + 1);
        canSplitAt[0] = true;

        for (size_t right = 1; right <= word.length(); right++) {
          for (size_t left = 0; left < right; left++) {
            if (canSplitAt[left] && wordsSeen.find(word.substr(left, right - left)) != wordsSeen.end()) {
              canSplitAt[right] = true;
              break;
            }
          }
        }

        return canSplitAt[word.length()];
    }
};





// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printStringVector(const vector<string> &array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector<string> &expected, vector<string> &output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printStringVector(expected);
    cout << " Your output: ";
    printStringVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  Solution s;
  vector<string> test_1 = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
  vector<string> expected_1 = {"catsdogcats","dogcatsdog","ratcatdogcat"};
  vector<string> output_1 = s.findAllConcatenatedWordsInADict(test_1);
  check(expected_1, output_1);

  // Add your own test cases here

}
