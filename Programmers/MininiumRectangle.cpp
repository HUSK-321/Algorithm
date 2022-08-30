#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int cardLongSide = 0, cardShortSide = 0;
    const int cardsCount = sizes.size();
    for(int i = 0; i < cardsCount; i++)
    {
        const int weight = sizes[i][0];
        const int height = sizes[i][1];
        if (weight > height)
        {
            cardLongSide = max(cardLongSide, weight);
            cardShortSide = max(cardShortSide, height);
            continue;
        } 
        cardLongSide = max(cardLongSide, height);
        cardShortSide = max(cardShortSide, weight);
    }
    
    return answer = cardLongSide * cardShortSide;
}