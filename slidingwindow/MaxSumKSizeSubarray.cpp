#include <cassert>
#include <vector>

namespace slidingwindow {

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
}

int main() {
    return 0;
}