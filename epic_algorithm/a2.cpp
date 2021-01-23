#include <iostream>
using namespace std;

int arr[20021];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp <= 0){
            temp = -temp;
            arr[temp]++;
        } else {
            temp += 10000;
            arr[temp]++;
        }
    }

    for(int i = 0; i < 20021; i++){
        if(arr[i]){
            int num = i -10000;
            printf("%d %d\n", num, arr[i]);
        }
    }
    
}