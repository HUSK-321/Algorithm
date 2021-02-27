#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char arr[16];
int l, c;

void func(string s, int count, int m, int j){
    // 최소 1개의 모음 (a,i,u,e,o) 이 들어가야 한다
    // 자음도 2개나 들어가야 한다고 한다
    // 결과 출력
    if(s.size() == l && m >= 1 && j >= 2){
        cout << s << '\n';
        return;
    }
    // 조건이 아니라면 다음 순열
    for(int i = count; i < c; i++){
        if(arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'e' || arr[i] == 'o')
            func(s + arr[i], i+1, m + 1, j);
        else
            func(s + arr[i], i+1, m, j + 1);
    }
}

int main(){
    cin >> l >> c;
    for(int i = 0; i < c; i++)
        cin >> arr[i];
    
    sort(arr, arr+c);

    func("", 0, 0, 0);
    
    return 0;
}