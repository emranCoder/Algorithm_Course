#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    int LCS_table[n+1][m+1];
    char tracker[n+1][m+1];

    for(int i =0; i<=n; i++)
    {
        LCS_table[i][0]=0;
    }
    for(int i =0; i<=m; i++)
    {
        LCS_table[0][i]=0;
    }

    for(int i =1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                LCS_table[i][j] = LCS_table[i-1][j-1]+1;
                tracker[i][j] = 'D';
            }
            else if( LCS_table[i-1][j] >=  LCS_table[i][j-1])
            {
                LCS_table[i][j] =  LCS_table[i-1][j] ;
                tracker[i][j] = 'U';
            }
            else
            {
                LCS_table[i][j] =  LCS_table[i][j-1];
                tracker[i][j] = 'L';
            }
        }
    }


    cout << "Longest Common Subsequence: " << LCS_table[n][m] << endl;

    string ans;
    int i = n;
    int j = m;

    while(i>0 && j>0)
    {
        if(tracker[i][j]=='U')
        {
            i--;
        }
        else if(tracker[i][j]=='L')
        {
            j--;
        }
        else
        {
            ans+=s1[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;


    return 0;
}

/*
Input Value:
TCAGGTAT
ACTAGCTA
LCS = 5;
Subsequence: TAGTA
*/
