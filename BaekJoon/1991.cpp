#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
unordered_map<char, pair<char, char>> tree;

void PreOrder(char cur){
    cout << cur;
    if(tree[cur].first != '.'){
        PreOrder(tree[cur].first);
    }
    if(tree[cur].second != '.'){
        PreOrder(tree[cur].second);
    }
}

void InOrder(char cur){
    if(tree[cur].first != '.'){
        InOrder(tree[cur].first);
    }
    cout << cur;
    if(tree[cur].second != '.'){
        InOrder(tree[cur].second);
    }
}

void PostOrder(char cur){
    if(tree[cur].first != '.'){
        PostOrder(tree[cur].first);
    }
    if(tree[cur].second != '.'){
        PostOrder(tree[cur].second);
    }
    cout << cur;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        char root, left, right;
        cin >> root >> left >> right;
        tree.insert({root, {left, right}});
    }

    PreOrder('A');
    cout << '\n';
    InOrder('A');
    cout << '\n';
    PostOrder('A');
    cout << '\n';
}