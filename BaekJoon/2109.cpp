#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visit[10001];
int n, d, p, res = 0;
vector<pair<int, int>> arr; // 금액, 날짜

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first >= b.first;
}

int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &p, &d);
        arr.push_back(pair<int, int>(p, d));
    } 
    
    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < arr.size(); i++){
        for(int j = arr[i].second; j >= 1; j--){
            if(!visit[j]){
                visit[j] = true;
                res += arr[i].first;
                break;
            }
        }
    }

    printf("%d\n", res);
}