// 일단 10,000 이하의 소수를 모두 구해둔다
// 입렵받은 값을 1000, 100, 10, 1 4자리수로 나눈 뒤
// 각 자리수를 0~9로 바꿔본다 (첫번째 자리는 1~9)
// 바꾼 뒤 숫자가 소수라면 이동 후 count++

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define MAX 10000
bool prime[MAX];
int visited[MAX];  // 한번 방문한 수는 다시 방문할 필요가 없다
int start, finish;
int input;  // 입력값


// 4자리 문자열을 정수로 변환
int to_int(string num){
    int ret = 0;

    for(int i=0; i<4; i++){
        ret = ret * 10 + (num[i] - '0');
    }

    return ret;
}
void Search(int first){
    queue<int> q;
    q.push(first);
    visited[first] = 0;
    // 수를 문자열(배열)로 만드는게 더 편할 것 같다

    while(!q.empty()){
        int n = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            string number = to_string(n);
            for(int j = 0; j <= 9; j++){
                number[i] = j + '0';        // 0을 더하는 이유는 숫자가 문자열이 되었을때 0~9가 48~57로 변함
                int next = to_int(number);
                if(next > 1000 && prime[next] == true && visited[next] == -1){
                    visited[next] = visited[n] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    memset(prime, true, sizeof(prime)); // 배열 초기화
    // 에라토스테네스의 채 방법으로 소수가 아닌 것들은 false로 만들어둔다
    for(int i = 2; i*i < MAX; i++) {
        for(int j = i*i; j < MAX; j += i){
            prime[j] = false;
        }
    }

    scanf("%d", &input);
    while (input--){
        scanf("%d %d", &start, &finish);
        memset(visited, -1, sizeof(visited));    // 할때마다 초기화를 해줘야 한다

        Search(start);
        if(visited[finish] != -1) {               // 탐색을 통해 원하는곳까지 갈 수 있었는가?
            printf("%d\n", visited[finish]);
        } else {
            printf("Impossible\n");
        }
    }
    
}