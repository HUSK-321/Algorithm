#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n;
char map[51][51];
bool visit[51][51][2];
int answer = 0;
pair<int, int> treePoint; int treeDir = 0;  // 1 : vertical, 0 : horizontal
pair<int, int> endPoint;  int endDir = 0;

bool CanTranspose(int y, int x, int dir){
/*
(y-1)(x-1)  (y-1)(x)   (y-1)(x+1)
(y)(x-1)    (y)(X)     (y)(x+1)
(y+1)(x-1)  (y+1)(x)   (y+1)(x+1)
*/
    if(x-1 < 0 || x+1 >= n)
        return false;
    
    if(x-1 < 0 || x+1 >= n)
        return false;
        
    if(dir == 1){
        if(map[y][x-1] == '1' || map[y][x+1] == '1')
            return false;
    }else{
        if(map[y-1][x] == '1' || map[y+1][x] == '1')
            return false;
    }
    if(map[y-1][x-1] == '1' || map[y-1][x+1] == '1' || map[y+1][x-1] == '1' || map[y+1][x+1] == '1')
        return false;
    cout << "true\n";
    return true;
}

int Search(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{treePoint}, {treeDir, 0}});
    visit[treePoint.first][treePoint.second][treeDir] = true;

    while (!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curDir = q.front().second.first;
        int curCount = q.front().second.second;
        q.pop();

        if(curY == endPoint.first && curX == endPoint.second){
            if(endDir == curDir){
                return curCount;
            }
        }

        if(curDir == 0){       // 누워있는 경우 cury : x-1 x x+1
            // U
            if(curY-1 >= 0 && curX-1 >= 0 && curX+1 < n && !visit[curY-1][curX][curDir]){
                if(map[curY-1][curX] != '1' && map[curY-1][curX-1] != '1' && map[curY-1][curX+1] != '1'){
                    visit[curY-1][curX][curDir] = true;
                    q.push({{curY-1, curX}, {curDir, curCount+1}});
                }
            }   
            // D
            if(curY+1 < n && curX-1 >= 0 && curX+1 < n && !visit[curY+1][curX][curDir]){
                if(map[curY+1][curX] != '1' && map[curY+1][curX-1] != '1' && map[curY+1][curX+1] != '1'){
                    visit[curY+1][curX][curDir] = true;
                    q.push({{curY+1, curX}, {curDir, curCount+1}});
                }
            }
            // L
            if(curX-2 > 0 && map[curY][curX-2] != '1'){
                if(!visit[curY][curX-1][curDir]){
                    visit[curY][curX-1][curDir] = true;
                    q.push({{curY, curX-1}, {curDir, curCount+1}});
                }
            }
            // R
            if(curX+2 < n && map[curY][curX+2] != '1'){
                if(!visit[curY][curX+1][curDir]){
                    visit[curY][curX+1][curDir] = true;
                    q.push({{curY, curX+1}, {curDir, curCount+1}});
                }
            }
            // T
            if(CanTranspose(curY, curX, curDir)){
                if(!visit[curY][curX][1]){
                    visit[curY][curX][1] = true;
                    q.push({{curY, curX}, {1, curCount+1}});
                }
            }
        }
        else { // 서 있는 경우
            // U
            if(curY-2 >= 0 && map[curY-2][curX] != '1'){
                if(!visit[curY-1][curX][curDir]){
                    visit[curY-1][curX][curDir] = true;
                    q.push({{curY-1, curX}, {curDir, curCount+1}});
                }
            }
            // D
            if(curY+2 < n && map[curY+2][curX] != '1'){
                if(!visit[curY+1][curX][curDir]){
                    visit[curY+1][curX][curDir] = true;
                    q.push({{curY+1, curX}, {curDir, curCount+1}});
                }
            }
            // L
            if(curX-1 >= 0 && curY+1 < n && curY-1 > 0 && !visit[curY][curX-1][curDir]){
                if(map[curY-1][curX-1] != '1' && map[curY][curX-1] != '1' && map[curY+1][curX-1] != '1'){
                    visit[curY][curX-1][curDir] = true;
                    q.push({{curY, curX-1}, {curDir, curCount+1}});
                }
            }
            // R
            if(curX-1 < n && curY-1 >= 0 && curY < n && !visit[curY+1][curX+1][curDir]){
                if(map[curY-1][curX+1] != '1' && map[curY][curX+1] != '1' && map[curY+1][curX+1] != '1'){
                    visit[curY][curX+1][curDir] = true;
                    q.push({{curY, curX+1}, {curDir, curCount+1}});
                }
            }
            // T
            if(CanTranspose(curY, curX, curDir)){
                if(!visit[curY][curX][0]){
                    visit[curY][curX][0] = true;
                    q.push({{curY, curX}, {0, curCount+1}});
                }
            }
        }
    }
    return 0;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;

    int treeCount = 0, endCount = 0;
    int firstTree = 0, firstEnd = 0;
    for(int i = 0; i < n ; i++){
        string input;   cin >> input;
        for(int j = 0; j < n; j++){
            map[i][j] = input[j];

            

            if(input[j] == 'B') { 
                treeCount++;

                if(treeCount == 2){
                    treePoint = make_pair(i, j);
                    if(firstTree != i)
                        treeDir = 1;
                }

                firstTree = i;
            }
            if(input[j] == 'E'){
                endCount++;

                if(endCount == 2){
                    endPoint = make_pair(i, j);
                    if(firstEnd != i)
                        endDir = 1;
                }
                firstEnd = i;
            }
        }
    }


    // search
    cout << Search() << '\n';
}