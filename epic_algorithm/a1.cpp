#include <iostream>
using namespace std;

int arr[11];
int main(){
    int count = 10;
    int how = 0;
    unsigned int num = 0;
    int i = 1;

    scanf("%d", &num);
    while(num){
        arr[i] = num % 10;
        num = num/10;
        how++;
        i++;
    }
    int temp = how;
    for(int i = 1; i <= how; i++){
        if(arr[i] != arr[temp]){
            printf("%d\n", 0);
            return 0;
        }
        temp--;
    }
    printf("%d\n", 1);
}