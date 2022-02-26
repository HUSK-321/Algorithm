#include <iostream>
using namespace std;

int m, n;
int map[501][501];
int wayCount[501][501];
int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };

bool isOut(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m)
        return true;
    return false;
}

int DFS(int x, int y){
    if(x == n-1 && y == m-1)
        return 1;

    if(wayCount[x][y] != -1)
        return wayCount[x][y];
        
    wayCount[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if(!isOut(nextX, nextY) && map[nextX][nextY] < map[x][y]) {
            wayCount[x][y] += DFS(nextX, nextY);
        }
    }
    return wayCount[x][y];
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            wayCount[i][j] = -1;
        }
    }

    // solve
    cout << DFS(0, 0) << '\n';
}