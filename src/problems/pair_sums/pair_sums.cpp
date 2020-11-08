#include <bits/stdc++.h>

using namespace std;

#define HASH_TABLE_IMPL 1
#define SORTING_IMPL !HASH_TABLE_IMPL

#if HASH_TABLE_IMPL
// Time: O(n)
// Space: O(n)
int numberOfWays(vector<int>& arr, int k) {
  // A -> {count(A), count(B)} such that A + B = k
  unordered_map<int, pair<int, int>> counts;

  // Build counts
  for (auto &e : arr) {
    if (e < k) {
      const int difference = k - e;

      if (counts.find(e) != counts.end()) {
        counts[e].first += 1;
      } else if (counts.find(difference) != counts.end()) {
        counts[difference].second += 1;
      } else {
        // Neither e nor (k - e) has been recorded yet
        counts[e] = make_pair(1, 0);
      }
    }
  }

  // Sum number of pairs
  size_t ways = 0;
  for (const auto &e : counts) {
    const pair<int, int> &count = e.second;

    if (e.first == k / 2) {
      ways += count.first * (count.first - 1) / 2;
    } else {
      ways += count.first * count.second;
    }
  }

  return ways;
}
#endif

#if SORTING_IMPL
// Time: O(n log n) for sorting.
// Space: O(1) if we can edit the array, otherwise O(n) to make a copy.
int numberOfWays(vector<int>& arr, int k) {
   std::sort(arr.begin(), arr.end());

  // Write your code here
  size_t ways = 0;

  typedef vector<int>::iterator vec_it_t;
  vec_it_t left = arr.begin();
  vec_it_t right = arr.end() - 1;

  while (left != right) {
    const int leftValue = *left;
    const int rightValue = *right;
    const int sum = leftValue + rightValue;

    if (sum > k) {
      --right;
    } else if (sum < k) {
      ++left;
    } else if (left + 1 == right) {
      ++ways;
      --right;
    } else { // sum == k
      size_t leftCount = 1, rightCount = 1;
      ++left;
      --right;

      while (left != right && *left == leftValue) {
        ++leftCount;
        ++left;
      }

      while (right != left && *right == rightValue) {
        ++rightCount;
        --right;
      }

      if (leftValue == rightValue && leftValue == (k / 2)) {
        const size_t occurrences = leftCount + rightCount + 1;
        ways += occurrences * (occurrences - 1) / 2;
      } else {
        ways += leftCount * rightCount;
      }
    }
  }

  return ways;
}
#endif

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

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

int main() {

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
