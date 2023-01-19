#include<bits/stdc++.h>

using namespace std;

struct acitivity
{
    char c;
    int start_time, second_time;
};


bool aSort(acitivity a1, acitivity a2)
{
    return (a1.second_time < a2.second_time);
}


int main()
{
    int n;
    cout << "Enter Activity Number: ";
    cin >> n;
    acitivity aArr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> aArr[i].c >> aArr[i].start_time >> aArr[i].second_time;
    }
    sort(aArr,aArr+n, aSort);
    cout << "Activity Numbers sort by end time :" << endl;
    for(int i = 0; i<n; i++)
    {
        cout << aArr[i].c << " " <<aArr[i].start_time << " " <<  aArr[i].second_time << endl;
    }
    cout << " " << "Activity Number : " << endl;
    int i = 0;
    cout<< aArr[i].c << " " <<aArr[i].start_time << " " <<  aArr[i].second_time << endl;

    for(int j = 1; j<n; j++)
    {
        if(aArr[j].start_time>=aArr[i].second_time)
        {
            cout << aArr[j].c << " " <<aArr[j].start_time << " " <<  aArr[j].second_time << endl;
            i=j;
        }
    }

    return 0;
}
