#include <bits/stdc++.h>
using namespace std;

//structure for holding values
typedef struct Job
{
    int jobNum;
    int deadline;
    int profit;
}Job;

bool compare(Job a, Job b);
void jobSequencing(Job input[], int num);

int main()
{
    int num;
    cout<<"Enter the total number of jobs: ";
    cin >> num;
    Job input[num];
    
    cout<<"\nEnter the JobID, Deadlines and Profit: "<<endl;
    for (int i = 0; i < num; i++)
    {
        cin >> input[i].jobNum;
        cin >> input[i].deadline;
        cin >> input[i].profit;
    }

    jobSequencing(input, num);
}

//comparison function for arrenging jobs in decreasing order of profit
bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

// job sequencing algorithm
void jobSequencing(Job input[], int num)
{
    sort(input, input + num, compare);

    int result[num];
    
    bool slot[num];
    
    int maxprofit;

    memset(slot, 0, sizeof(slot));

    for (int i = 0; i < num; i++)
    {
        for (int j = min(num, input[i].deadline)-1; j >= 0; j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    //required jobs
    cout << "\nJob sequenced in order: ";
    for (int i=0; i<num; i++)
    {
       if (slot[i] == true)
        cout << input[result[i]].jobNum << " ";
    }
    
    //required max profit
    maxprofit=0;
    cout<<"\nMaximum Profit: ";
    for(int i=0; i<num; i++)
    {
		if (slot[i] == true)
		    maxprofit = maxprofit + input[result[i]].profit;
		
	}
	cout<<maxprofit;
}
