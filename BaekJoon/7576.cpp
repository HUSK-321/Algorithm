#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int tomato[1001][1001];
queue<pair<int, int>> q;
int moveX[] = { 1, -1, 0, 0 };
int moveY[] = { 0, 0, 1, -1 };

bool IsOut(int x, int y){
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
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tomato[i][j];

            if(tomato[i][j] == 1)   q.push({i, j});
        }
    }

    // Search
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        int curDay = tomato[curY][curX];
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextX, nextY)) continue;

            if(tomato[nextY][nextX] == 0){
                tomato[nextY][nextX] = curDay + 1;
                q.push({nextY, nextX});
            }
        }
    }

    // output
    int answer = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tomato[i][j] == 0){
                cout << "-1\n";
                return 0;
            }

            answer = max(answer, tomato[i][j]);
        }
    }

    cout << answer-1 << '\n';
    return 0;
    
}