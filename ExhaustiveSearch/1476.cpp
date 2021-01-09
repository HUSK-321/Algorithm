#include <iostream>

int E, S, M;

int CalculateYear(){
    int result = 1;

    while(true){
        if((result - E)%15 == 0 && (result - S)%28 == 0 && (result - M)%19 == 0)
            return result;
        result++;
    }
}

int main() {
    scanf("%d %d %d", &E, &S, &M);

    printf("%d", CalculateYear());
}