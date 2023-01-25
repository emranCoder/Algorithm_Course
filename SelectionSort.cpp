#include<bits/stdc++.h>

using namespace std;


int selectionSort(int arr[], int n)
{
    int mn;

    for(int i =0; i<n-1; i++)
    {
        mn = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] <arr[mn])
            {
                mn=j;
            }
        }
        swap(arr[i],arr[mn]);
    }
}



int main()
{
    int n;
    cout << "Enter The Array Size: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr,n);

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}
