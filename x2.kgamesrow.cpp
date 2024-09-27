#include "header.hpp"
// A competition consists of n players numbered from 0 to n - 1.

// You are given an integer array skills of size n and a positive integer k, where skills[i] is the skill level of player i. All integers in skills are unique.

// All players are standing in a queue in order from player 0 to player n - 1.

// The competition process is as follows:

// The first two players in the queue play a game, and the player with the higher skill level wins.
// After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.
// The winner of the competition is the first player who wins k games in a row.

// Return the initial index of the winning player.

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        std::list<int> q;
        for(auto skill: skills) q.push_back(skill);
        int n = skills.size();
        int res = -1;
        int count = 0;
        if(k > n) return max_element(skills.begin(), skills.end())-skills.begin();
        while(count < k){
            int p1 = q.front();
            q.pop_front();
            int p2 = q.front();
            q.pop_front();
            //if p1 wins, p1 stays at the front of the queue
            if(p1 > p2){
                q.push_front(p1);
                q.push_back(p2);
                count++;
            }
            else{
                q.push_front(p2);
                q.push_back(p1);
                count = 1;
            }

            if(count == k)
            {   
                res = find(skills.begin(), skills.end(), max(p1,p2))-skills.begin();
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> skills = {4,12,17};
    cout << s.findWinningPlayer(skills, 1) << endl;
};
