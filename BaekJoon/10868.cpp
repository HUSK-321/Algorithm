#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;

long long InitTree(const vector<long long>& nums, vector<long long>& tree, int node, int start, int end){
    if(start == end)
        return tree[node] = nums[start];
    
    int mid = (start + end) / 2;
    return tree[node] = min(InitTree(nums, tree, node*2, start, mid), InitTree(nums, tree, node*2+1, mid+1, end));
}

long long GetMinValue(const vector<long long>& tree, int node, const int left, const int right, int start, int end){
    if(left > end || right < start)
        return INT32_MAX;
    if(left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    long long left_val = GetMinValue(tree, node*2, left, right, start, mid);
    long long right_val = GetMinValue(tree, node*2+1, left, right, mid+1, end);
    return min(left_val, right_val);
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;

    vector<long long> numbers(n);
    vector<pair<int, int>> answers(m);
    int tree_height = (int)ceil(log2(n));
    int tree_size = (1 << (1 + tree_height));
    vector<long long> min_value_tree(tree_size);

    for(unsigned i = 0; i < n; i++)
        cin >> numbers[i];

    for(unsigned i = 0; i < m; i++)
        cin >> answers[i].first >> answers[i].second;

    // make segment tree
    InitTree(numbers, min_value_tree, 1, 0, n-1);
    
    // solve
    for(unsigned i = 0; i < answers.size(); i++){
        cout << GetMinValue(min_value_tree, 1, answers[i].first-1, answers[i].second-1, 0, n-1) << '\n';
    }
}
