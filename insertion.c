#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}
void main()
{
    FILE *fp;
    fp = fopen("insertion.txt","w");
    srand(time(0));
    for(int i=0;i<10000;i++)
    {
        fprintf(fp,"%d\n",rand()%10000);
    }
    fclose(fp);

    for(int i = 1;i<=100;i++)
    {
        fp = fopen("insertion.txt","r");

        int arr[100*i];

        for(int j=0;j<i*100;j++)
        {
            fscanf(fp,"%d",&arr[j]);
        }
        fclose(fp); 

        clock_t t = clock();
        insertion_sort(arr,i*100);
        t = clock() - t;
        printf("\nTime taken:%f",(double)t/CLOCKS_PER_SEC);
    }

}