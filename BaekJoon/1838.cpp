#include <iostream>
#include <algorithm>
using namespace std;
int arr[500001];
int main(){
    int n, i;
    int flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for(i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(arr[j], arr[j+1]);
            } 
        }
        if(flag == 0)
            break;
    }

    printf("%d", i);
}