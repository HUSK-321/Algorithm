#include <iostream>
using namespace std;
bool arr[1001] = {false};
int main(){
    int n, num;
    int count = 0;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &num);
        if(arr[num] == false){
            arr[num] = true;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}