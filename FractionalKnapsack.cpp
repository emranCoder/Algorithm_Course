#include<bits/stdc++.h>

using namespace std;

struct Item
{
    string name;
    float price, weight, per_unit;
};

bool sortCmp(Item a1, Item a2)
{
    return(a1.per_unit>a2.per_unit);
}

int knapSack(Item arr[], int w, int n)
{
    sort(arr,arr+n, sortCmp);

    float total=0;

    for(int i =0; i<n; i++)
    {
        if(w>=arr[i].weight)
        {
            total += arr[i].price;
            w-=arr[i].weight;
            cout << arr[i].name << " " << arr[i].price << endl;
        }
        else
        {
            cout << arr[i].name << " " <<arr[i].per_unit * w<< endl;
            total += arr[i].per_unit * w;
            break;
        }
    }

    cout << "Total Profit: " << total << endl;

}



int main()
{
    int n;
    cout << "Enter The Item Number: ";
    cin >> n;

    Item arr[n];

    for(int i = 0; i<n; i++)
    {
        /* Price & Weight Input */
        cin >> arr[i].name >> arr[i].price >> arr[i].weight;
        /* Per Unit Price Stored */
        arr[i].per_unit = arr[i].price / arr[i].weight;
    }
    /* Knap Sack Capacity Input */
    int w;
    cout << "KnapSack Capacity: ";
    cin >> w;

    knapSack( arr,  w,  n);


    return 0;
}



/*
Input Value
3
A 60 10
B 100 20
C 120 30

*/


