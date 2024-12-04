#include <algorithm>
#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    std::vector<int> count(maxVal + 1, 0);
    std::vector<int> output(arr.size());

    // Count occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Update count[i] to be the position of this element in output
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    arr = output;
}

int main() {
    // Predefined input
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
