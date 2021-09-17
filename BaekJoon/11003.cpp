#include <iostream>
#include <deque>
using namespace std;

int numbers[5000001];
int n, l;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    deque<pair<int, int> > list;

    for(int i = 0; i < n; i++){
        if(!list.empty() && list.front().second < i - l + 1)
            list.pop_front();

        while(!list.empty() && list.back().first > numbers[i]){
            list.pop_back();
        }
        
        list.push_back(make_pair(numbers[i], i));
        cout << list.front().first << " ";
    }
    cout << '\n';
}
/*
1 5 2 3 6 2 3 7 3 5 2 6

D(i) = A(i - l + 1) ~ A(i)
범위 = 윈도우가 l이란 뜻
*/