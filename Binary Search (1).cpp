
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#define SIZE 20000

using namespace std;
using namespace std ::chrono;

void Linear(vector<int> a, long long key)
{
    auto start2 = high_resolution_clock::now();
    int flag = 0;
    for (long long i = 0; i < SIZE; i++)
    {
        if (a[i] == key)
        {
            cout << "\n 	Element Found at Location:\t" << (i + 1) << endl;
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\n	Element Not Found" << endl;
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "	Time taken By Linear Search: " << duration2.count() << " nanoseconds" << endl;
}


void Binary(vector<int> a, long long key)
{
    // Get starting timepoint
    auto start1 = high_resolution_clock::now();
    // Call the function, here sort()
    long long mid = 0;
    long long first = 0;
    long long last = SIZE;
    mid = (first + last) / 2;
    while ((a[mid] != key) && (first < last))
    {
        if (a[mid] > key)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
    if (a[mid] == key)
    {
        cout << " 	Element found at location:\t" << mid<<endl;
    }
    else
    {
        cout << "	Element Not Found\n";
    }
    // Get ending timepoint
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "	Time taken By Binary Search: " << duration1.count() << " nanoseconds" << endl;
}

void Binary_random(vector<int> a, long long key)
{
    // Get starting timepoint
    auto start1 = high_resolution_clock::now();
    // Call the function, here sort()
    long long mid = 0;
    long long first = 0;
    long long last = SIZE;
    mid = rand()%SIZE;
    while ((a[mid] != key) && (first < last))
    {
        if (a[mid] > key)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
    if (a[mid] == key)
    {
        cout << " 	Element found at location:\t" << mid + 1<<endl;
    }
    else
    {
        cout << "	Element Not Found\n";
    }
    // Get ending timepoint
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "	Time taken By Binary Search: " << duration1.count() << " nanoseconds" << endl;
}


int main()
{
    int ch = 1;
    long long key, index;
    vector < int > values(SIZE);
    auto f = []() -> int {return rand() % SIZE;};
    generate(values.begin(), values.end(), f);
    sort(values.begin(), values.end());

    cout << "Dataset:\n";
    for (long long i = 0; i < SIZE; i++)
        cout << values[i] << "\t";
    while (ch != 0) {
        cout << "\n";
        cout << "\n Enter the element to search: ";
        cin >> key;
        
        cout << "\n 1. Linear search-";
        Linear(values, key);

        cout << "\n 2. Binary recursive search\n";
        Binary(values, key);

        cout << "\n 3. Binary recursive search with random middle element\n";
        Binary_random(values, key);
  
        cout << "\n Press 1 to continue(enter 0 to exit): ";
        cin >> ch;
    }
    return 0;
}
