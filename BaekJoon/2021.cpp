#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, l; 
int start_station, end_station;   
int station[200001];
vector<int> route[200001];  // 호선 - 역 연결 벡터

int Search_Station(){
    queue<int> q;
    station[start_station] = 0;
    q.push(start_station);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == end_station)
        {
            if(station[cur] - 1 > 0)
                return station[cur] - 1;
            else
                return 0;
        }
        

        for(int i = 0; i < route[cur].size(); i++){
            int next_station = route[cur][i];

            if(station[next_station] > -1)
                continue;
            
            // 환승 else 같은 노선
            if(next_station > 100000)
                station[next_station] = station[cur] + 1;
            else
                station[next_station] = station[cur];

            q.push(next_station);
        }
    }

    return -1;
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(station, -1, sizeof(station));

    // input
    cin >> n >> l;

    for(int i = 1; i <= l; i++){
        while(true){
            int input_station;
            cin >> input_station;
            
            if(input_station == -1) break;

            route[input_station].push_back(i+100000);   // 노선
            route[i+100000].push_back(input_station);   // 노선에 해당하는 역
        }
    }
    cin >> start_station >> end_station;

    cout << Search_Station() << endl;
}