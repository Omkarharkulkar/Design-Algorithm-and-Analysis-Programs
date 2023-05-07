//0/1 knapsack by DP

#include<iostream>

using namespace std;

#define MAX 50

int p[MAX],w[MAX],n;
int knapsack(int,int);
int max(int,int);

int main()
{
    int m,i,optsoln;
    cout<<"Enter no. of objects: ";
    cin>>n;
    
    cout<<"\nEnter the weights:\n";
    for(i=1; i<=n; i++)
    {
    	cin>>w[i];
	}
        
    cout<<"\nEnter the profits:\n";
    for(i=1; i<=n; i++)
    {
    	cin>>p[i];
	}
        
    cout<<"\nEnter the knapsack capacity: ";
    cin>>m;
    
    optsoln=knapsack(1,m);
    cout<<"\nThe optimal soluntion is: "<<optsoln;
}

int knapsack(int i, int m)
{
    if(i==n)
        return (w[n]>m) ? 0: p[n];
    if(w[i]>m)
        return knapsack(i+1, m);
    return max(knapsack(i+1, m), knapsack(i+1, m-w[i])+p[i]);
}

int max(int a, int b)
{
    if(a>b)
    {
    	return a;
	}
    else
    {
    	return b;
	}
}
