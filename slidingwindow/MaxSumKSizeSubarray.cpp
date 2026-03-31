/**
 * @brief Calculation of the maximum Sum of a k-sized subarray
 *
 * @details
 * This algorithm uses the sliding window technique to efficiently compute the
 * maximum sum of a subarray of size k. Through reusing the results from previous
 * calculations it reduces the time complexity from O(n*k) to O(n). This is
 * especially more efficient when dealing with large input arrays.
 *
 * In case of a subarray size that is smaller than the arrays size, the algorithm
 * terminates instantly.
 *
 * Time Complexity:
 * Worst-case O(n)
 * Average-case O(n)
 * Best-case O(n)
 */

#include <cassert>
#include <vector>

/**
 * @namespace slidingwindow
 * @brief slidingwindow algorithms
 */
namespace slidingwindow {

/**
 * Calculates the maximum sum of a subarray with size k
 *
 * @param array Array of which the maximum of its subarray should be calculated
 * @param k Size of the subarray
 * @return the calculated maximum sum of the subarray
 */
int maxSumKSizeSubarray(const std::vector<int>& array, const size_t k) {
    // terminate if the array size is smaller than the size of the subarray
    if (array.size() < k) {
        return INT_MIN;
    }

    int max_sum = 0;
    int window_sum = 0;

    // sum of the first k elements
    for (size_t i = 0; i < k; i++) {
        max_sum += array[i];
    }

    window_sum = max_sum;

    // sliding the window
    for (size_t i = k; i < array.size(); i++) {
        window_sum += array[i] - array[i - k];
        if (window_sum > max_sum) max_sum = window_sum;
    }

    return max_sum;
}
}  // namespace slidingwindow

/**
 * @brief self tested implementation
 */
void test() {
    const std::vector arr_1 = {3, 4, -3, 0, 9, 3, -2, 7};
    const int sum_1 = slidingwindow::maxSumKSizeSubarray(arr_1, 3);
    const int sum_2 = slidingwindow::maxSumKSizeSubarray(arr_1, 4);
    const int sum_3 = slidingwindow::maxSumKSizeSubarray(arr_1, 5);
    const int sum_4 = slidingwindow::maxSumKSizeSubarray(arr_1, 6);

    assert(sum_1 == 12);
    assert(sum_2 == 17);
    assert(sum_3 == 17);
    assert(sum_4 == 16);

    const std::vector arr_2 = {1, -2, 5, 6, -1, 8, 2, -3};
    const int sum_5 = slidingwindow::maxSumKSizeSubarray(arr_2, 3);
    const int sum_6 = slidingwindow::maxSumKSizeSubarray(arr_2, 4);
    const int sum_7 = slidingwindow::maxSumKSizeSubarray(arr_2, 5);
    const int sum_8 = slidingwindow::maxSumKSizeSubarray(arr_2, 6);

    assert(sum_5 == 13);
    assert(sum_6 == 18);
    assert(sum_7 == 20);
    assert(sum_8 == 18);

    // Case: k > array Size
    const std::vector arr_3 = {8, 5, -1, 0};
    const int sum_9 =slidingwindow::maxSumKSizeSubarray(arr_3, 6);

    assert(sum_9 == INT_MIN);
}

/**
 * @brief Main function
 */
int main() {
    test();
    return 0;
}