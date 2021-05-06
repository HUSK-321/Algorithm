#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 51

using namespace std;

int n, m;
string s;
int arr[MAX][MAX];
int ans[MAX][MAX];
bool visit[MAX][MAX];

int goX[4] = { 0, 0, 1, -1 };
int goY[4] = { 1, -1, 0, 0 };

int search(int x, int y){
    // 범위를 벗어나거나 구멍이면 실패
    if(x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == -1)
        return 0;
    // 사이클일 경우 무한대, -1, exit로 프로레스 종료
    if(visit[x][y]){
        printf("-1\n");
        exit(0);
    }   
    
    if(ans[x][y] != -1)
        return ans[x][y];
    
    visit[x][y] = true;
    ans[x][y] = 0;
    for(int i = 0; i < 4; i++){
        
        int nextX = x + (arr[x][y] * goX[i]);
        int nextY = y + (arr[x][y] * goY[i]);
        // for문의 4방향중 제일 오래할 수 있는 값을 선택
        ans[x][y] = max(ans[x][y], search(nextX, nextY) + 1);
    }
    visit[x][y] = false;

    return ans[x][y];
}

int main(){
    // 입력
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'H')
                arr[i][j] = -1;
            else
                arr[i][j] = s[j] - '0';
        }
    }
    // 계산
    memset(ans, -1, sizeof(ans));
    printf("%d\n", search(0, 0));
}