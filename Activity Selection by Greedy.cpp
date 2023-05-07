//Activity Selection by Greedy Approach

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>i,pair<int,int>j)
{
    return i.second<j.second;
}

int main() 
{
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
      
	map<pair<int,int>,int>m;
    vector<pair<int,int> >vec(n);
    
	cout<<"\nEnter the starting time of activity:"<<endl;
    //store starting time
    for(int i=0;i<n;i++)
	{
        cin>>vec[i].first;
    }
      
	cout<<"\nEnter the finishing time of activity:"<<endl;
    //store finishing time
    for(int i=0;i<n;i++)
	{
        cin>>vec[i].second;
    }
    
	for(int i=0;i<n;i++)
	{
        m[vec[i]]=i;
    }
    
	//sorting
    sort(vec.begin(),vec.end(),comp);
      
	//store the activity
    vector<int>v;
    vector<int>::iterator i;
    v.push_back(m[vec[0]]);
    pair<int,int>current=vec[0];
      
	for(int j=1;j<n;j++)
	{
        if(vec[j].first>current.second)
		{
            v.push_back(m[vec[j]]);
            current=vec[j];
        }
    }
      
	cout<<"\nOrder in which the activity take place"<<endl;
      
	for(i=v.begin();i!=v.end();i++)
	{
        cout<<*i+1<<" ";
    }
    
	cout<<endl;
    
	return 0;
}
