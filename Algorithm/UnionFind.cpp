#include <iostream>
#include <algorithm>
using namespace std;
int parent[1000001];
int level[1000001];

int FindParent(int x){
    if(x == parent[x])
        return x;

    return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;

    if(level[x] > level[y])
        swap(x, y);

    else
        parent[x] = y;

    if(level[x] == level[y])
        level[y]++;
}

int main(){
    for(int i = 0; i <= 1000000; i++)
        parent[i] = i;
}