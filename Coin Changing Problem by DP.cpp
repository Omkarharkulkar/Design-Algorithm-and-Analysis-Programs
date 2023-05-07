#include<bits/stdc++.h>
using namespace std;

int coinchange(int coins[],int amount)
{
	int x = sizeof(coins);
	int y = amount;
	
	int arr[x+1][y+1];
	
	
	for(int i=0; i<=x; i++)
	{
		for(int j=0; j<=y; j++)
		{
			if(j==0)
			{
				arr[i][j] = 0;
			}
			else if(i==0)
			{
				arr[i][j] = j;
			}
			else if(coins[i-1] > j)
			{
				arr[i][j] = arr[i-1][j];
			}
			else
			{
				arr[i][j] = min(arr[i-1][j], 1+arr[i][j-coins[i-1]]);
			}
		}
	}
	
	return arr[x][y];
}

int main()
{
	int amount,d;
	cout<<"Enter the weight/value : ";
	cin>>amount;
	cout<<"Enter the number of denominations : ";
	cin>>d;
	int coins[d];
	cout<<"Enter the denominations : ";
	for(int i=0; i<d; i++)
	{
		cin>>coins[i];
	}
		
	int val = coinchange(coins,amount);
	cout<<"Total number of coins required are : "<<val;
	
	sort(coins, coins+d, greater<int>());
	
	vector<int> sol;
	
	for(int i=0; i<val; i++)
	{
		if(val > coins[i])
		{
			if(val%coins[i] == 0)
			{
				int a = val/coins[i];
				for(int j=0; j<a; j++)
				{
					sol.push_back(coins[i]);
				}
			}
		}
		if(val < coins[i])
		{
			continue;
		}
		
		if(val == coins[i])
		{
			sol.push_back(coins[i]);
		}
	}
	
	cout<<"\nCoins are :"<<endl;
	for(int i=0; i<sizeof(sol); i++)
	{
		cout<<sol[i];
	}
	
	return 0;
}
