#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[210];

void bfs(int start, vector<vector<int>> computers, int n){
    visit[start] = true;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        
        for(int i = 0; i < n; i++){
            if(!visit[i] && computers[temp][i] == 1){
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(int start, vector<vector<int>> computers, int n){
    visit[start] = true;
    
    for(int i = 0; i < n; i++){
        if(!visit[i] && computers[start][i])
            dfs(i, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            //bfs(i, computers, n);
            dfs(i, computers, n);
            ans++;
        }
    }
    return ans;
}