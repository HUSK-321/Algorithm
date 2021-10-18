#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, res = 0, edgenum = 0;
pair<int, pair<int , int>> edge[100001];
int parents[10001];

int FindRoot(int x){
    if(x == parents[x])
        return x;
    return parents[x] = FindRoot(parents[x]);
}

void Merge(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);

    if(x == y)
        return;
    parents[x] = y;
}

int main(){
    scanf("%d %d", &v, &e);
    
    for(int i = 0; i <= v; i++)
        parents[i] = i;

    for(int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[i].first = c;
        edge[i].second.first = a;
        edge[i].second.second = b;
    }

    sort(edge, edge + e);
    
    // 간선 갯수만큼 크루스칼 알고리즘
    for(int i = 0; i < e; i++){
        if(FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
            continue;
        
        Merge(edge[i].second.first, edge[i].second.second);
        res += edge[i].first;
        edgenum++;
        if(edgenum == v - 1)
            break;
    }
    printf("%d\n", res);
}