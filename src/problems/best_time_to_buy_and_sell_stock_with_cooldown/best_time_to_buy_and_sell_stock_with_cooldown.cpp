#include <cassert>
#include <vector>

using std::vector;

class Solution
{
public:
    int maxProfitOne(const vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // If there's only 1 day, you can't make a profit
        if (n == 1) return 0;

        // Hold, sold, and cooldown states for each day
        int hold = -prices[0];
        int sold = 0;
        int cooldown = 0;

        for (int i = 1; i < n; i++) {
            // Previous states needed for today's calculations
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_cooldown = cooldown;

            // Update states for today
            hold = std::max(prev_hold, prev_cooldown - prices[i]);
            sold = std::max(prev_sold, prev_hold + prices[i]);
            cooldown = prev_sold;
        }

        // We return sold because we end up with more profit by selling than holding
        return sold;
    }

    using CurrencyAmount = int;

    /**
     * Maximum possible profit by either buying, selling, or waiting one tim
     * each day according to the stock `prices`.
     *
     * ## Assumptions
     *
     * - Compiler has tail-call optimization turned ON
     */
    CurrencyAmount maxProfit(const vector<CurrencyAmount>& prices)
    {
        return doMaxProfit(prices, 0, Action::wait, false, 0);
    }

private:
    enum class Action
    {
        wait,
        buy,
        sell
    };

    CurrencyAmount doMaxProfit(
            const vector<CurrencyAmount>& prices,
            CurrencyAmount profit,
            Action last,
            bool holdingStock,
            size_t day)
    {
        if (day >= prices.size()) {
            return profit;
        }

        const auto possibleActions = possibilities(last, holdingStock);
        assert(possibleActions.size() > 0);

        CurrencyAmount maxProfitFromPossibleActions = 0;

        for (const auto action: possibleActions) {
            CurrencyAmount profitAfterAction = 0;
            bool holdingStockAfterAction = false;

            switch (action) {
                case Action::buy:
                    profitAfterAction = profit - prices.at(day);
                    holdingStockAfterAction = true;
                    break;
                case Action::sell:
                    profitAfterAction = profit + prices.at(day);
                    holdingStockAfterAction = false;
                    break;
                case Action::wait:
                    profitAfterAction = profit;
                    holdingStockAfterAction = holdingStock;
                    break;
            }

            const auto result = doMaxProfit(
                    prices,
                    profitAfterAction,
                    action,
                    holdingStockAfterAction,
                    day + 1);

            maxProfitFromPossibleActions = std::max(maxProfitFromPossibleActions, result);
        }

        return maxProfitFromPossibleActions;
    }

    vector<Action> possibilities(Action last, bool holdingStock)
    {
        if (last == Action::wait && !holdingStock) { return { Action::wait, Action::buy }; }
        else if (last == Action::wait && holdingStock) { return { Action::wait, Action::sell }; }
        else if (last == Action::buy && holdingStock) { return { Action::wait, Action::sell }; }
        else if (last == Action::sell && !holdingStock) { return { Action::wait }; } // Mandatory cooldown

        else if (last == Action::buy && !holdingStock) { assert(false); } // Impossible
        else if (last == Action::sell && holdingStock) { assert(false); } // Impossible

        assert(false); // Not exhaustive
        return {};
    }
};

///// Test cases /////
#include <chrono>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void printInteger(int n) {
    cout << "[" << n << "]";
}

int test_case_number = 1;

void assert_equal(Solution::CurrencyAmount actual, Solution::CurrencyAmount expected) {
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";

    if (actual == expected) {
        cout << rightTick << " Test #" << test_case_number << " (PASSED - answer was " << expected << ")\n";
    } else {
        cout << wrongTick << " Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(actual);
        cout << endl;
    }

    test_case_number++;
}

int main()
{
    using std::vector;
    using std::pair;
    using std::make_pair;

    using CurrencyAmount = Solution::CurrencyAmount;

    vector<pair<vector<CurrencyAmount>, CurrencyAmount>> test_data = {
            // LeetCode test cases
            make_pair<vector<CurrencyAmount>, CurrencyAmount>({1, 2, 3, 0, 2}, 3),
            make_pair<vector<CurrencyAmount>, CurrencyAmount>({1}, 0),
            // Long-running hidden test case:
            make_pair<vector<CurrencyAmount>, CurrencyAmount>({48, 12, 60, 93, 97, 42, 25, 64, 17, 56, 85, 93, 9, 48, 52, 42, 58, 85, 81, 84, 69, 36, 1, 54, 23, 15, 72, 15, 11, 94}, 428),

            // Whiteboard test cases
            make_pair<vector<CurrencyAmount>, CurrencyAmount>({5, 3, 4, 2, 0, 8, 4, 1}, 9),

            // Additional test cases
            make_pair<vector<CurrencyAmount>, CurrencyAmount>({}, 0),
    };

    Solution impl;

    using clock = std::chrono::steady_clock;
    using std::chrono::duration_cast;

    for (const auto & test_case : test_data) {
        const auto& stockPrices = test_case.first;
        const auto expected_output = test_case.second;

        const auto start = clock::now();
        //const int actual_output = impl.maxProfit(stockPrices);
        const int actual_output = impl.maxProfitOne(stockPrices);
        const auto end = clock::now();

        assert_equal(actual_output, expected_output);

        std::cout << "  Time elapsed: "
                  << duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns"
                  << " (approx. "
                  << duration_cast<std::chrono::microseconds>(end - start).count() << "us"
                  << " / "
                  << duration_cast<std::chrono::milliseconds>(end - start).count() << "ms"
                  << " / "
                  << duration_cast<std::chrono::seconds>(end - start).count() << "s"
                  << ")" << std::endl;
    }
}
