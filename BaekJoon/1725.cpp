#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int arr[1000010];
stack<int> sta;
int n, result = 0, w, h;
int main(){
    // 속도 향상
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    // 스택을 이용해서 문제풀이
    // 스택에 히스토그램 인덱스값(1부터 시작)을 계속 넣는다 = 이게 이전 위치
    // 만약 현재 위치(i)가 이전 위치(스택에 있음)보다 작다면
    // 스택에서 현재 위치(i)보다 작은 값이 나올때 까지 계속 빼낸다
    // 그걸 계속 하면서 높이, 넓이를 구해 계속 max로 비교한다
    // 틀린 이유 : for문에서 n=1을 하지 않았다
    //             저걸 해줘야 마지막 직 사각형을 볼 수 있다
    // 안하면 10 20 30 40 50 같이 계속 오르는 애들이 0이 나온다
    sta.push(0);
    for(int i = 1; i <= n+1; i++){
        while(arr[i] < arr[sta.top()] && !sta.empty()){
            h = arr[sta.top()];
            sta.pop();
            w = i - sta.top()-1;    // i-1이 지금 제일 높은 히스토그램이다
            result = max(result, h*w);
        }
        sta.push(i);
    }

    cout << result << '\n';
}