#include<iostream>
#include<vector>
using namespace std;

void backtrack(int i,int target, int curr, vector<int> temp,vector<int> arr)
{
    if(curr==target)
    {
        cout<<"{";
        for (int i = 0; i < temp.size(); i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<"}";
        return;
    }
    
    if(i==arr.size())
        return;

    temp.push_back(arr[i]);
    backtrack(i+1,target,curr+arr[i],temp,arr);
    temp.pop_back();
    backtrack(i+1,target,curr,temp,arr);
}

int main()
{
    cout<<"Enter Number of elements";
    int n;

    cin>> n;

    cout<<"\nEnter elements of the array";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"\nEnter Target:";
    cin>>target;
    vector<int> temp;
    backtrack(0,target,0,temp,arr);
    return 0;
}