#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
const int MAX = 2600;
char map[51][51];
int wallBreak[51][51];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

bool IsOut(int y, int x){
    if(x < 0 || y < 0 || x >= n || y >= n) 
        return true;
    return false;
}

// void MakeMaze(){
//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     wallBreak[0][0] = 0;

//     while(!q.empty()){
//         int curY = q.front().first;
//         int curX = q.front().second;
//         q.pop();
//         for(int i = 0; i < 4; i++){
//             int nextY = curY + moveY[i];
//             int nextX = curX + moveX[i];
//             if(IsOut(nextY, nextX)) continue;

//             int nextIsWall = (map[nextY][nextX] == '0') ? 1 : 0;

//             if(wallBreak[curY][curX] + nextIsWall < wallBreak[nextY][nextX]){
//                 wallBreak[nextY][nextX] = wallBreak[curY][curX] + nextIsWall;
//                 q.push({nextY, nextX});
//             }
//         }
//     }
// }
void MakeMaze(){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    wallBreak[0][0] = 0;

    while(!q.empty()){
        int count = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();
        
        if(count > wallBreak[curY][curX])   continue;

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];
            if(IsOut(nextY, nextX)) continue;

            int nextIsWall = (map[nextY][nextX] == '0') ? 1 : 0;

            if(count + nextIsWall < wallBreak[nextY][nextX]){
                q.push({count + nextIsWall, {nextY, nextX}});
                wallBreak[nextY][nextX] = count + nextIsWall;
            }
        }
    }
}
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    // search
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            wallBreak[i][j] = MAX;
    MakeMaze();

    // print
    cout << wallBreak[n-1][n-1] << '\n';
}
