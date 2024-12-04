#include <iostream>
#include <utility> // For std::pair

std::pair<int, int> findMinMax(int arr[], int left, int right) {
    // If there's only one element
    if (left == right) {
        return {arr[left], arr[left]}; // Return both min and max as the same element
    }

    // If there are two elements
    if (right == left + 1) {
        return (arr[left] < arr[right]) ? std::make_pair(arr[left], arr[right]) : std::make_pair(arr[right], arr[left]);
    }

    // More than two elements, divide the array
    int mid = left + (right - left) / 2;
    auto leftPair = findMinMax(arr, left, mid);
    auto rightPair = findMinMax(arr, mid + 1, right);

    // Combine results
    int minValue = std::min(leftPair.first, rightPair.first);
    int maxValue = std::max(leftPair.second, rightPair.second);
    
    return {minValue, maxValue};
}

int main() {
    int arr[] = {3, 5, 1, 8, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    auto result = findMinMax(arr, 0, n - 1);
    std::cout << "Minimum: " << result.first << ", Maximum: " << result.second << std::endl;

    return 0; // Return success
}
