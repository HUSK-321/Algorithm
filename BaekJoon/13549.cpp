#include <iostream>
#include <queue>
using namespace std;
#define max 100001
int isVisited[max] = {0};  // 방문한 곳을 다시 방문할 필요가 없으니 체크하기 위한 배열 (default : false)
int N, K;
int search(int N, int K) {
    int count = 0;      // 몇번만에 만났는지 체크할 변수
    queue<int> q;
    q.push(N);      // 일단 자기 위치 넣어줌

    while(true){    //계속 돌게하고 탈출 조건인 N = K를 안에 넣음
        int n = q.size();
        isVisited[N] = 1;
        for(int i = 0; i < n; i++){

            N = q.front();
            q.pop();

            if(N == K)  // 완료조건
                return isVisited[K] - 1;

            if (2*N < 100001 && isVisited[N*2] == 0){
                q.push(N*2);
                isVisited[N*2] = isVisited[N];
            }
            if (N > 0 && isVisited[N-1] == 0){
                q.push(N-1);
                isVisited[N-1] = isVisited[N] + 1;
            }
            if (N < 100001 && isVisited[N+1] == 0){
                q.push(N+1);
                isVisited[N+1] = isVisited[N] + 1;
            }
        }
    }

}
int main(){

    scanf("%d %d", &N, &K);
    printf("%d\n", search(N,K));
}
