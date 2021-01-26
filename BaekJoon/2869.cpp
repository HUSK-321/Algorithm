#include <iostream>
using namespace std;
int main(){
    int a,b,v,day, result = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &v);

    if(a == v){
        printf("%d\n", 1);
        return 0;
    }

    day = a - b; // 하루에 올라가는 양
    result += (v-a) / day;
    if((v-a) % day > 0)
        result++;
    
    result++;
    printf("%d\n", result);

    return 0;
}