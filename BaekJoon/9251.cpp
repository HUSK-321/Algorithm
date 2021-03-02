#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a,b;
int arr[1001][1001];
// LCS 알고리즘
// 2차원 배열을 통해 같은 문자열을 저장한다
// 여기에 저장된 값중 최대값이 최대 공통 요소가 된다
// 열까지 해당하는 문자열, 행까지 해당하는 문자열 중
// 최대 같은 길이가 배열에 값으로 저장된다
int main(){
    cin >> a >> b;

    int maxA = a.size();
    int maxB = b.size();
    for(int i = 1; i <= maxA; i ++){
        for(int j = 0; j <= maxB; j++){
            if(a[i-1] == b[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    cout << arr[maxA][maxB] << '\n';
}