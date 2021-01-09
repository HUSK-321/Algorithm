#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int arr[11][11];
    int minCost = 2147483647;

    scanf("%d", &N);

    int city[10];   // 도시 최대 수가 10이다
    for(int i = 0; i < N; i++)
        city[i] = i+1;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);
    
    // can 변수는 못가는 도시가 있었는지를 탐색 > 한 도시라도 못갔다면 비교를 안할 예정
    do {
        int cost = 0;
        bool can = true;

        for(int i = 0; i < N-1; i++){
            if(arr[city[i]][city[i+1]] == 0){   // 갈 수 없다
                can = false;
                break;
            }else{
                cost += arr[city[i]][city[i+1]];
            }
        }

        if(can && arr[city[N-1]][city[0]] != 0){    // 마지막으로 원래대로 돌아갈 수 있는지
            cost += arr[city[N-1]][city[0]];
            minCost = min(minCost, cost);
        }

    } while (next_permutation(city, city+N));     // 도시를 방문하는 가짓수를 순열 생성기로 만듬


    printf("%d\n", minCost);
}