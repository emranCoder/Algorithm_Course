#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout <<  "Enter The number of Coins: ";
    cin >> n;

    int amount;
    cout << "Enter The Amount: ";
    cin >> amount;

    int arr[n];

    cout << "Enter The Coins: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int tabler_method[n][amount+1];

    for(int i =0; i<n; i++)
    {
        for(int j=0; j<=amount; j++)
        {
            if(j==0)
            {
                tabler_method[i][0] = 1;
            }
            else
            {
                int v = arr[i];
                if(i==0)
                {
                    if( j%v==0 )
                    {
                        tabler_method[i][j]=1;
                    }
                    else
                    {
                        tabler_method[i][j]=0;
                    }
                }else
                {
                    if(v<=j)
                    {
                        tabler_method[i][j] = tabler_method[i-1][j]+tabler_method[i][j-v];
                    }else
                    {
                        tabler_method[i][j] = tabler_method[i-1][j];
                    }
                }

            }


        }
    }

    for(int i =0; i<n; i++)
    {
        for(int j=0; j<=amount; j++)
        {
            cout << tabler_method[i][j] << " ";
        }
        cout << endl;
    }


    cout << "The minimum Number of Ways: " << tabler_method[n-1][amount] << endl;





    return 0;
}

