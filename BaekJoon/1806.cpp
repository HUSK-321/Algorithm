#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> num(n);
    for(int i = 0; i < n; i++)
        cin >> num[i];
    
    int left = 0, right = 0, sum = num[0];
    int ans = 999999999;
    while(right >= left && right < n){
        if(sum == s){
            ans = min(ans, right - left + 1);
            right++;
            sum += num[right];
        }
        else if(sum > s){
            ans = min(ans, right - left + 1);
            sum -= num[left];
            left++;
        }
        else if(sum < s){
            right++;
            sum += num[right];
        } 

    }

    if(ans == 999999999)
        cout << "0\n";
    else 
        cout << ans << '\n';
}