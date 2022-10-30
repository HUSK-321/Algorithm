#include <iostream>
using namespace std;

int n;
int tiles[31];

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;

    if(n % 2){
        cout << "0\n";
        return 0;
    }

    tiles[0] = 1;
    tiles[2] = 3;
    tiles[4] = 11;

    for(int i = 6; i <= n; i += 2){
        tiles[i] = tiles[i-2] * tiles[2];
        for(int j = i-4; j >= 0; j -= 2){
            tiles[i] += tiles[j] * 2;
        }
    }

    cout << tiles[n] << '\n';
}