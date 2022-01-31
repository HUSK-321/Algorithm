#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
const int INT_MAX = INT32_MAX;
const int INT_MIN = INT32_MIN;

int InitTree(const vector<int>& num, vector<int>& tree, int node, const int start, const int end, const bool isMax){
    if(start == end)
        return tree[node] = num[start];
    
    int mid = (start + end) / 2;
    if(isMax)
        return tree[node] = max(InitTree(num, tree, node*2, start, mid, isMax), InitTree(num, tree, node*2+1, mid+1, end, isMax));
    else
        return tree[node] = min(InitTree(num, tree, node*2, start, mid, isMax), InitTree(num, tree, node*2+1, mid+1, end, isMax));
}

int GetValue(const vector<int>& tree, const bool isMax, int node, int start, int end, const int left, const int right){
    if(left > end || right < start){
        if(isMax)
            return INT_MIN;
        else
            return INT_MAX;
    }

    if(left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    if(isMax)
        return max(GetValue(tree, isMax, node*2, start, mid, left, right), GetValue(tree, isMax, node*2+1, mid+1, end, left, right));
    else
        return min(GetValue(tree, isMax, node*2, start, mid, left, right), GetValue(tree, isMax, node*2+1, mid+1, end, left, right));
    
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    vector<int> numbers(n+1);
    int tree_height = (int)ceil(log2(n));
    int tree_size = (1 << (1 + tree_height));
    vector<int> max_segment_tree(tree_size);
    vector<int> min_segment_tree(tree_size);

    for(unsigned i = 0; i < n; i++)
        cin >> numbers[i];
    
    // init tree
    InitTree(numbers, max_segment_tree, 1, 0, n-1, true);
    InitTree(numbers, min_segment_tree, 1, 0, n-1, false);

    // solve
    for(unsigned i = 0; i < m; i++){
        int left, right;

        cin >> left >> right;

        int min_val = GetValue(min_segment_tree, false, 1, 0, n-1, left - 1, right - 1);
        int max_val = GetValue(max_segment_tree, true, 1, 0, n-1, left - 1, right - 1);

        cout << min_val << " " << max_val << '\n';
    }
}

