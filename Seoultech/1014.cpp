#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coin;
vector<int> comma_index;
int n;
//int dp[1000010];
string s;

int main(){
    // input
    getline(cin, s);
    // split
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ','){
            comma_index.push_back(i);
        }
    }
    int temp_index = 0;
    for(int i = 0; i < comma_index.size(); i++){
        int comma = comma_index[i];
        int number = stoi(s.substr(temp_index, comma));
        temp_index = comma+2;

        coin.push_back(number);
    }
    // input
    cin >> n;
    vector<int> dp(n+1);
    for(int i = 0; i < n+1; i++){
        dp[i] = 999999999;
    }

    // solve
    dp[0] = 0;
    for(int i = 0; i < coin.size() ; i++){
        for(int j = coin[i]; j <= n; j++){
            dp[j] = min(dp[j], dp[j-coin[i]] + 1);
        }
    }

    cout << dp[n];

    return 0;
}