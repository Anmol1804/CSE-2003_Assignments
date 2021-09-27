#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
	if (start <= end) {
		int mid = start + (end - start)/2;

		if (arr[mid] == target)
			return mid;

		else if (arr[mid] > target)
			return binarySearch(arr, start, mid - 1, target);
		
		else
			return binarySearch(arr, mid + 1, end, target);
	}
	
	// if element not present
	return -1;
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
	
	int target;
	cout<<"Enter Target element : ";
	cin>>target;
	
	int start = 0;
	int end = n-1;
	int result = binarySearch(arr, start, end, target);
	
	
	if(result == -1)
	{
		cout << " \n Element(" << target << ") "<< "is not present in array" <<endl;
	}
	else
	{
		cout << " \n Element(" << target << ") "<< "is present at index : " << result <<endl;
	}
		
	return 0;
}


