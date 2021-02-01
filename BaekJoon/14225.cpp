#include <iostream>
using namespace std;
int n;
int arr[21];
bool possible[2000001];
void Search(int num, int sum){
    if(num == n){
        possible[sum] = true;
        return;
    }
    Search(num + 1, sum + arr[num]);
    Search(num + 1, sum);
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Search(0, 0);
    for(int i = 1; i <= 2000000; i++){
        if(!possible[i]){
            printf("%d\n", i);
            return 0;
        }
    }
}