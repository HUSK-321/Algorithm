#include <iostream>
using namespace std;

int colorCount, selectCount;
int answer = 0;
int selectMap[1001][1001];
const int mod = 1000000003;
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> colorCount;
    cin >> selectCount;

    // init array
    for(int i = 0; i <= colorCount; i++){
        selectMap[i][1] = i;
        selectMap[i][0] = 1;
    }

    // solve
    for(int n = 2; n <= colorCount; n++){
        for(int k = 2; k <= selectCount; k++){
            selectMap[n][k] = (selectMap[n-1][k] + selectMap[n-2][k-1]) % mod;
        }
    }

    // print
    // if draw colorCount position -> 1, colorCount-1 should not draw -> 2~colorCount-2
    selectMap[colorCount][selectCount] = (selectMap[colorCount-1][selectCount] + selectMap[colorCount-3][selectCount-1]) % mod;
    cout << selectMap[colorCount][selectCount] << '\n';
}