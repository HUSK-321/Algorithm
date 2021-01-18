#include <iostream>
using namespace std;
int arr[7];
int sum = 0;
int main(){
    int min = 999;
    for(int i = 0; i < 7; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 7; i++){
        if(arr[i] % 2 == 1){
            sum += arr[i];
            if(arr[i] < min)
                min = arr[i];
        }
    }

    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d", sum, min);
}