#include <bits/stdc++.h>

using namespace std;

size_t calc_optimal(const vector<unsigned> &items, const vector<vector<unsigned>> &optimal, size_t item, size_t weight);

unsigned subset_sum(vector<unsigned> items, size_t maxWeight)
{
  // 1-based indexing for items to match solution matrix
  items.insert(items.begin(), 0);

  const size_t numCols = maxWeight + 1;
  const size_t numRows = items.size();
  vector<vector<unsigned>> optimal(numRows, vector<unsigned>(numCols, 0));

  for (size_t item = 1; item < numRows; item++) {
    for (size_t weight = 0; weight < numCols; weight++) {
      optimal[item][weight] = calc_optimal(items, optimal, item, weight);
    }
  }

  return optimal[numRows - 1][numCols - 1];
}

size_t calc_optimal(const vector<unsigned> &items, const vector<vector<unsigned>> &optimal, size_t item, size_t weight)
{
  const unsigned weight_i = items[item];

  if (weight_i > weight)
    return optimal[item - 1][weight];

  return max(
    optimal[item - 1][weight],
    weight_i + optimal[item - 1][weight - weight_i]
  );
}



////////////// Tests //////////////
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
  check(10, subset_sum({4, 6, 9}, 11));
  check(0, subset_sum({4, 2, 3}, 1));
  check(2, subset_sum({4, 2, 3}, 2));
  check(3, subset_sum({4, 2, 3}, 3));
  check(4, subset_sum({4, 2, 3}, 4));
  check(5, subset_sum({4, 2, 3}, 5));
  check(6, subset_sum({4, 2, 3}, 6));
  check(7, subset_sum({4, 2, 3}, 7));
  check(7, subset_sum({4, 2, 3}, 8));
  check(9, subset_sum({4, 2, 3}, 9));
  check(9, subset_sum({4, 2, 3}, 10));
}
