#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<int> digits;
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(4);
    int n = 0;
    int len = digits.size() - 1; //len=3
    for (int i = 0; i < digits.size(); i++)
    {
        n += pow(10, len - i) * digits[i];
    }
    n++;
    vector<int> res;
    int iter = n;
    while (iter != 0)
    {
        res.push_back(iter % 10);
        iter /= 10;
    }
    reverse(res.begin(), res.end());
    //print res;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}
