#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 101;
bool map[MAX][MAX];
bool visit[MAX][MAX];
int moveY[] = { 0, 0, 1, -1 };
int moveX[] = { 1, -1, 0, 0 };

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            map[i][j] = (line[j] == '1');
        }
    }

    // solve
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visit[0][0] = true;

    while (!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curCount = q.front().second;
        q.pop();

        if(curY == n-1 && curX == m-1){
            cout << curCount << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)  continue;
            if(visit[nextY][nextX]) continue;
            if(!map[nextY][nextX])  continue;

            visit[nextY][nextX] = true;
            q.push({{nextY, nextX}, curCount+1});
        }
    }
    
}