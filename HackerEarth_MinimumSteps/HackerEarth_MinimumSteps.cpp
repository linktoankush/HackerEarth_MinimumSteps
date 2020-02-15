// HackerEarth_MinimumSteps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(pair<int, int>& A1, pair<int, int>& A2)
{
    return A1.first < A2.first;
}
int main()
{
    int N;
    std::vector<pair<int, int>> arrPos;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arrPos.push_back( make_pair(tmp, i));
        //Arr2.push_back(tmp);
    }

    sort(arrPos.begin(), arrPos.end(), myfunction);

    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(N, false);

    // Initialize result 
    int ans = 0;

    // Traverse array elements 
    for (int i = 0; i < N; i++)
    {
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node 
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.  
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
    //std::cout << std::endl;
    std::cout << ans << std::endl;

    return 0;
}
