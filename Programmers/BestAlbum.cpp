#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> genresTimes;
    unordered_map<string, map<int, int>> musicInfo; // genres, index, playtimes

    // make unordered map
    for(int i = 0; i < genres.size(); i++){
        genresTimes[genres[i]] += plays[i];
        musicInfo[genres[i]][i] = plays[i];
    } 

    // find most played genres
    // and find most played music in that genres

    // 1. sort genres by played time
    vector<pair<string, int>> genresPlayTimes(genresTimes.begin(), genresTimes.end());
    sort(genresPlayTimes.begin(), genresPlayTimes.end(), cmp);

    for(int i = 0; i < genresPlayTimes.size(); i++){
        // search most played genres
        string curGenre = genresPlayTimes[i].first;
        
        // find two music in this genres
        for(int genCount = 0; genCount < 2; genCount++){
            int playTime = -1, index = -1;
            for(auto music : musicInfo[curGenre]){
                if(playTime < music.second){
                    playTime = music.second;
                    index = music.first;
                }
            }

            if(index == -1) continue;

            answer.push_back(index);
            musicInfo[curGenre].erase(index);
        }
    }

    return answer;
}