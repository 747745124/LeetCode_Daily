#include "header.hpp"
bool solution(string inputString)
{
    if (inputString.size() == 1)
        return true;

    for (int i = 0; i < inputString.size() / 2; i++)
    {
        if (inputString[i] == inputString[inputString.size() - i])
            continue;
        else
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    string inputString = "aabaa";
    cout << solution(inputString) << endl;
    return 0;
}