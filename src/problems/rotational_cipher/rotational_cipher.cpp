#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
char rotate(char c, int rotationFactor, char min, char max) {
  rotationFactor = rotationFactor % (max - min + 1);

  unsigned char rotated = c;
  rotated += rotationFactor;

  if (rotated < min) {
    rotated += max - min + 1;
  } else if (rotated > max) {
    rotated -= max - min + 1;
  }

  return rotated;
}

string rotationalCipher(string input, int rotationFactor) {
  for (char &c : input) {
    if (c >= 'a' && c <= 'z') {
      c = rotate(c, rotationFactor, 'a', 'z');
    } else if (c >= 'A' && c <= 'Z') {
      c = rotate(c, rotationFactor, 'A', 'Z');
    } else if (c >= '0' && c <= '9') {
      c = rotate(c, rotationFactor, '0', '9');
    }
  }

  return input;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected);
    cout << " Your output: ";
    printString(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
