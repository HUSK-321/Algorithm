#include <iostream>
#include <string.h>
#include <vector>
#define max 10000001
using namespace std;

bool prime[max];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    // 에라토스테네스의 채
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i*i < max; i++){
        for(int j = i*i; j < max; j += i)
            prime[j] = false;
    }

    // k번째 출력
    vector<int> result;
    for(int i = 2; i < max; i++){
        if(prime[i]){
            result.push_back(i);
        }
    }

    cout << result[k-1] << '\n';
}