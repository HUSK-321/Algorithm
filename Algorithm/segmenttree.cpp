#include <iostream>
#include <vector>
using namespace std;

long long init (vector<long long> &arr, vector<long long> &tree, int node, int start, int end){
    if(start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;

    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(!(start <= index && index <= end))
        return;
    
    tree[node] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid+1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}