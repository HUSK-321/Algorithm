#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, c;
int arr[10010];
pair<int, int> candy[5001]; // 칼로리, 가격 순
double m, p;

int main(){
    while (true){
        memset(arr, 0, sizeof(arr));
        // 돈 : m, n : 사탕의 종류
        cin >> n >> m;

        if(n == 0 && (m < 0.001))
            break;

        
        for(int i = 0; i < n; i++){
            cin >> c >> p;
            candy[i] = make_pair(c, (int)(p * 100 + 0.5));
        }

        
        int intM = (int)(m * 100 + 0.5);
        for(int i = 0; i < n; i++){
            for(int j = candy[i].second; j <= intM; j++)
                arr[j] = max(arr[j], arr[j - candy[i].second] + candy[i].first);
        }

        cout << arr[intM] << '\n';
    }
}