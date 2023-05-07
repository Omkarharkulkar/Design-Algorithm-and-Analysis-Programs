//quicksort using median of median algorithm

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to partition the array using the pivot
int partition(vector<int>& arr, int pivot, int left, int right) 
{
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[right]); // Move the pivot to the end
    int storeIndex = left;
    for (int i = left; i < right; i++) 
	{
        if (arr[i] < pivotValue) 
		{
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[right], arr[storeIndex]); // Move the pivot to its final place
    return storeIndex;
}

// Function to find the median of an array using the Median of Medians algorithm
int medianOfMedians(vector<int>& arr, int left, int right) 
{
    if (right - left < 5) 
	{
        sort(arr.begin() + left, arr.begin() + right + 1);
        return (left + right) / 2;
    }
    // Divide the array into groups of size 5
    int numGroups = (right - left + 1) / 5;
    for (int i = 0; i < numGroups; i++) 
	{
        int groupLeft = left + i * 5;
        int groupRight = min(groupLeft + 4, right);
        int medianIndex = medianOfMedians(arr, groupLeft, groupRight);
        swap(arr[left + i], arr[medianIndex]); // Move the medians to the beginning of the array
    }
    // Recursively find the median of the medians
    return medianOfMedians(arr, left, left + numGroups - 1);
}

// Function to perform the QuickSort algorithm using the Median of Medians algorithm to select the pivot
void quickSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
	{
        int pivotIndex = medianOfMedians(arr, left, right); // Choose the pivot using the Median of Medians algorithm
        pivotIndex = partition(arr, pivotIndex, left, right); // Partition the array using the pivot
        quickSort(arr, left, pivotIndex - 1); // Recursively sort the left subarray
        quickSort(arr, pivotIndex + 1, right); // Recursively sort the right subarray
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter the elements: "<<endl;
    
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
	{
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

