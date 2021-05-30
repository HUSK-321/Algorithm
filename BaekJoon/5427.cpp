#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t, w, h;
pair<int, int> s;
queue<pair<int, int> > fireQ;
char map[1000][1000];
int firemap[1000][1000];
bool visit[1000][1000];
int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };


void InitArr(){
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            firemap[i][j] = 999999999;
        }
    }
    memset(visit, false, sizeof(visit));
}

void MakeFire(){
    while (!fireQ.empty()){
        for(int i = 0; i < fireQ.size(); i++){
            int curX = fireQ.front().first;
            int curY = fireQ.front().second;
            fireQ.pop();

            for(int j = 0; j < 4; j++){
                int nextX = curX + goX[j];
                int nextY = curY + goY[j];

                if(nextX >= 0 && nextX < h && nextY >= 0 && nextY < w){
                    if(map[nextX][nextY] != '#'){
                        if(firemap[nextX][nextY] > firemap[curX][curY] + 1){
                            firemap[nextX][nextY] = firemap[curX][curY] + 1;
                            fireQ.push(make_pair(nextX, nextY));
                        }
                    }
                }
            }
        }
    }
}

void Sanguen() {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(s.first, s.second), 0));
    visit[s.first][s.second] = true;

    while (!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curT = q.front().second;
        q.pop();

        if(curX == 0 || curX == h-1 || curY == 0 || curY == w-1){
            cout << curT + 1 << '\n';
            return;
        }
            
        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];

            if(nextX >= 0 && nextX < h && nextY >= 0 && nextY < w){
                if(map[nextX][nextY] == '.' && visit[nextX][nextY] == false){
                    if(firemap[nextX][nextY] > curT + 1){
                        visit[nextX][nextY] = true;
                        q.push(make_pair(make_pair(nextX, nextY), curT + 1));
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return;
}

void Input(){
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];
                
            if(map[i][j] == '@'){
                s.first = i;
                s.second = j;
            }

            if(map[i][j] == '*'){
                fireQ.push(make_pair(i, j));
                firemap[i][j] = 0;
            } 
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        InitArr();
        Input();
        
        MakeFire();
        Sanguen();
    }
}