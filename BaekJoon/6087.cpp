#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int w, h;
pair<int, int> startP, endP;
bool getStartPoint;
char map[101][101];
int count[101][101];

int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
// 0 = 위, 1 = 아래, 2 = 오른쪽, 3 = 왼쪽



void MirrorSearch(){
    queue<pair<pair<int, int>, pair<int, int>>> q; // x, y, mirrorcount, direction
    count[startP.first][startP.second] = 0;
    // Start
    for(int i = 0; i < 4; i++)
        q.push(make_pair(make_pair(startP.first, startP.second), make_pair(0, i)));

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int mirrorCount = q.front().second.first;
        int curDir = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];
            int nextCount = mirrorCount;

            if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w)
                continue;
            
            if(map[nextX][nextY] == '*')
                continue;
            
            if(i != curDir)
                nextCount = mirrorCount + 1;

            if(count[nextX][nextY] == -1 || count[nextX][nextY] >= nextCount){
                q.push(make_pair(make_pair(nextX, nextY), make_pair(nextCount, i)));
                count[nextX][nextY] = nextCount;
            }
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    cin >> w >> h;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];

            if(map[i][j] == 'C'){
                if(!getStartPoint){
                    getStartPoint = true;
                    startP.first = i;
                    startP.second = j;
                }
                else{
                    endP.first = i;
                    endP.second = j;
                } 
            }
        }
    }

    // solution
    memset(count, -1, sizeof(count));
    MirrorSearch();

    // print
    cout << count[endP.first][endP.second] << '\n';
}