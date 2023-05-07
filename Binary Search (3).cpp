#include <iostream>
#include <chrono>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // not found
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    auto start = chrono::high_resolution_clock::now(); // start the timer

    int result = binarySearch(arr, 0, n - 1, target);

    auto end = chrono::high_resolution_clock::now(); // end the timer
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration in microseconds

    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index " << result << " in the array." << endl;
    }

    cout << "Time taken by the function: " << duration.count() << " microseconds" << endl;

    return 0;
}

