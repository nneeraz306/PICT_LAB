#include <bits/stdc++.h>
using namespace std;

// ------------------- Deterministic Partition -------------------
int partition_deterministic(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // pivot = first element
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) i++;
        while (arr[j] > pivot && j >= 0) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// ------------------- Randomized Partition -------------------
int partition_randomized(vector<int>& arr, int low, int high) {
    int random_index = low + rand() % (high - low + 1); // pick random pivot
    swap(arr[low], arr[random_index]); // move random pivot to first
    // now same as deterministic
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) i++;
        while (arr[j] > pivot && j >= 0) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// ------------------- Deterministic Quick Sort -------------------
void quicksort_deterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_deterministic(arr, low, high);
        quicksort_deterministic(arr, low, p - 1);
        quicksort_deterministic(arr, p + 1, high);
    }
}

// ------------------- Randomized Quick Sort -------------------
void quicksort_randomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_randomized(arr, low, high);
        quicksort_randomized(arr, low, p - 1);
        quicksort_randomized(arr, p + 1, high);
    }
}

// ------------------- MAIN -------------------
int main() {
    srand(time(0)); // seed for randomness

    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    vector<int> arr2 = arr1; // copy for randomized

    cout << "Original array: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n";

    quicksort_deterministic(arr1, 0, arr1.size() - 1);
    quicksort_randomized(arr2, 0, arr2.size() - 1);

    cout << "Sorted array (Deterministic): ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    cout << "Sorted array (Randomized):   ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    return 0;
}
