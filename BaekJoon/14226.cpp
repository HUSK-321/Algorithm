#include <iostream>
#include <queue>
using namespace std;

bool visit[2000][2000]; // [화면][클립보드]

int bfs(int s){
    queue<pair<pair<int, int>, int> > q;  // 화면, 클립보드, 시간
    int screen, clipboard, time;
    q.push(make_pair(make_pair(1,0), 0));
    visit[1][0] = true;
    // 큐를 이용한 너비 우선 탐색
    while(!q.empty()){
        screen = q.front().first.first;
        clipboard = q.front().first.second;
        time = q.front().second;
        q.pop();

        // 결과 출력
        if(screen == s)
            break;

        // 너비우선탐색
        // 화면 이모티콘 클립보드로, 화면에서 하나 지우기
        if(screen > 0 && screen < 2000){
            if(visit[screen][screen] == false){
                visit[screen][screen] = true;
                q.push(make_pair(make_pair(screen,screen), time+1));
            }
            if(visit[screen-1][clipboard] == false){
                visit[screen-1][clipboard] = true;
                q.push(make_pair(make_pair(screen-1,clipboard), time+1));
            }
        }
        // 클립보드에 있는거 붙여넣기
        if(clipboard > 0 && screen + clipboard < 2000){
            if(visit[screen + clipboard][clipboard] == false){
                visit[screen + clipboard][clipboard] = true;
                q.push(make_pair(make_pair(screen + clipboard,clipboard), time+1));
            }
        }
    }
    return time;
}

int main(){
    int input;
    cin >> input;
    cout << bfs(input) << '\n';
}