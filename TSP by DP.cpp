//TSP by DP

#include <iostream>
#include <algorithm>

using namespace std;

int cost[20][20];

int tsp(int path[], int start, int n) 
{
    int i, j, k, ccost;
    int mintour[n+1];
    int temp[n+1];
    
    if(start == n-1)
    {
    	return cost[path[n-1]][path[n]] + cost[path[n]][1];
	}
	
    int mincost = 999;
    
    for(i = start+1; i <= n; i++) 
	{
        for(j = 1; j <= n; j++)
        {
        	temp[j] = path[j];
		}
		
        temp[start+1] = path[i];
        temp[i] = path[start+1];
        
        if(cost[path[start]][path[i]] + (ccost = tsp(temp, start+1, n)) < mincost) 
		{
            mincost = cost[path[start]][path[i]] + ccost;
            for(k = 1; k <= n; k++)
            {
            	mintour[k] = temp[k];
			} 
        }
    }
    
    for(i = 1; i <= n; i++)
    {
    	path[i] = mintour[i];
	}
	
    return mincost;
}

int main() 
{
    int mincost, n, i, j;
    
    cout << "enter the no of cities" << endl;
    cin >> n;
    
    int path[n+1];
    
    cout << "Enter the cost matrix" << endl;
    
    for(i = 1; i <= n; i++)
    {
    	for(j = 1; j <= n; j++)
    	{
    		cin >> cost[i][j];
		}
	}
            
    for(i = 1; i <= n; i++)
    {
    	path[i] = i;
	}
	
    mincost = tsp(path, 1, n);
    
    cout << "\nTSP Tour:" << endl;
    
    for(i = 1; i <= n; i++)
    {
    	cout << path[i] << "--->";
	}
        
    cout << "1" << endl;
    
    cout << "\nCost of Tour = " << mincost << endl;
    return 0;
}

