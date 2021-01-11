#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int floor[1000001];

int Search(){
    queue<int> q;
    q.push(S);
    floor[S] = 1;

    while (!q.empty()){
        int here = q.front();
        q.pop();

        if(here == G)   // 도달
            return floor[here] - 1;
        
        // 갈 수 있는 가짓수를 배열로 저장
        int toNext[2] = { here+U, here-D };

        for(int i = 0; i < 2; i++){
            // 갈 수 있는 범위인지, 방문했던건 아닌지 확인
            if(1 <= toNext[i] && toNext[i] <= F && floor[toNext[i]] == 0){
                // 가능하다면 
                floor[toNext[i]] = floor[here] + 1; //이걸로 몇번 이동했는지 카운트 하는것
                q.push(toNext[i]);  // 큐에 넣어서 while 계속 되게 함
            }
            // 조건에 맞지않아 못간다면 큐가 비어서 갈 while문을 탈출함
        }
    }
    // while문 탈출했다면 -1 리턴
    return -1;
}
int main(){
    // 총 F 층, 현재 있는곳 S층, 가야하는곳은 G층
    // U 위로 갈 수 있는 정도, D 아래로 갈 수 있는 정도
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int a = Search();
    if(a==-1)
        printf("use the stairs\n");
    else
        printf("%d\n", a);
}