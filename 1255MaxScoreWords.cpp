#include "header.hpp"
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(const auto& ch:letters){
            freq[ch-'a']++;
        }
        return getMaxScore(words,freq,score,0);
    }

    //01 knapsack problem
    int getMaxScore(vector<string>& words, vector<int>& freq, vector<int>& score, int index){
        if(index == words.size()) return 0;

        // max score if the current word is not formed
        int maxScore = getMaxScore(words,freq,score,index+1);

        // check if the current word can be formed
        vector<int> tempFreq = freq;
        int currScore = 0;
        bool canForm = true;
        for(const auto& ch:words[index]){
            if(tempFreq[ch-'a'] == 0){
                canForm = false;
                break;
            }
            tempFreq[ch-'a']--;
            currScore += score[ch-'a'];
        }

        // if the current word can be formed, update the max score
        // maxScore = max(maxScore,currScore + getMaxScore(words,tempFreq,score,index+1));
        if(canForm){
            maxScore = max(maxScore,currScore + getMaxScore(words,tempFreq,score,index+1));
        }

        return maxScore;
    }
};