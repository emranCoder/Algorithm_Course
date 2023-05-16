#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,amount;
    cout << "Enter The number Of coins: ";
    cin >> n;
    cout << "Enter The Amount: ";
    cin >> amount;

    cout << "Enter the coins: ";

    int arr[n];
    for(int i = 0; i<n ; i++)
    {
        cin >> arr[i];
    }

    int tabler_method[n+1][amount+1];
    //char tracker[n+1][m+1];

    for(int i =0; i<=n; i++)
    {
        tabler_method[i][0]=0;
    }
    tabler_method[0][0]=0;
    for(int i =1; i<=amount; i++)
    {
        tabler_method[0][i]=amount+1;
    }

    for(int i =1; i<=n; i++)
    {
        int v = arr[i-1];
        for(int j = 1; j<=amount; j++)
        {
            if(arr[i-1] <= j)
            {


                tabler_method[i][j] = min( tabler_method[i-1][j], tabler_method[i][j-v]+1);
            }else
            {
                 tabler_method[i][j] =  tabler_method[i-1][j];
            }
        }
    }

    for(int i =0; i<=n; i++)
    {
        for(int j = 0; j<=amount; j++)
        {
            cout << tabler_method[i][j] << " ";
        }
        cout << endl;
    }


    cout << "The minimum Number of Coins: " << tabler_method[n][amount] << endl;
    
    int i = n;
    int j = amount;

    while( i>0 && j>0 )
    {
        if(tabler_method[i][j]!=tabler_method[i-1][j])
        {
            cout << arr[i-1] << " ";
            j-=arr[i-1];
        }else
        {
            i--;
        }
    }
    cout << endl;




    return 0;
}

/*
Input Value:
Coins: 1 5 6 9
Amount: 10
Answer: 22
*/
