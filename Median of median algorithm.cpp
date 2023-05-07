#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the median of a vector of integers using the Median of Medians algorithm
int findMedian(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> medians;
    for (int i = 0; i < n; i += 5) 
	{
        vector<int> group;
        for (int j = i; j < min(i + 5, n); j++) 
		{
            group.push_back(arr[j]);
        }
        sort(group.begin(), group.end());
        medians.push_back(group[group.size() / 2]);
    }
    if (medians.size() == 1) 
	{
        return medians[0];
    } 
	else 
	{
        return findMedian(medians);
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
    int median = findMedian(arr);
    cout << "Median: " << median << endl;
    return 0;
}

