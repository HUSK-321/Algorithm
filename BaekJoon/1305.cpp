#include <iostream>
using namespace std;
int n, pi[1000001];
char arr[1000001];

int main(){
    cin >> n >> arr;    // 이렇게 해도 받아진다!

    int last = 0;
    // kmp 알고리즘 참고
    // ex) aaaaa
    // kmp 배열이 0 1 2 3 4 라서 n - kmp[n-1] 이 5 - 4가 되어 1이 나옴
    for(int i = 1; i < n; i++){
        // i 왼쪽, last 오른쪽
        // 접미사 =/= 접두사인 경우
        while(arr[i] != arr[last] && last > 0)
            last = pi[last-1];
        // 접미사== 접두사인 경우
        if(arr[i] == arr[last])
            pi[i] = ++last;
    }

    cout << n - pi[n-1];
}