#include <iostream>
#include <queue>
using namespace std;


int r, c, ans;
char map[51][51];
int waterMap[51][51];

int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
bool visit[51][51];
queue<pair<int, int>> water;
pair<int, int> B, G;

int Gosum(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(G.first, G.second), 0));
    visit[G.first, G.second];

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curT = q.front().second;
        q.pop();

        if(curX == B.first && curY == B.second)
            return curT;
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];

            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c){
                if(map[nextX][nextY] != 'X' && !visit[nextX][nextY]){
                    if(waterMap[nextX][nextY] > curT + 1){
                        q.push(make_pair(make_pair(nextX, nextY), curT+1));
                        visit[nextX][nextY] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    // 입력
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == '*') {
                waterMap[i][j] = 0;
                water.push(make_pair(i, j));
            } else{
                waterMap[i][j] = 3000;
            }
            
            if(map[i][j] == 'D') { // 비버의 굴
                B.first = i;
                B.second = j;
            } else if(map[i][j] == 'S') { // 고슴도치 시작지점
                G.first = i;
                G.second = j;
            }
            
        }
    }

    // 물 맵 만들기
    while (!water.empty()) {
        for(int i = 0; i < water.size(); i++){
            int curX = water.front().first;
            int curY = water.front().second;
            water.pop();

            for(int j = 0; j < 4; j++){
                int nextX = curX + goX[j];
                int nextY = curY + goY[j];

                if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c){
                    if(map[nextX][nextY] != 'D' && map[nextX][nextY] != 'X'){
                        if(waterMap[nextX][nextY] > waterMap[curX][curY] + 1){
                            waterMap[nextX][nextY] = waterMap[curX][curY] + 1;
                            water.push(make_pair(nextX, nextY));
                        }
                    }
                }
            }
        }
    }    

    // 고슴도치 가자
    ans = Gosum();
    // 결과 출력
    if(ans == -1)
        cout << "KAKTUS" << '\n';
    else
        cout << ans << '\n';

}