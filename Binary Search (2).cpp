#include <algorithm>
#include <chrono>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;
void linear_search(int l[],int num,int data){
	int flag=0;
	int i=0;
	for(i=0;i<num;i++){
		if(l[i]==data){
			flag=1;
			break;
		}
		else{
			flag=0;
		}
	}
	if(flag==1){
		cout<<"Element present at : "<<i;
	}
	else{
		cout<<"Element not present";
	}
	
}
/* Non-Recursive function*/
int nonrecursive(int l[], int f, int r, int data)
{
   while (f <= r) {
		int m = f + (r - f) / 2;

		// Check if x is present at mid
		if (l[m] == data)
			return m;

		// If x greater, ignore left half
		if (l[m] < data)
			f = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}



/* Recursive function*/
int recursive(int l[],int Start,int End,int a)
{
  int m,pos;
  if (Start<=End)
  {
    m=(Start+End)/2;
    if (l[m]==a)
      return m;
    else if (a<l[m])
      return recursive(l,Start,m-1,a);
    else
      return recursive(l,m+1,End,a);
   }
   return -1;
}


//--to take user input
void input(int l[],int n)
{
   int i;
   for(i=0;i<n;i++){
    l[i]=rand()%500;
   }
      
}

//-- to display
void display(int l[],int n)
{
    int i;
   for(i=0;i<n;i++)
       cout<<l[i]<<" ";
}

/*main function*/
main()
{
   int  num, data,f,l1,a;
   int ch,pos;

     cout<<"\nEnter the number of elements : ";
     cin>>num;
     int l[num];
     input(l,num);
     // selection_sort(l,num);
     sort(l,l+num);
     cout<<"\nElements present in the list are:\t";
     display(l,num);
     cout<<"\n\nEnter the element you want to search:\n\n";
     cin>>data;
   

   
      cout<<"\nLinear Search:\n";
   auto sl = high_resolution_clock::now();
   linear_search(l,num,data);
   auto stl = high_resolution_clock::now();
   auto durl = duration_cast<microseconds>(stl - sl);
   cout << "\nTime taken by function: "<< durl.count() << " microseconds" << endl;

 
   cout<<"\nRecursive method:\n";
        auto start = high_resolution_clock::now();
        pos=recursive(l,0,num-1,data);
        auto stop = high_resolution_clock::now();
        if(pos==-1)
        {
        cout<<"Element is not found";
        }
        else
        {
        cout<<"Element is found at position \t"<<pos;
        }
        auto duration = duration_cast<microseconds>(stop - start);
      cout << "\nTime taken by function: "<< duration.count() << " microseconds" << endl;

      
      cout<<"\nNon-Recursive method:\n";
      auto s = high_resolution_clock::now();
    //  nonrecursive(l,num,data);
      
      int result = nonrecursive(l, 0, num - 1, data);
	   (result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
      
      auto st = high_resolution_clock::now();
      auto dur = duration_cast<microseconds>(st - s);
      
      cout << "\nTime taken by function: "<< dur.count() << " microseconds" << endl;




}
