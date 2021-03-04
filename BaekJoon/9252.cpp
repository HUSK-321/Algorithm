#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a,b;
int arr[1001][1001];
string lcs[1001][1001];
int main(){
    cin >> a >> b;

    int maxA = a.size();
    int maxB = b.size();
    for(int i = 1; i <= maxA; i ++){
        for(int j = 0; j <= maxB; j++){
            // 공통부분 발견
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
                // 최대 배열값 갱신
                lcs[i][j] = lcs[i][j] + lcs[i-1][j-1] + a[i-1];
            }
            else{
                // 공통부분이 없다면 남아있는 것들 중 최대를 고름
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);

                if(lcs[i-1][j].length() > lcs[i][j-1].length())
                    lcs[i][j] = lcs[i-1][j];
                else
                    lcs[i][j] = lcs[i][j-1];
            }
                
        }
    }

    cout << arr[maxA][maxB] << '\n';
    cout << lcs[maxA][maxB] << '\n';
}