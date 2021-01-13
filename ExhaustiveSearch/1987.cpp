#include <iostream>
using namespace std;

char maze[21][21];
int visited[26] ={0};
// char 을 int로 바꾸면 65~90이다
// 이전에 방문했던 
void Search(){
    
}

int main(){
    int R, C;
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> maze[i][j];
        }
    }
}