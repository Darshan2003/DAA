// #include <stdio.h>
// #include <stdlib.h>

// // Structure to represent an item in the input array
// struct Item {
//     int value;  // Value of the item
//     int weight; // Weight of the item
// };

// // Function to compare items based on their value per unit weight
// int compare(const void *x, const void *y) {
//     struct Item *item1 = (struct Item *)x;
//     struct Item *item2 = (struct Item *)y;
//     double ratio1 = (double)item1->value / item1->weight;
//     double ratio2 = (double)item2->value / item2->weight;
//     if (ratio1 > ratio2) {
//         return -1;
//     } else if (ratio1 < ratio2) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// // Function to find the maximum value that can be obtained from a given weight of items
// double fractional_knapsack(int capacity, struct Item items[], int n) {
//     // Sort the items in decreasing order of their value per unit weight
//     qsort(items, n, sizeof(struct Item), compare);

//     // Initialize variables
//     double value = 0.0;
//     int i = 0;

//     // Loop through the sorted items and add them to the knapsack
//     while (capacity > 0 && i < n) {
//         if (capacity >= items[i].weight) {
//             // Add the whole item to the knapsack
//             value += (double)items[i].value;
//             capacity -= items[i].weight;
//         } else {
//             // Add a fractional part of the item to the knapsack
//             value += ((double)capacity / items[i].weight) * items[i].value;
//             capacity = 0;
//         }
//         i++;
//     }

//     // Return the total value of the items in the knapsack
//     return value;
// }

// // Sample usage
// int main() {
//     // Create an array of items
//     struct Item items[] = {
//         {60, 10},
//         {100, 20},
//         {120, 30},
//     };
//     int n = sizeof(items) / sizeof(items[0]);

//     // Set the capacity of the knapsack
//     int capacity = 50;

//     // Calculate the maximum value that can be obtained
//     double max_value = fractional_knapsack(capacity, items, n);

//     // Print the maximum value that can be obtained
//     printf("Maximum value that can be obtained is: %.2lf\n", max_value);

//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *x, const void *y)
{
    struct Item *a = (struct Item *)x;
    struct Item *b = (struct Item *)y;
    int ratio1 = (double)a->value/a->weight;
    int ratio2 = (double)b->value/b->weight;

    if(ratio1>ratio2)
    {
        return -1;
    }
    else if (ratio1<ratio2)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

int knapsack(struct Item items[],int n,int capacity)
{
    qsort(items, n, sizeof(struct Item),compare);

    int j=0;
    double val = 0;
    while(capacity>0 && j<n)
    {
        if(capacity>=items[j].weight)
        {
            val += items[j].value;
            capacity -= items[j].weight;
        }
        else
        {
            val += (items[j].value/items[j].weight) * capacity;
            capacity = 0;
        }
        j++;
    }

    return val;
    
}

int main()
{
    int n;
    printf("\nEnter number of items:");
    scanf("%d",&n);

    struct Item items[n];

    printf("\nEnter each items weight and value:");

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&items[i].value,&items[i].weight);
    }
    int cap;
    printf("Enter Capacity of the knapsack:");
    scanf("%d",&cap);

    printf("\nMaximum value:%d",knapsack(items,n,cap));
    return 0;
}