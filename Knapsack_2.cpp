# include<iostream>
using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   cout<<"\nThe result vector is:- ";
   for (i = 0; i < n; i++)
      cout<<x[i]<<"\t";

   cout<<"\nMaximum profit is:-  "<<tp;

}

void insertionSort(float ratio[], float profit[], float weight[], int n)
{
    float ele, elep, elew;
    int i,j;
    for (i = 1; i < n; i++)
    {
        ele = ratio[i];
        elep = profit[i];
        elew = weight[i];
        
        j = i - 1;
        while (j >= 0 && ele > ratio[j])
        {
            ratio[j+1] = ratio[j];
            profit[j+1] = profit[j];
            weight[j+1] = weight[j];
            j = j - 1;
        }
        ratio[j+1] = ele;
        profit[j+1] = elep;
        weight[j+1] = elew;
    }
    	
}

int main() {
	cout << "--- ANMOL 19BCE0891  --- "<<endl;
	
   int num, i, j, capacity;
   cout<<("\nEnter the no. of objects:- ");
   cin>>num;
   
   
	float ratio[num], weight[num], profit[num];
   cout<<"\nEnter the weights and profits (correspondingly) of each object:- "<<endl;
   for (i = 0; i < num; i++) {
      cin>>weight[i]>>profit[i];
   }

   cout<<"\nEnter the capacity of knapsack:- ";
   cin>>capacity;
	
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
   
   insertionSort(ratio, profit, weight, num);

	cout<<"\n Sorting in p/w ratio using insertion sort : "<<endl;
	for(int i=0; i<num; i++){
		cout<<ratio[i]<<" "<<weight[i]<<" "<<profit[i]<<endl;
		
	}

	cout<<endl;

   knapsack(num, weight, profit, capacity);
   return 0;
}
