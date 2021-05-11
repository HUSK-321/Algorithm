#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int map[125][125];
int dist[125][125];
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

priority_queue <pair<int, pair<int, int>>> pq;     // <cost, <x, y>>

int main(void){
    int n;
    int test = 0;
    int here_x, here_y, cost;
    int there_x, there_y, there_cost;
    
    while(1){
        test++;
        scanf("%d", &n);
        if(n == 0)
            return 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = -1;
                
            }
        }
            
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &map[i][j]);
            }
        }
        
        dist[0][0] = map[0][0];
        pq.push(make_pair(-map[0][0],make_pair(0, 0)));
        
        while(!pq.empty()){
            here_x = pq.top().second.first;
            here_y = pq.top().second.second;
            cost = -pq.top().first;
            
            pq.pop();
                    
            if(dist[here_x][here_y] < cost)
                continue;
            
            for(int i=0; i<4; i++){
                there_x = here_x + x[i];
                there_y = here_y + y[i];
                there_cost = cost + map[there_x][there_y];
                
                if(there_x < 0 || there_x >=n || there_y < 0 || there_y >=n)
                    continue;
                
                if(dist[there_x][there_y] == -1){
                    dist[there_x][there_y] = there_cost;
                    
                    pq.push(make_pair(-there_cost, make_pair(there_x, there_y)));
                }
                else if(there_cost < dist[there_x][there_y]){
                    dist[there_x][there_y] = there_cost;
                    pq.push(make_pair(-there_cost, make_pair(there_x, there_y)));
                }
                    
            }
                    
        }
        printf("Problem %d: %d\n", test, dist[n-1][n-1]);
    }
    
}