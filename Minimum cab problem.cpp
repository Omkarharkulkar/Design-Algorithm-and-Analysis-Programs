//minimum cab problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval 
{
    float start;
    float end;
};

bool cmp(Interval a, Interval b) 
{
    return a.start < b.start;
}

int main() 
{
    int n;
    cout<<"Enter the number of persons: ";
    cin >> n;
    
    cout<<"\nEnter the start time and end time: "<<endl;
    vector<Interval> intervals(n);
    for (float i = 0; i < n; i++) 
	{
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), cmp);

    float count = 1;
    float end_time = intervals[0].end;
    for (float i = 1; i < n; i++) 
	{
        if (intervals[i].start > end_time) 
		{
            count++;
            end_time = intervals[i].end;
        }
        else 
		{
            end_time = max(end_time, intervals[i].end);
        }
    }

    cout <<"\nTotal cab requireds are: " << count << endl;

    return 0;
}

