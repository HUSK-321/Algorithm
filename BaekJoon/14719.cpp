#include <iostream>
#include <algorithm>
using namespace std;

int w, h, l, r, answer = 0;
int height[501];

int main(){
    scanf("%d %d", &h, &w);

    for(int i = 0; i < w; i++)
        scanf("%d", &height[i]);

    for(int i = 1; i < w-1; i++) {
        l = 0;
        r = 0;
        for (int j = 0; j < i; j++)
            l = max(l, height[j]);
        
        for (int j = i + 1; j < w; j++)
            r = max(r, height[j]);
        
        answer += max(0, min(l, r) - height[i]);
    }
    printf("%d\n", answer);
}