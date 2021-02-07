#include <iostream>
#include <stack> 
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n), result(n);
    stack<int> sta;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    for(int i = n-1; i >= 0; i--){
        while (!sta.empty() && sta.top() <= v[i]){
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