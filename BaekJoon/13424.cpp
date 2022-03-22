#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int roomCount, edgeCount;
int roomDist[101][101];
int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    int testcase;
    cin >> testcase;

    while (testcase--){
        vector<int> friendRooms;
        // input
        cin >> roomCount >> edgeCount;
        for(int i = 1; i <= roomCount; i++){
            for(int j = 1; j <= roomCount; j++){
                if(i == j)
                    roomDist[i][j] = 0;
                
                else 
                    roomDist[i][j] = 999999999;
            }
        }
        for(int i = 0; i < edgeCount; i++){
            int a, b, c;
            cin >> a >> b >> c;

            roomDist[a][b] = c;
            roomDist[b][a] = c;
        }

        int friendCount;
        cin >> friendCount;
        for(int i = 0; i < friendCount; i++){
            int input;  cin >> input;

            friendRooms.push_back(input);
        }


        // floyid
        for(int via = 1; via <= roomCount; via++){
            for(int from = 1; from <= roomCount; from++){
                for(int to = 1; to <= roomCount; to++){
                    if(roomDist[from][to] > roomDist[from][via] + roomDist[via][to])
                        roomDist[from][to] = roomDist[from][via] + roomDist[via][to];
                }
            }
        }

        // search room
        int answer = 999999999;
        int minRoomidx = -1;
        for(int i = 1; i <= roomCount; i++){
            int thisRoomCost = 0;
            for(int j = 0; j < friendRooms.size(); j++){
                thisRoomCost += roomDist[i][friendRooms[j]];
            }

            if(answer > thisRoomCost){
                answer = thisRoomCost;
                minRoomidx = i;
            }
        }

        cout << minRoomidx << '\n';
    }
    
}