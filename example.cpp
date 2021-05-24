#include <iostream>
#include <queue>

using namespace std;

int r, c;
int curX, curY, curT, nextX, nextY;
char arr[1000][1000];
int fire[1000][1000];
bool visit[1000][1000];
queue<pair<int,int> > fireQ;
pair<int, int> Ji, Firestart;

int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };

int Jihoon(){
    queue<pair<pair<int, int>, int> >  q;    // x, y, 시간
    q.push(make_pair(make_pair(Ji.first, Ji.second), 0));
    visit[Ji.first][Ji.second] = true;

    while (!q.empty()){
        curX = q.front().first.first;
        curY = q.front().first.second;
        curT = q.front().second;
        q.pop();
        visit[curX][curY] = true;
        if(curX == 0 || curX == r -1 || curY == 0 || curY == c -1)
            return curT + 1;

        for(int i = 0; i < 4; i++){
            nextX = curX + goX[i];
            nextY = curY + goY[i];

            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c) {
                if(arr[nextX][nextY] != '#' && !visit[nextX][nextY]){
                    if(fire[nextX][nextY] > curT + 1){
                        q.push(make_pair(make_pair(nextX, nextY), curT + 1));
                    }
                }
            }
        }
    }
    return -100;
}

void Firemap(){

    while(!fireQ.empty()){
        for(int i = 0; i < fireQ.size(); i++){
            curX = fireQ.front().first;
            curY = fireQ.front().second;
            fireQ.pop();

            for(int j = 0; j < 4; j++){
                nextX = curX + goX[j];
                nextY = curY + goY[j];

                if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c){
                    if(arr[nextX][nextY] != '#'){
                        if(fire[nextX][nextY] > fire[curX][curY] + 1){
                            fire[nextX][nextY] = fire[curX][curY] + 1;
                            fireQ.push(make_pair(nextX, nextY));
                        }
                    }
                }
            }
        }
    }
}

// . : 지나갈 수 있음
// # : 벽 , J : 첫 위치, F : 불
int main(){
    // 입력
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            bool isF = false;
            cin >> arr[i][j];

            if(arr[i][j] == 'J'){
                Ji.first = i;
                Ji.second = j;
            }

            if(arr[j][j] == 'F'){
                fireQ.push(make_pair(i, j));
                fire[i][j] = 0;
                isF = true;
            }

            if(!isF)
                fire[i][j] = 1000000000;

        }
    }

    // 불 지형 만들기
    Firemap();

    // 사람 이동, 출력
    int res = Jihoon();

    if(res == -100)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << res << "\n";
}