#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include<limits.h>

using namespace std;

struct Set
{
    unordered_set<int> elems;
    int cost;
};

vector<int> setCover(vector<Set> &sets, const vector<int> &U)
{
    unordered_set<int> I; // initialize I as an empty set
    vector<int> res; // initialize result as an empty vector

    while (I.size() < U.size()) // loop until I includes all elements in U
    {
        double minRatio = INT_MAX;
        int minSetIndex = -1;

        // find the set Si with the smallest cost effectiveness ratio
        for (int i = 0; i < sets.size(); i++)
        {
            if (find(res.begin(), res.end(), i) != res.end()) // if Si is already included in res, skip it
                continue;

            int newElements = 0;
            for (auto elem : sets[i].elems)
                if (I.find(elem) == I.end()) // if the element is not already in I, it is a new element
                    newElements++;

            double costEffectiveness = (double)sets[i].cost / newElements;
            if (costEffectiveness < minRatio)
            {
                minRatio = costEffectiveness;
                minSetIndex = i;
            }
        }

        // add the elements of Si to I and add Si to res
        for (auto elem : sets[minSetIndex].elems)
            I.insert(elem);
        res.push_back(minSetIndex);
    }

    return res;
}

int main()
{
    int n, m;
    cout<<"Enter Number of elements and number of sets:";
    cin >> n >> m;

    vector<int> U(n);
    cout<<"\nEnter elements:";
    for (int i = 0; i < n; i++)
        cin >> U[i];

    vector<Set> sets(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cout<<"\nEnter Cost and size of set-"<<i<<" :";
        cin >> sets[i].cost >> k;
        cout<<"\nEnter elements for the set:";
        for (int j = 0; j < k; j++)
        {
            int elem;
            cin >> elem;
            sets[i].elems.insert(elem);
        }
    }

    vector<int> res = setCover(sets, U);

    cout << "Selected sets: ";
    for (auto index : res)
        cout << index << " ";
    cout << endl;

    return 0;
}
