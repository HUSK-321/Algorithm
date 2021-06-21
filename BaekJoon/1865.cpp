#include <iostream>
#include <vector>
using namespace std;

int t, n, m, w; // 지점의 수, 도로의 수, 웜홀의 수
int node[501];
bool possible;
vector<pair<pair<int, int>, int> > edge;

bool Bellman(){
    node[0] = 1;

    for(int i = 0; i <= n-1; i++){
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

    for(int j = 0; j < edge.size(); j++){
        int from, to, cost;

        from = edge[j].first.first;
        to = edge[j].first.second;
        cost = edge[j].second;

        if(node[from] == 999999999)
            continue;
            
        if(node[to] > node[from] + cost){
            return true;
        } 
    }
    return false;
}

int main(){
    scanf("%d", &t);
    while (t--){
        int from, to, cost;
        // init
        for(int i = 0; i < 501; i++)
            node[501] = 999999999;

        edge.clear();

        //input
        scanf("%d %d %d", &n, &m, &w);
        while(m--){
            scanf("%d %d %d", &from, &to, &cost);
            edge.push_back(make_pair(make_pair(from, to), cost));
            edge.push_back(make_pair(make_pair(to, from), cost));
        }
        while(w--){
            scanf("%d %d %d", &from, &to, &cost);
            edge.push_back(make_pair(make_pair(from, to), -cost));
        }
        
        // bellman-ford
        possible = Bellman();

        if(possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
}