#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
    	for (int j = 0; j < n-i-1; j++)
		{
    		if (arr[j] > arr[j+1])
			{
    			int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}   
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
	
	cout << "\nSorted array Using Bubble Sort (Time Complexity O(n)): " <<endl;
	bubbleSort(arr, n);
	
	return 0;
}

