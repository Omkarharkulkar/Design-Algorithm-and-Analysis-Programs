//coin changing problem by greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of coins needed to make change
vector<int> coinChangeGreedy(vector<int>& coins, int amount) 
{
    vector<int> result;
    sort(coins.begin(), coins.end(), greater<int>()); // sort coins in descending order

    for (int i = 0; i < coins.size(); i++) 
	{
        while (amount >= coins[i]) 
		{
            amount -= coins[i];
            result.push_back(coins[i]);
        }
    }

    return result;
}

int main() 
{
    int n, amount;
    cout << "Enter the number of coins: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "\nEnter the values of coins: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> coins[i];
    }

    cout << "\nEnter the amount to make change for: ";
    cin >> amount;

    vector<int> result = coinChangeGreedy(coins, amount);

    if (result.size() == 0) 
	{
        cout << "No solution exists";
    } 
	else 
	{
        cout << "\nMinimum number of coins needed: " << result.size() << endl;
        cout << "\nCoins used: ";
        for (int i = 0; i < result.size(); i++) 
		{
            cout << result[i] << " ";
        }
    }
    
    return 0;
}

