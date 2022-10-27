#include <iostream>

using namespace std;
using ll = unsigned long long;

ll arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

ll PowerWithMod(ll x, ll y, ll mod){
    ll answer = 1;
    ll b = x % mod;
    while (y > 0){
        if(y & 1){
            answer = (answer * b) % mod;
        }
        y = y >> 1;
        b = (b * b) % mod;
    }
    return answer;
}

bool IsComposite(ll num, ll prime, ll d, ll r){
    ll x = PowerWithMod(prime, d, num);

    if(x == 1 || x == num - 1)  return false;

    for(int i = 1; i < r; i++){
        x = x * x % num;
        if(x == num - 1)    return false;
    }
    return true;
}

bool CheckPrimeByMillerRabin(ll x){
    if(x < 2)               return false;
    if(x % 2 == 0)          return false;

    ll r = 0;
    ll d = x - 1;

    while((d & 1)== 0){
        r++;
        d = d >> 1;
    }

    for(auto prime : arr){
        if(x == prime)    return true;
        if(IsComposite(x, prime, d, r))   return false;
    }
    return true;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int answer = 0;
    int numOfTestCase;  cin >> numOfTestCase;
    while (numOfTestCase--){
        ll num; cin >> num;
        if(CheckPrimeByMillerRabin(2 * num + 1))
            answer++;
    }

    cout << answer << '\n';
}