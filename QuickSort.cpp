#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); // Swap if element is smaller than pivot
        }
    }
    std::swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partitioning index
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
