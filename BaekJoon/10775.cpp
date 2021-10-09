#include <iostream>
using namespace std;

int g, p, gNum, ans = 0;
int gate[100001];

int FindParent(int x){
    if(x == gate[x])
        return x;
    else 
        return gate[x] = FindParent(gate[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    gate[x] = y;
}

int main(){
    scanf("%d", &g);
    scanf("%d", &p);

    for(int i = 1; i <= g; i++)
        gate[i] = i;
    
    for(int i = 0; i < p; i++){
        scanf("%d", &gNum);

        int root = FindParent(gNum);

        if(root == 0){
            break;
        } else {
            ans++;
            Merge(root, root-1);
        }
    }

    printf("%d\n", ans);
}