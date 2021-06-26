#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };
int map[1001][1001];
int arr[1001][1001][2];

int BFS(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1));
    arr[0][0][1] = 1;

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if(curX == m-1 && curY == n-1)
            return arr[curY][curX][count];
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + goX[i];
            int nextY = curY + goY[i];

            if(nextX >= 0 && nextX <= m-1 && nextY >= 0 && nextY <= n-1){
                if(map[nextY][nextX] == 1 && count){
                    arr[nextY][nextX][0] = arr[curY][curX][count] + 1;
                    q.push(make_pair(make_pair(nextX, nextY), 0));
                }
                else if(map[nextY][nextX] == 0 && arr[nextY][nextX][count] == 0){
                    arr[nextY][nextX][count] = arr[curY][curX][count] + 1;
                    q.push(make_pair(make_pair(nextX, nextY), count));
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            map[i][j] = line[j] - '0';
        }
    }

    printf("%d\n", BFS());
}