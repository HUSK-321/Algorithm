#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int answer[1001];
int main(){
    int n;
    int result = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++){
        answer[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                answer[i] = max(answer[i], answer[j] + 1);
            }
        }
        result = max(result, answer[i]);
    }

    cout << result << '\n';
}