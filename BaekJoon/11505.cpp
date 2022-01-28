#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m, k;

long long InitTree(vector<long long>& numbers, vector<long long>& tree, int node, int start, int end){
    if(start == end)
        return tree[node] = numbers[start] % 1000000007;
    
    int mid = (start + end) / 2;
    return tree[node] = (InitTree(numbers, tree, node*2, start, mid) * InitTree(numbers, tree, node * 2 + 1, mid+1, end)) % 1000000007;
}

long long UpdateTree(vector<long long>& tree, int index, int new_num, int node, int start, int end){
    if(!(start <= index && index <= end))
        return tree[node] % 1000000007;

    if(start == end)
        return tree[node] = new_num;

    int mid = (start + end) / 2;
    return tree[node] = (UpdateTree(tree, index, new_num, node*2, start, mid) * UpdateTree(tree, index, new_num, node*2+1, mid+1, end)) % 1000000007;
}

long long GetPrefixMul(vector<long long>& tree, int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 1;
    if(left <= start && end <= right)
        return tree[node] % 1000000007;
    
    int mid = (start + end) / 2;
    return (GetPrefixMul(tree, node*2, start, mid, left, right) * GetPrefixMul(tree, node*2+1, mid+1, end, left, right)) % 1000000007;
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

    for(unsigned int i = 0; i < n; i++)
        cin >> numbers[i];

    // init segment tree
    InitTree(numbers, segment_tree, 1, 0, n-1);

    // solve
    int ps_count = m + k;
    while (ps_count--){
        int type;
        cin >> type;

        if(type == 1){
            int index, new_num;
            cin >> index >> new_num;
            UpdateTree(segment_tree, index-1, new_num, 1, 0, n-1);
        }
        else if(type == 2){
            int from, to;
            cin >> from >> to;
            cout << GetPrefixMul(segment_tree, 1, 0, n-1, from-1, to-1) << endl;;
        }
    }
    
}