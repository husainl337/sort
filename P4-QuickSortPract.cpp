#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int &comparisons) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        comparisons++; // Count comparison
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons); // Partitioning index

        quickSort(arr, low, pi - 1, comparisons); // Before pi
        quickSort(arr, pi + 1, high, comparisons); // After pi
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    quickSort(arr, 0, arr_size - 1, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
