#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m, k;  // number count, update count, sum count

long long InitTree(vector<long long> &numbers, vector<long long> &tree, int node, int start, int end){
    if(start == end)
        return tree[node] = numbers[start];
    
    int mid = (start + end) / 2;

    return tree[node] = InitTree(numbers, tree, node*2, start, mid) + InitTree(numbers, tree, node*2+1, mid+1, end);
}

void UpdateTree(vector<long long> &tree, int node, int start, int end, int index, long long difference){
    if(!(start <= index && index <= end))
        return;
    
    tree[node] += difference;

    if(start != end){
        int mid = (start + end) / 2;
        UpdateTree(tree, node*2, start, mid, index, difference);
        UpdateTree(tree, node*2+1, mid+1, end, index, difference);
    }
}

long long GetPrefixSum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return GetPrefixSum(tree, node*2, start, mid, left, right) + GetPrefixSum(tree, node*2+1, mid+1, end, left, right);
}


int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m >> k;

    int tree_height = (int)ceil(log2(n));
    int tree_size = (1 << (tree_height + 1));
    vector<long long> numbers(n);
    vector<long long> segment_tree(tree_size);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    // Init segment tree
    InitTree(numbers, segment_tree, 1, 0, n-1);

    // Problem Solving
    int ps_count = m + k;

    while (ps_count--){
        int type;
        cin >> type;

        if(type == 1){
            int index;
            long long value;
            cin >> index >> value;

            long long difference = value - numbers[index - 1];
            numbers[index - 1] = value;
            UpdateTree(segment_tree, 1, 0, n-1, index-1, difference);
        }
        else if(type == 2){
            int left, right;
            cin >> left >> right;
            cout << GetPrefixSum(segment_tree, 1, 0, n-1, left-1, right-1) << endl;;
        }
    }
    
    return 0;
}