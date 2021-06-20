#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, res = 0;
int x, y, l, r;
vector<pair<int, int>> v;

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end());

    l = v[0].first; r = v[0].second;

    for(int i = 1; i < n; i++){
        if(v[i].first > r){
            res += r - l;
            l = v[i].first;
            r = v[i].second;
        }
        else if(r < v[i].second)
            r = v[i].second;
    }

    res += r - l;

    printf("%d\n", res);
}