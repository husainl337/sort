#include <iostream>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If target is smaller than mid, search in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // If target is larger than mid, search in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0; // Return success
}