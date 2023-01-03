#include "header.hpp"
class Solution
{
public:
    int max_score = 0;
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int n = students.size();
        int m = students[0].size();

        bitset<8> is_student_assigned;
        bitset<8> is_mentor_assigned;

        calculate_score(students, mentors, is_student_assigned, is_mentor_assigned, 0);

        return max_score;
    }

    void calculate_score(vector<vector<int>> &students, vector<vector<int>> &mentors, bitset<8> &is_student_assigned, bitset<8> &is_mentor_assigned, int curr_score)
    {
        if (is_student_assigned.count() == students.size())
        {
            max_score = max(curr_score, max_score);
            return;
        }

        for (int i = 0; i < students.size(); i++)
        {
            // if a student is not assigned yet
            if (!is_student_assigned.test(i))
            {
                is_student_assigned.set(i);
                // assign a mentor to him/her
                for (int j = 0; j < mentors.size(); j++)
                {
                    if (!is_mentor_assigned.test(j))
                    {
                        is_mentor_assigned.set(j);
                        auto &st = students[i];
                        auto &mt = mentors[j];
                        int score = 0;
                        for (int k = 0; k < st.size(); k++)
                        {
                            if (st[k] == mt[k])
                                score++;
                        }
                        curr_score += score;
                        calculate_score(students, mentors, is_student_assigned, is_mentor_assigned, curr_score);
                        curr_score -= score;
                        is_mentor_assigned.reset(j);
                    }
                }
                is_student_assigned.reset(i);
            }
        }
    }
};