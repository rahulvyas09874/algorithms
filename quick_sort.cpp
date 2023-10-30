#include <iostream>
#include <vector>

/**
 * Partition the array using the last element as the pivot
 *
 * @param arr The array to be partitioned
 * @param low The index of the first element in the partition range
 * @param high The index of the last element in the partition range
 * @return The index of the pivot element after partitioning
 */
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;    // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
 * Perform the Quick Sort algorithm to sort an array in-place
 *
 * @param arr The array to be sorted.
 * @param low The index of the first element in the sorting range
 * @param high The index of the last element in the sorting range
 */
void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        //  Recursively sort the elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};

    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
