#include <iostream>
using namespace std;
int main(){
    int arr[10];
    int res = 0;
    int where = 1;
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > res){
            res = arr[i];
            where = i+1;
        }
    }
    printf("%d\n", res);
    printf("%d\n", where);
}