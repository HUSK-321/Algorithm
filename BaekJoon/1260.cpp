#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, v;
int a, b;
bool visit[1001];
int edge[1001][1001];

void DFS(int node){
    visit[node] = true;
    printf("%d ", node);
    for(int i = 1; i <= n; i++){
        if(!visit[i] && edge[node][i])
            DFS(i);
    }
}

void BFS(){
    queue<int> q;

    q.push(v);
    visit[v] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        printf("%d ", node);

        for(int i = 1; i <= n; i++){
            if(!visit[i] && edge[node][i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
    
}

int main(){
    scanf("%d %d %d", &n, &m, &v);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    DFS(v);
    memset(visit, false, sizeof(visit));
    printf("\n");
    BFS();
}
/*
4 5 1
1 2
1 3
1 4
2 4
3 4
*/