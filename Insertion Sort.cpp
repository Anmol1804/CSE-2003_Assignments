#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, ele, j;
    for (i = 1; i < n; i++)
    {
        ele = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > ele)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = ele;
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
	
	cout << "\nSorted array Using Insertion Sort (Time Complexity O(n*n)): " <<endl;
	insertionSort(arr, n);
	
	return 0;
}

