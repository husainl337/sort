#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comparisons) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // Compare left child with largest
    if (left < n) {
        comparisons++; // Count comparison
        if (arr[left] > arr[largest])
            largest = left;
    }

    // Compare right child with largest
    if (right < n) {
        comparisons++; // Count comparison
        if (arr[right] > arr[largest])
            largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int &comparisons) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0, comparisons); // call max heapify on the reduced heap
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    heapSort(arr, arr_size, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
