#include <iostream>
#include <algorithm>
using namespace std;
int book[10001];
int main(){
    int n, m, count = 0;
    int answer = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> book[i];
        if(book[i] < 0)
            count++;
    }
    
    sort(book, book + n);

    // 절댓값이 제일 먼 수를 1쌍으로
    // -39 -37 -29 -28 -6  2  11
    // count  = 5
    // 음수의 인덱스 0 ~ count - 1
    // 다 이동을 한 후 제일 먼 거리를 마지막에 간걸로 처리하면 된다

    for(int i = 0; i < count; i += m)
        answer += abs(book[i] * 2);

    for(int i = n - 1; i >= count; i -= m)
        answer += book[i] * 2;

    answer -= max(abs(book[0]), abs(book[n-1]));

    cout << answer << '\n';
}