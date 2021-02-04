#include <iostream>
using namespace std;

int n, m;
int arr[9] = {0,};
bool visit[9] = {0,};
void Search(int now, int count){
    // 1~n까지 숫자중 m개 출력
    if(count == m){ // 다 탐색하면 출력하기
        for(int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i = now; i <= n; i++){
        arr[count] = i;
        Search(i,count+1);    // count++과 같은 효과
    }
}
int main(){
    scanf("%d %d", &n, &m);
    Search(1,0);
}