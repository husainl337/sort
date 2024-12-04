#include <iostream>
#include <vector>
#include <algorithm>

int maxCrossingSum(const std::vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = std::max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = std::max(rightSum, sum);
    }

    return std::max(leftSum + rightSum, std::max(leftSum, rightSum));
}

int maxSubArraySum(const std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left]; // Base case: only one element
    }

    int mid = left + (right - left) / 2;

    return std::max({
        maxSubArraySum(arr, left, mid), // Left subarray
        maxSubArraySum(arr, mid + 1, right), // Right subarray
        maxCrossingSum(arr, left, mid, right) // Crossing subarray
    });
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubArraySum(arr, 0, arr.size() - 1);

    std::cout << "Maximum Subarray Sum: " << maxSum << std::endl;

    return 0;
}
