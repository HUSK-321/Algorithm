#include <iostream>
#include <algorithm>
using namespace std;
int step[301];
int result[301];
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> step[i];

    result[0] = step[0];
    result[1] = step[0] + step[1];
    result[2] = max(step[0], step[1]) + step[2];

    for(int i = 3; i < n; i++)
        result[i] = max(result[i-3] + step[i-1], result[i-2]) + step[i];
    
    cout << result[n-1] << '\n';
}