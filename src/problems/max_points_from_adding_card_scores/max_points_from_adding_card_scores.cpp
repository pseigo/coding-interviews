#include <cstddef> // size_t
#include <vector>

class Solution {
public:
    /**
     * ## Complexity
     *
     * - Time: O(2k) (optimal)
     * - Space: O(N) (optimal)
     *
     * ## Optimizations
     *
     * - `if (k >= N) { return sum(cardPoints); }`
     * - If `2*k` elements fit in CPU caches and `cardPoints.size()` (`N`) is very large, start (in another function)
     *   by copying the first and last `k` elements into a new array. This should improve performance because in this
     *   solution, we alternate reading elements from the front and back of `cardPoints`, which for sufficiently large
     *   `N`, should avoid constantly filling up the cache line only to use one element and throwing away the whole
     *   thing. Would need to benchmark to confirm this hypothesis.
     *
     * @return Maximum score by taking exactly `k` picks from front and back of `cardPoints`.
     */
    int maxScore(const std::vector<int>& cardPoints, size_t k) {
        if (k == 0) {
            return 0;
        }

        const auto N = cardPoints.size();
        if (k > N) {
            k = N;
        }

        int max = 0;

        // Start with all front picks
        for (size_t i = 0; i < k; i++) {
            max += cardPoints.at(i);
        }

        // Try other combinations of picks until true max is found
        auto sum = max;
        constexpr size_t startingOffset = 1;
        size_t i = (k - 1) + startingOffset;

        do {
            i--; // Start by decrementing to account for startingOffset

            // Remove a front pick
            sum -= cardPoints.at(i);

            // Add a back pick
            sum += cardPoints.at((N - 1) - (k - 1 - i));

            if (sum > max) {
                max = sum;
            }
        } while (i != 0);

        return max;
    }
};

///// Test cases /////
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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

    vector<pair<pair<vector<int>, size_t>, int>> test_data = {
            // LeetCode test cases
            make_pair(make_pair<vector<int>, size_t>({1, 2, 3, 4, 5, 6, 1}, 3), 12),
            make_pair(make_pair<vector<int>, size_t>({2, 2, 2}, 2), 4),
            make_pair(make_pair<vector<int>, size_t>({9, 7, 7, 9, 7, 7, 9}, 7), 55),

            // Whiteboard test cases
            make_pair(make_pair<vector<int>, size_t>({2, 5, 3, 1, 3, 6, 12, 1}, 4), 22),
            make_pair(make_pair<vector<int>, size_t>({1, 6, 2, 4, 1, 5, 3, 2, 6, 12, 52, 1000, 100000, 1, 1, 1, 1, 5}, 5), 18),

            // Additional test cases
            make_pair(make_pair<vector<int>, size_t>({1, 6, 2, 4, 1, 100000, 100000, 100000, 100000, 100000, 2, 1, 6, 1, 5}, 5), 19),
            make_pair(make_pair<vector<int>, size_t>({1, 6, 2, 4, 1, 100000, 100000, 100000, 100000, 100000, 1, 6, 1, 5}, 5), 100013),
            make_pair(make_pair<vector<int>, size_t>({100000, 100000, 100000, 100000, 100000}, 2), 200000),
            make_pair(make_pair<vector<int>, size_t>({}, 0), 0),
            make_pair(make_pair<vector<int>, size_t>({1}, 0), 0),
            make_pair(make_pair<vector<int>, size_t>({10}, 1), 10),
            make_pair(make_pair<vector<int>, size_t>({10}, 10), 10)
    };

    Solution impl;

    for (const auto & test_case : test_data) {
        const auto& cards = test_case.first.first;
        const auto k = test_case.first.second;
        const auto expected_output = test_case.second;

        const int actual_output = impl.maxScore(cards, k);

        assert_equal(actual_output, expected_output);
    }
}
