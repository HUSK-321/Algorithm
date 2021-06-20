#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long node[501];
vector<pair<pair<int, int>, int>> edge;

void Bellman(){
    // 벨만 포드 알고리즘
    node[1] = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < edge.size(); j++){
            int from, to, cost;
            from = edge[j].first.first;
            to = edge[j].first.second;
            cost = edge[j].second;

            if(node[from] == 999999999)
                continue;
            
            if(node[to] > node[from] + cost)
                node[to] = node[from] + cost;
        }
    }
        //사이클이 있는지 확인하기
    for(int i = 0; i < edge.size(); i++){
        int from, to, cost;
        from = edge[i].first.first;
        to = edge[i].first.second;
        cost = edge[i].second;

        if(node[from] == 999999999)
            continue;
            
        if(node[to] > node[from] + cost){
            printf("-1\n");
            return;
        }
            
    }

    // 출력
    for(int i = 2; i <= n; i++){
        if(node[i] == 999999999)
            printf("-1\n");
        else
            printf("%d\n", node[i]);
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++)
        node[i] = 999999999;

    for(int i = 0; i < m; i++){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        edge.push_back(make_pair(make_pair(from, to), cost));
    }

    Bellman();
}