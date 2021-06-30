#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    string ans;

    for(int i = 2; i >= 0; i--){
        if(a[i] > b[i]){
            ans = a;
            break;
        } else if(a[i] < b[i]){
            ans = b;
            break;
        }
    }
    cout << ans[2] << ans[1] << ans[0] << '\n';
}