#include <iostream>
using namespace std;

int parent[500001];
int n, m;

int FindParent(int x){
    if(x == parent[x])
        return x;
    else
        return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;
    parent[x] = y;
    return;
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        parent[i] = i;
    
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        if(FindParent(a) == FindParent(b)){
            printf("%d\n", i);
            return 0;
        }
        Merge(a, b);
    }
    printf("0\n");
    return 0;
}