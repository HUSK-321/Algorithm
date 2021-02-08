#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001];
long long temp[100001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    temp[0] = arr[0];
    long long result = temp[0];
    for(int i = 1; i < n; i++){
        temp[i] = max(temp[i-1] + arr[i], arr[i]);
        result = max(result, temp[i]);
    }

    printf("%d\n", result);
}