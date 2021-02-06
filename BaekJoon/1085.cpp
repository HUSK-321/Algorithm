#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int temp1 = min(w-x, h-y);
    int temp2 = min(x,y);
    printf("%d\n", min(temp1, temp2));
}