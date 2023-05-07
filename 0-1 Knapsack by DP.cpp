#include <iostream>
#define MAX 200
using namespace std;

//weights
int weight[] = {0, 1, 2, 1, 3};
//values
int value[] =  {0, 10, 7, 11, 15};
//knapsack bag weight limit
int knapsack_weight = 5;
//count of items
int n = 4;

class KnapsackDP
{
public:
  int **memoTable;

  KnapsackDP()
  {
    this->memoTable = new int*[n+1]; 
    
    for(int i=0; i<n+1; i++)
	{
        this->memoTable[i]= new int[knapsack_weight+1] {0};
    }
  }

  int solve()
  {
    //Compute and fill the memo table
    for(int i=1; i< (n + 1); i++)
	{
      for(int j=1; j<(knapsack_weight + 1); j++)
	  {

        int not_taking_item = memoTable[i-1][j];

        int taking_item = 0;
        if(weight[i] <= knapsack_weight)
		{
          if(j-weight[i] < 0)
              taking_item = memoTable[i-1][j];
          else
              taking_item = value[i] + memoTable[i-1][j-weight[i]];
        }

        memoTable[i][j] = max(not_taking_item, taking_item);
      }
    }
    return memoTable[n][knapsack_weight];
  }

  void selected_items()
  {
    for(int i=n, j= knapsack_weight; i>0; i--)
	{
      if(memoTable[i][j] != memoTable[i-1][j])
	  {
        cout << "Item: "<<i <<" Selected \n";
        j = j- weight[i];
      }
    }
  }
};
 
int main()
{
    KnapsackDP kdp;
    cout << "Total Benefit: "<< kdp.solve() <<endl;

    //To print which items are included
    kdp.selected_items();
    return 0;
}
