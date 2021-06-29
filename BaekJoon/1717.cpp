#include <iostream>
using namespace std;
int parent[1000001];

int FindParent(int x){
    if(x == parent[x])
        return x;

    return parent[x] = FindParent(parent[x]);
}

void Merge(int x, int y){
    x = FindParent(x);
    y = FindParent(y);

    if(x == y)
        return;
    else
        parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        parent[i] = i;
    
    while(m--){
        int operand, a, b;
        cin >> operand >> a >> b;

        if(operand == 0){
            Merge(a, b);
        } else{
            if(FindParent(a) == FindParent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}