#include <iostream>
#include <algorithm>
using namespace std;
int R, C;
char maze[21][21];
// 진행 가짓수 오른쪽, 왼쪽, 아래, 위
int nextX[4] = {1, -1, 0, 0};
int nextY[4] = {0, 0, 1, -1};
int visited[26] ={0}; // char 을 int로 바꾸면 65~90이다

int howMany = 0;
// 이전에 방문했던 
void Search(int curX, int curY, int walk){
    visited[(int)maze[0][0]-65]++;// 첫방문 감사합니다
    howMany = max(walk, howMany);
    for(int i = 0; i < 4; i++){
        int goX = curX+nextX[i];
        int goY = curY+nextY[i];
        if(goX < 0 || goX >= R || goY < 0 || goY >= C)
            continue; // 위는 배열을 벗어나는 조건임
        int go = (int)maze[goX][goY] - 65;
        if(visited[go])
            continue;
        
        visited[go]++;
        Search(goX, goY, walk+1);
        visited[go]--;   // for문 다음을 위한 --
    }

}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> maze[i][j];
        }
    }
    Search(0,0,1);

    cout << howMany << '\n';
}