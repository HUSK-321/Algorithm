#include <iostream>
#include <algorithm>
using namespace std;
int arr [101];
int main(){
    int n, m, result;
    int temp = -100;
    // n개의 카드가 있는데 이걸로 m과 가장 유사하게
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // for문 3개? 가능?
    for(int i = 0; i< n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                result = 0;
                result = arr[i] + arr[j] + arr[k];
                if(result <= m)
                    temp = max(result, temp);
            }
        }
    }
    printf("%d\n", temp);
}