#include<bits/stdc++.h>

using namespace std;

struct Item
{
    string name;
    int price, weight;
};



int main()
{
    int n;
    cout << "Enter The Item Number: ";
    cin >> n;

    Item arr[n];


    for(int i =0; i<n; i++)
    {
        cin >> arr[i].name >> arr[i].price >> arr[i].weight;
    }
    int capacity;
    cout << "Enter The Knapsack Capacity: ";
    cin >> capacity;

    int r = n;
    int c = capacity;

    int tabler[r+1][c+1];

    for(int i =0; i<=r; i++)
    {
        tabler[i][0]=0;
    }
    for(int i =0; i<=c; i++)
    {
        tabler[0][i]=0;
    }
    for(int i =1; i<=r; i++)
    {
        for(int j = 1; j<=c; j++)
        {
            int w = arr[i-1].weight;
            int p = arr[i-1].price;
            if(w<=j)
            {
                tabler[i][j] = max( tabler[i-1][j], tabler[i-1][j-w]+p );
            }
            else
            {
                tabler[i][j] = tabler[i-1][j];
            }


        }
    }

    cout << "0/1 Knapsack: " << tabler[r][c] << endl;
    cout << "Selected Items: ";

    int i = n;
    int j = capacity;

    while(i>0 && j>0)
    {
        if(tabler[i][j]==tabler[i-1][j])
        {

            i--;
        }
        else
        {
            cout << arr[i-1].name << " ";
            i--;
            j-=arr[i].weight;

        }
    }
    cout << endl;

    return 0;
}

/*
Input Value:
n = 4
capacity = 7
P w
---
1 1 1
2 4 3
3 5 4
4 7 5
knapsack = 9;
Items = 3,2;

*/
