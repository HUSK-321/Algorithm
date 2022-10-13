#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
int n;
int map[MAX][MAX];
bool visit[MAX][MAX];
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };

void SearchMap(int y, int x, const int height){
    
    for(int i = 0; i < 4; i++){
        int nextY = y + moveY[i];
        int nextX = x + moveX[i];

        if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n)  continue;
        if(visit[nextY][nextX]) continue;
        if(map[nextY][nextX] <= height) continue;

        visit[nextY][nextX] = true;
        SearchMap(nextY, nextX, height);
    }
    
}


int main(){
    // input
    cin >> n;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cin >> map[y][x];
    
    // solve
    int maxAreaCount = 1;
    for(int height = 1; height <= 100; height++){
        int heightCount = 0;
        memset(visit, false, sizeof(visit));

        // search in this height
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(!visit[y][x] && map[y][x] > height){
                    visit[y][x] = true;
                    SearchMap(y, x, height);
                    heightCount++;
                }
            }
        }

        if(heightCount == 0)    break;

        if(heightCount > maxAreaCount)
            maxAreaCount = heightCount;
    }

    cout << maxAreaCount << '\n';
}