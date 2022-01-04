#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;  // 집의 수, 공유기 갯수
vector<int> house;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> c;
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;

        house.push_back(input);
    }

    sort(house.begin(), house.end());

    // solve
    int min = 1;
    int max = house[n - 1] - house[0];
    int mid;
    int answer = 0;

    while (max >= min){
        mid = (min + max) / 2;
        int wifi_count = 1;
        int prev_house = house[0];

        // search
        for(int i = 1; i < house.size(); i++){
            if(house[i] - prev_house >= mid){
                wifi_count += 1;
                prev_house = house[i];
            }
        }

        // next
        if(wifi_count >= c){
            answer = mid;
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    
    cout << answer << '\n';

}
