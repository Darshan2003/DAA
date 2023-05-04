#include<stdio.h>
#include<stdlib.h>


void merge(int arr[],int l, int mid, int r)
{
    int L[mid-l+1];
    int R[r-mid];
    int len1 = mid-l+1;
    int len2 = r-mid;

    for(int i = 0; i<len1;i++)
        L[i] = arr[l+i];
    
    for(int i=0;i<len2;i++)
        R[i] = arr[mid+1+i];

    int m=0,n=0,k=l;

    while(m<len1 && n<len2)
    {
        if(L[m]<R[n])
        {
            arr[k++] =  L[m++];
        }
        else
        {
            arr[k++] = R[n++];
        }
    }


    while(m<len1)
        arr[k++] = L[m++];
    
    while(n<len2)
        arr[k++] = R[n++];

        
}

void merge_sort(int arr[],int l, int r)
{
    if(l>=r)
        return;
    int mid = l+(r-l)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


void main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};

    merge_sort(arr,0,9);

    for(int i=0;i<10;i++)
    {
        printf("%d\n",arr[i]);
    }
}