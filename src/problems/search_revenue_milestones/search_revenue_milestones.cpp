#include <bits/stdc++.h>

using namespace std;

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Maintain a sorted, parallel array to milestones
  vector<pair<int, int>> milestonePairs;
  for (size_t i = 0; i < milestones.size(); i++) {
    milestonePairs.push_back(make_pair(milestones[i], i));
  }

  sort(milestonePairs.begin(), milestonePairs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.first <= b.first;
  });

  long long totalRevenue = 0;
  size_t mIdx = 0;

  // Record all the days where milestones were hit
  for (size_t day = 0; day < revenues.size() && mIdx < milestonePairs.size(); day++)
  {
    totalRevenue += revenues[day];
    while (mIdx < milestones.size() && totalRevenue >= milestonePairs[mIdx].first) {
      milestonePairs[mIdx].first = day + 1;
      mIdx++;
    }
  }

  // Set any milestones not hit to -1
  for (size_t i = 0; i < milestonePairs.size(); i++)
  {
    milestones[milestonePairs[i].second] = milestonePairs[i].first;
    if (i >= mIdx) {
      milestones[milestonePairs[i].second] = -1;
    }
  }

  return milestones;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printIntegerVector(vector <int> array) {
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

void check(vector <int>& expected, vector <int>& output) {
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
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  // Testcase 1
  // int n_1 = 5, k_1 = 4;
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  // int n_2 = 6, k_2 = 5;
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);

  // Add your own test cases here
  // int n_3 = 6, k_3 = 5;
  vector <int> revenues_3{10, 10, 20, 30, 5};
  vector <int> milestones_3{70, 80};
  vector <int> expected_3{4, -1};
  vector <int> output_3 = getMilestoneDays(revenues_3, milestones_3);
  check(expected_3, output_3);
}
