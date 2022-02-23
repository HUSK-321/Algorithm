#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parent[101];
pair<int, pair<int, int>> edge[10001];

int findRoot(int x){
    if(x == parent[x])
        return x;
    return parent[x] = findRoot(parent[x]);
}

void Merge(int x, int y){
    x = findRoot(x);
    y = findRoot(y);

    if(x == y)
        return;

    parent[x] = y;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int edgeCount = costs.size();
    // init
    for(unsigned i = 0; i <= n; i++)
        parent[i] = i;

    // make input
    for(unsigned i = 0; i < edgeCount; i++){
        int from = costs[i][0];
        int to = costs[i][1];
        int cost = costs[i][2];

        edge[i].first = cost;
        edge[i].second.first = from;
        edge[i].second.second = to;
    }

    sort(edge, edge+edgeCount);


    // make mst
    int jointed = 0;
    for(unsigned i = 0; i < edgeCount; i++){
        int island1 = edge[i].second.first;
        int island2 = edge[i].second.second;
        if(findRoot(island1) == findRoot(island2))
            continue;
        
        Merge(island1, island2);

        answer += edge[i].first;
        jointed++;
        if(jointed == n-1)
            break;
    }

    return answer;
}