#include <iostream>
#include <stack> 
#include <vector>

int count[1000001];
int v[1000001];
int result[1000001];
using namespace std;
int main(){
    int n;
    cin >> n;
    stack<int> sta;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        count[v[i]]++;
    }
    
    for(int i = n-1; i >= 0; i--){
        while (!sta.empty() && count[sta.top()] <= count[v[i]]){
            sta.pop();
        }
        if(sta.empty()){
            result[i] = -1; //노답
        } else{
            result[i] = sta.top();
        }
        sta.push(v[i]);
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}