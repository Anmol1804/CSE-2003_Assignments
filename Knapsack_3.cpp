
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
//	vector<vector<int>> K(n + 1, vector<int>(W + 1));
	 int K[n + 1][W + 1];
	 
	// Build table K[][] in bottom up manner
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

void selectionSort(int arr[], int arr1[], int n)
{
	
	for (int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		
		// finding index of min element
		if (arr[j] < arr[minIndex])
		{
			minIndex = j;
		}
		
		// swaping min_element with element at index i
		int temp1 = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp1; 
		
		int temp2 = arr1[minIndex];
		arr1[minIndex] = arr1[i];
		arr1[i] = temp2; 
	}	
	
}





int main()
{
	cout << "--- ANMOL 19BCE0891   --- "<<endl;
	cout<< "\n\n0/1 Knapsnack Using Dynamic Programming"<<endl;
   int num, i, j, capacity;
   cout<<("\nEnter the no. of objects:- ");
   cin>>num;
   
   int weight[num], profit[num];

   cout<<"\nEnter the wts and profits (correspondingly) of each object:- "<<endl;
   for (i = 0; i < num; i++) {
      cin>>weight[i]>>profit[i];
   }

   cout<<"\nEnter the capacity of knapsack:- ";
   cin>>capacity;
	
	// Selection Sort in increasing Profit
	cout<<"Sorting Profit Using Selection Sort :"<<endl;
	selectionSort(profit, weight, num);
	for (int i=0; i < num; i++)
	{
		cout << weight[i] << " " <<profit[i] <<endl;
	}
	
	cout <<"Maximum Profit : " << knapSack(capacity, weight,  profit, num);
	
	return 0;
}

