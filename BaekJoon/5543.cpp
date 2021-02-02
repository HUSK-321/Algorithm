#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int minBuger = 3000;
    int minBeverage = 3000;
    int buger[3];
    int beverage[2];
    for(int i = 0; i < 3; i++){
        scanf("%d", &buger[i]);
        minBuger = min(minBuger, buger[i]);
    }
    for(int i = 0; i < 2; i++){
        scanf("%d", &beverage[i]);
        minBeverage = min(minBeverage, beverage[i]);
    }
    printf("%d\n", (minBeverage + minBuger) - 50);
}