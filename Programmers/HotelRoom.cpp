#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> hotelRoom;

long long FindAvailableRoomNumber(long long roomNumber){
    if(hotelRoom.find(roomNumber) == hotelRoom.end())
        return roomNumber;
    return hotelRoom[roomNumber] = FindAvailableRoomNumber(hotelRoom[roomNumber]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i = 0; i < room_number.size(); i++){
        auto availableRoom{ FindAvailableRoomNumber(room_number[i]) };
        answer.push_back(availableRoom);
        hotelRoom[availableRoom] = availableRoom + 1;
    }
    
    return answer;
}