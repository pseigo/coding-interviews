#include <bits/stdc++.h>

using namespace std;

struct Item {
  unsigned weight;
  int value;
  Item(size_t weight, int value) : weight(weight), value(value) { }
};

size_t calc_optimal(const vector<Item> &items, const vector<vector<int>> &optimal, size_t item, size_t weight);

unsigned knapsack(vector<Item> items, size_t maxWeight)
{
  // 1-based indexing for items to match solution matrix
  items.insert(items.begin(), Item(0, 0));

  const size_t numCols = maxWeight + 1;
  const size_t numRows = items.size();
  vector<vector<int>> optimal(numRows, vector<int>(numCols, 0));

  for (size_t item = 1; item < numRows; item++) {
    for (size_t weight = 0; weight < numCols; weight++) {
      optimal[item][weight] = calc_optimal(items, optimal, item, weight);
    }
  }

  return optimal[numRows - 1][numCols - 1];
}

size_t calc_optimal(const vector<Item> &items, const vector<vector<int>> &optimal, size_t item, size_t weight)
{
  const unsigned weight_i = items[item].weight;
  const int value_i = items[item].value;

  if (weight_i > weight)
    return optimal[item - 1][weight];

  return max(
    optimal[item - 1][weight],
    value_i + optimal[item - 1][weight - weight_i]
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
  // Same as Subset Sum.
  const vector<Item> items_1 = {Item(4, 4), Item(6, 6), Item(9, 9)};
  check(10, knapsack(items_1, 11));

  const vector<Item> items_2 = {Item(5, 5), Item(5, 7), Item(2, 3), Item(3, 5)};
  check(8, knapsack(items_2, 5));

  // Throwing some negatives and zeros in there.
  const vector<Item> items_3 = {Item(2, 1), Item(0, -1), Item(1, 0), Item(1, 1), Item(1, 1), Item(0, 10)};
  check(12, knapsack(items_3, 3));
}
