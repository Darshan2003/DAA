#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Comparator for priority queue
struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b)
    {
        return a.bound < b.bound;
    }
};

// Calculates the bound of a node
float bound(Node u, int n, int W, Item arr[])
{
    if (u.weight >= W)
        return 0;

    float profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while ((j < n) && (total_weight + arr[j].weight <= W))
    {
        total_weight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - total_weight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Solves the 0/1 Knapsack problem using the Least Cost Branch and Bound algorithm
int knapsack(int W, Item arr[], int n)
{

    priority_queue<Node, vector<Node>, CompareNode> Q;

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;

    float max_profit = 0;
    Q.push(u);

    while (!Q.empty())
    {
        u = Q.top();
        Q.pop();

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > max_profit)
            max_profit = v.profit;
        //if the item is included
        v.bound = bound(v, n, W, arr);
        if (v.bound > max_profit)
            Q.push(v);


        //if the item is not included
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > max_profit)
            Q.push(v);
    }

    return max_profit;
}

int main()
{
    int W, n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> arr[i].weight >> arr[i].value;
    }

    int max_profit = knapsack(W, arr, n);
    cout << "Maximum profit: " << max_profit << endl;

    return 0;
}
