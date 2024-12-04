#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int comparisons = 0; // To count the number of comparisons
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++; // Increment comparisons for each comparison made
        }
        comparisons++; // Increment for the last comparison when while condition fails
        arr[j + 1] = key;
    }
    cout << "Number of comparisons: " << comparisons << endl; // Output the number of comparisons
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
