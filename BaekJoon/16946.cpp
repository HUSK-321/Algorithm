#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int inputMap[1001][1001];
int BFSMap[1001][1001];
bool visit[1001][1001];

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++)
            inputMap[i][j] = line[j] - '0';
    }
}