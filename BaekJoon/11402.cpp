#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int MAXNUM = 2001;

ll n, k, m;
ll BC[MAXNUM][MAXNUM];

vector<int> GetNotationNumber(ll number, int notation){
    vector<int> answer;
    while (number > 0){
        answer.push_back(number % notation);
        number /= notation;
    }
    return answer;
}

ll BinomialCoefficient(int n, int k){
    if(n < k)       return 0;
    if(n / 2 < k)   k = n - k;

    ll& result = BC[n][k];
    if(result != -1)    return result;
    if(k == 0)          return result = 1;
    if(k == 1)          return result = n;

    return result = (BinomialCoefficient(n-1, k-1) + BinomialCoefficient(n-1, k)) % m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(BC, -1, sizeof(BC));

    cin >> n >> k >> m;

    ll answer = 1;

    auto nToMNotation{ GetNotationNumber(n, m) };
    auto kToMNotation{ GetNotationNumber(k, m) };

    auto minSize{ min(nToMNotation.size(), kToMNotation.size()) };
    int forLoopIndex = static_cast<int>(minSize);

    for(int i = 0; i < forLoopIndex; i++){
        answer *= BinomialCoefficient(nToMNotation[i], kToMNotation[i]);
        answer %= m;
    }

    cout << answer << '\n';
}