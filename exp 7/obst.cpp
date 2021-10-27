#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
#define inputarr(arr,n) for(int i=0;i<n;i++) cin>>arr[i]

// Find optimal cost to construct a binary search tree from keys
// `i` to `j`, where each key `k` occurs `freq[k]` number of times
int findOptimalCost(int freq[], int start, int end, int level) {
    // base case
    if (end < start) {
        return 0;
    }

    int optimalCost = INT_MAX;

    // consider each key as a root and recursively find an optimal solution
    for (int k = start; k <= end; k++) {
        // recursively find the optimal cost of the left subtree
        int leftOptimalCost = findOptimalCost(freq, start, k - 1, level + 1);

        // recursively find the optimal cost of the right subtree
        int rightOptimalCost = findOptimalCost(freq, k + 1, end, level + 1);

        // current node's cost is `freq[k]×level`
        int cost = freq[k] * level + leftOptimalCost + rightOptimalCost;

        // update the optimal cost
        optimalCost = min (optimalCost, cost);
    }

    // Return minimum value
    return optimalCost;
}

int main() {
    int n;
	cin >> n;
	int keys[n], freq[n];
	inputarr(keys, n);
	inputarr(freq, n);

    cout << "The optimal cost of constructing BST is "
         << findOptimalCost(freq, 0, n - 1, 1);

    return 0;
}