#include <iostream>
#include <queue>

using namespace std;

int r, c;
char arr[1001][1001];
int fire[1001][1001];
bool visit[1001][1001];
queue<pair<int,int> > fireQ;
pair<int, int> Ji, Firestart;

int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };

int Jihoon(){
    queue<pair<pair<int, int>, int> >  q;    // x, y, 시간
    q.push(make_pair(make_pair(Ji.first, Ji.second), 0));
    visit[Ji.first][Ji.second] = true;

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int curT = q.front().second;
        q.pop();

        if(x == 0 || x == r -1 || y == 0 || y == c -1)
            return curT + 1;

        for(int i = 0; i < 4; i++){
            int nextX = x + goX[i];
            int nextY = y + goY[i];

            if(nextX >= 0 && nextX < r && nextY >= 0 && nextY < c) {
                if(arr[nextX][nextY] != '#' && visit[nextX][nextY] == false){
                    if(fire[nextX][nextY] > curT + 1){
                        q.push(make_pair(make_pair(nextX, nextY), curT + 1));
                        visit[nextX][nextY] = true;
                    }
                }
            }
        }
    }
    return -100;
}

void Firemap(){
    fireQ.push(make_pair(Firestart.first, Firestart.second));

    while(!fireQ.empty()){
        for(int i = 0; i < fireQ.size(); i++){
            int curX = fireQ.front().first;
            int curY = fireQ.front().second;
            fireQ.pop();

            for(int j = 0; j < 4; j++){
                int nextX = curX + goX[j];
                int nextY = curY + goY[j];

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
                Firestart.first = i;
                Firestart.second = j;
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