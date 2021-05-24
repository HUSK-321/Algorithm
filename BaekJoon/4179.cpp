#include <iostream>
#include <queue>
using namespace std;

int r, c, jsx, jsy, ans;
char map[1000][1000];
int fire[1000][1000];
bool visit[1000][1000];
int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> fireq;

void Firemap(){
    while(!fireq.empty()){
        int qsize = fireq.size();
        for(int i = 0; i < qsize; i++){
            int curX = fireq.front().first;
            int curY = fireq.front().second;
            fireq.pop();

            for(int j = 0; j < 4; j++){
                int nextX = curX + goX[j];
                int nextY = curY + goY[j];

                if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c){
                    if(map[nextX][nextY] != '#'){
                        if(fire[nextX][nextY] > fire[curX][curY] + 1){
                            fire[nextX][nextY] = fire[curX][curY] + 1;
                            fireq.push(make_pair(nextX, nextY));
                        }
                    }
                }
            }
        }
    }
}

int Jihoon(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(jsx, jsy), 0));
    visit[jsx][jsy] = true;

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if(curX == 0 || curX == r-1 || curY == 0 || curY == c-1)
            return time + 1;

        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];

            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c){
                if(map[nextX][nextY] != '#' && visit[nextX][nextY] == false){
                    if(fire[nextX][nextY] > time + 1){
                        visit[nextX][nextY] = true;
                        q.push(make_pair(make_pair(nextX, nextY), time+1));
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

            if(map[i][j] == 'J') {
                jsx = i;
                jsy = j;
            }
            else if(map[i][j] == 'F') {
                fireq.push(make_pair(i, j));
                fire[i][j] = 0;
            } else
                fire[i][j] = 999999999;
        }
    }

    // 불 시간 구하기
    Firemap();

    // 지훈
    ans = Jihoon();

    if(ans == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << ans << '\n';
    
}