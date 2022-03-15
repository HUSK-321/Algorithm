#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[9][9];
int lab[9][9];
int temp[9][9];
int answer = -1;
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

vector<pair<int, int>> initialVirus;

void CopyLab(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            map[i][j] = lab[i][j];
}

void MakeTempMap(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            temp[i][j] = map[i][j];
}

bool IsOut(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= m)
        return true;
    return false;
}

void SpreadVirus(){
    MakeTempMap();
    
    queue<pair<int, int>> q;

    for(int i = 0; i < initialVirus.size(); i++){
        q.push(initialVirus[i]);
    }

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];

            if(IsOut(nextY, nextX)) continue;
            if(temp[nextY][nextX] == 0){
                temp[nextY][nextX] = 2;
                q.push({nextY, nextX});
            }
        }
    }
    
    int safeZone = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(temp[i][j] == 0){
                safeZone++;
            }
        }
    }

    answer = max(answer, safeZone);
}

void BuildWall(int wallCount){
    if(wallCount == 3){
        SpreadVirus();
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                BuildWall(wallCount+1);
                map[i][j] = 0;
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
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int input;
            cin >> input;

            lab[i][j] = input;
            if(input == 2)
                initialVirus.push_back({i, j});
        }
    }

    // solve
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(lab[i][j] == 0){
                // build wall
                CopyLab();
                map[i][j] = 1;
                BuildWall(1);
                map[i][j] = 0;
            }
        }
    }

    // output
    cout << answer << '\n';
}