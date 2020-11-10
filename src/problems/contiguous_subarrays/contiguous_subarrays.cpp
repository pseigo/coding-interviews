#include <bits/stdc++.h>

using namespace std;

vector<int> CountSubarrays(vector <int> arr) {
  const size_t numElems = arr.size();
  vector<int> endCount(numElems, 1);

  for (size_t i = 1; i < numElems; i++) {
    long long farthestLeft = i;
    long long prev = farthestLeft - 1;

    while (prev >= 0 && arr[prev] < arr[i]) {
      prev -= arr[prev];
      farthestLeft = prev + 1;
    }

    farthestLeft = max((long long)0, farthestLeft);
    endCount[i] = i - farthestLeft + 1;
  }

  vector<int> beginCount(numElems, 1);

  for (long long i = numElems - 2; i > 0; i--) {
    size_t farthestRight = i;
    size_t next = farthestRight + 1;

    while (next < numElems && arr[next] < arr[i]) {
      next += arr[next];
      farthestRight = next - 1;
    }

    farthestRight = min(numElems - 1, farthestRight);
    beginCount[i] = farthestRight - i + 1;
  }

  // Build solution
  for (size_t i = 0; i < numElems; i++) {
    arr[i] = beginCount[i] + endCount[i] - 1;
  }

  return arr;
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

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
