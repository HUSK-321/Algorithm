#include <iostream>
#include <algorithm>
using namespace std;
bool prime[10001];
int main(){
    for(int i = 2; i <= 10000; i++)
        prime[i] = true;

    for(int i = 2; i * i < 10001; i++){
        for(int j = i*i; j < 10001; j += i)
            prime[j] = false;
    }

    int n, m;
    cin >> n >> m;

    int sum = 0;    int x = 10001;
    for(int i = n; i <= m; i++){
        if(prime[i] == true){
            x = min(x, i);
            sum += i;
        }
    }
    if(!sum)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << x << '\n';
}