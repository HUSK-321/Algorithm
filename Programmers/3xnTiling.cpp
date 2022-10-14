#include <string>
#include <vector>

using namespace std;

long long tiles[5001];
const int MOD = 1000000007;

int solution(int n) {
    if(n % 2 == 1)  return 0;

    tiles[0] = 1;
    tiles[2] = 3;
    tiles[4] = 11;

    for(int i = 6; i <= n; i++){
        tiles[i] = tiles[i-2] * 3;
        for(int j = i-4; j >= 0; j = j - 2){
            tiles[i] += tiles[j] * 2;
        }
        tiles[i] %= MOD;
    }


    return static_cast<int>(tiles[n]);
}