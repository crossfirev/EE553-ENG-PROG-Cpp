/*
 * Author: Matthew Lepis
 * Date:   12/12/2025
 *
 * Description:
 *   Solves EE553 Homework 9: “Buildings with Ocean View.” Given a 0-indexed
 *   array of building heights with the ocean to the right, the program
 *   identifies which buildings have an ocean view—i.e., buildings that are
 *   strictly taller than every building to their right.
 *
 *   The core solution is implemented in `findBuildingsWithOceanView()`,
 *   which performs a single right-to-left scan while tracking the maximum
 *   height seen so far on the right. When a building’s height is strictly
 *   greater than this running maximum, its index is recorded as having an
 *   ocean view. Indices are collected in reverse order and then reversed to
 *   satisfy the requirement of increasing index order in the output.
 *
 *   Features:
 *     • O(n) time complexity using a single pass from right to left.
 *     • O(k) additional space for result indices (k = number of visible buildings).
 *     • Correct handling of duplicate heights:
 *         – Equal height to the right blocks the view (strict “>” requirement).
 *     • Defensive guard for empty input (even though constraints specify n >= 1).
 *     • Test harness in main() executes multiple representative cases and
 *       prints formatted input/output pairs for validation.
 *
 *   Algorithm Overview:
 *     • Initialize maxRight to the smallest possible value.
 *     • Iterate i from n-1 down to 0:
 *         – If heights[i] > maxRight, then i has an ocean view:
 *             ▪ append i to result
 *             ▪ update maxRight = heights[i]
 *     • Reverse result to return indices in increasing order.
 *
 *   The main() function:
 *     • Defines several test vectors, including:
 *         – Provided examples
 *         – Single-element input
 *         – Strictly increasing/decreasing sequences
 *         – Repeated-height cases (to validate strictness)
 *     • Calls `findBuildingsWithOceanView()` for each test and prints results.
 *
 *   Notes / Assumptions:
 *     • Indices are 0-based, matching the assignment specification.
 *     • Heights are treated as integers, but maxRight is stored as long long
 *       as an extra-safety measure (heights[i] <= 1e9 still fits in int).
 *     • Output ordering is strictly increasing as required.
 *
 *   References:
 *     • EE553 Homework 9: Buildings with Ocean View prompt.
 *     • C++ STL usage: std::vector, std::reverse, std::numeric_limits.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> findBuildingsWithOceanView(const vector<int>& heights) {
    vector<int> result;
    const int n = static_cast<int>(heights.size());

    // Edge case: empty input isn't expected per constraints (n >= 1),
    // but it's harmless to guard anyway.
    if (n == 0) return result;

    // Track the tallest building seen so far while scanning from right to left.
    // Use long long to be extra safe, though heights[i] <= 1e9 fits in int.
    long long maxRight = numeric_limits<long long>::min();

    // Scan from rightmost building to leftmost
    for (int i = n - 1; i >= 0; --i) {
        // STRICTLY greater is required; equal height to the right blocks the view.
        if (static_cast<long long>(heights[i]) > maxRight) {
            result.push_back(i);
            maxRight = heights[i];
        }
    }

    // We collected indices in reverse order (right-to-left). Reverse to increasing order.
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    vector<vector<int>> tests = {
        {4, 2, 3, 1},   // expected: 0 2 3
        {4, 3, 2, 1},   // expected: 0 1 2 3
        {1},            // expected: 0
        {2, 2, 2},      // expected: 2 (equal heights block left ones)
        {1, 3, 2, 4},   // expected: 3 (4 blocks everyone left)
        {5, 4, 4, 3, 2},// expected: 0 2 3 4? careful: index 0 sees right max is 4 => 5>4 yes,
        {1, 2, 3, 4, 5}
                        // index 1 has 4, right has 4 equal => blocked, index 2 has 4, right max 3 => yes,
                        // index 3 has 3, right max 2 => yes, index 4 yes => [0,2,3,4]
    };

    for (const auto& heights : tests) {
        cout << "heights = [";
        for (size_t i = 0; i < heights.size(); ++i) {
            if (i) cout << ", ";
            cout << heights[i];
        }
        cout << "]\n";

        vector<int> ans = findBuildingsWithOceanView(heights);
        cout << "ocean view indices = [";
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ", ";
            cout << ans[i];
        }
        cout << "]\n\n";
    }

    return 0;
}