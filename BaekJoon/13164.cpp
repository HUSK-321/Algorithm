#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
int kids[300001];

int main(){
    // init 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> k;

    if(k == n){
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < n; i++)
        cin >> kids[i];
    
    // solve
    vector<int> differences;
    for(int i = 0; i < n-1; i++)
        differences.push_back(abs(kids[i] - kids[i+1]));
    
    sort(differences.begin(), differences.end());

    int answer = 0;
    for(int i = 0; i < n-k; i++)
        answer += differences[i];

    cout << answer << '\n';
}