
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
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
		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp; 
	}
	
	// diplaying sorted array
	for (int i=0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
}


int main()
{	
	cout<<"----- ANMOL 19BCE0891 -----"<<endl;
	
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	cout << "\nSorted array Using Selection Sort (Time Complexity O(n)): " <<endl;
	selectionSort(arr, n);
	
	return 0;
}

