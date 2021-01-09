#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, result = 0;
    int arr[8];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+N);          // algorithm에 있는 정렬

    do {
       int sum = 0;     // 초기화 안하면 값이 누적
       for(int i = 0; i < N-1; i++) {
        sum += abs(arr[i] - arr[i+1]);
       }
       result = max(result, sum);
    } while (next_permutation(arr, arr+N)); //배열 모든 원소로 순열을 만들때 까지

    printf("%d\n", result);
}