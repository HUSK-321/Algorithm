#include <iostream>
using namespace std;

int area[101][101];
int main(){
    int count = 0;

    for(int i = 0; i < 4; i++){
        int lx, ly, hx, hy;
        scanf("%d %d %d %d", &lx, &ly, &hx, &hy);
        for(int j = lx; j < hx; j++){
            for(int k = ly; k < hy; k++){
                area[j][k] = 1;
            }
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(area[i][j] == 1)
                count++;
        }
    }
    printf("%d", count);
}