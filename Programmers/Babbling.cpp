#include <string>
#include <vector>
using namespace std;

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to){
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length() + 1;
    }
    return str;
}

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> canTalk = {"aya", "ye", "woo", "ma"};

    for(auto& word : babbling){
        for(const auto& can : canTalk){
            ReplaceAll(word, can, "");
        }
        if(word.length())   continue;
        answer++;
    }


    return answer;
}