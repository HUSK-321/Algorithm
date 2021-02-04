#include <iostream>
using namespace std;
bool arr[300000];
int main(){
    while(1){
        int n, count = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = n; i <= 2*n; i++)
            arr[i] = true;

        for(int i = 2; i <= 2*n; i++){
            for(int j = i + i; j <= 2*n; j += i){
                arr[j] = false;
            }
        }

        for(int i = n + 1; i <= 2 *n; i++){
            if(arr[i]){
                count++;
            }
        }
        printf("%d\n", count);
    }
}