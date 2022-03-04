#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

int n, m;
int map[101][101];
int dist[101][101];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

bool isOut(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n)
        return true;
    return false;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string input;
        cin >> input;
        for(int j = 0; j < input.size(); j++){
            map[i][j] = input[j] - '0';
            dist[i][j] = INT32_MAX-1;
        }
    }

    //search
    queue<pair<int, int>> q; // x, y, break count
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    while (!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];

            if(isOut(nextX, nextY)) continue;

            if(map[nextX][nextY] == 1){
                if(dist[nextX][nextY] > dist[curX][curY] + 1){
                    dist[nextX][nextY] = dist[curX][curY] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
            else{
                if(dist[nextX][nextY] > dist[curX][curY]){
                    dist[nextX][nextY] = dist[curX][curY];
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
    
    cout << dist[m-1][n-1] << '\n';
    return 0;
}