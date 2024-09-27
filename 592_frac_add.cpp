#include "header.hpp"
class Solution {
public:
    struct frac{
        int upper;
        int lower;
    };

    string fractionAddition(string expression) {
        frac res;
        int upper = 1;
        int lower = 1;

        res.upper = upper;
        res.lower = lower;


        for(int i = 0; i < expression.length(); i++){
            auto ch = expression[i];
            
            frac op;
            string tmp = "";

            if(ch=='+')
                i++;
            
            while(expression[i]!='/'){
                tmp+=expression[i];
                i++;
            }

            op.upper = ch=='-'?-1:1 * stoi(tmp);
            i++;
            tmp = "";

            while(isalnum(expression[i])){
                tmp+=expression[i];
                i++;
            }

            op.lower = stoi(tmp);
            res = add_sub(res,op);
        }

        res = add_sub(res, frac(-1,1));
        int gcd = abs(__gcd(res.upper,res.lower));
        res.upper/=gcd;
        res.lower/=gcd;
        
        return to_string(res.upper) + '/' + to_string(res.lower);
    }

    frac add_sub(frac num1, frac num2){
        frac res;
        int common_lower = lcd(num1.lower, num2.lower);
        int upper = num1.upper*(common_lower/num1.lower) + num2.upper*(common_lower/num2.lower);
        
        res.lower = common_lower;
        res.upper = upper;
        return res;
    }

    int lcd(int num1, int num2){
        return abs(num1*num2)/__gcd(num1,num2);
    }


};


int main(){
    Solution s;
    cout << s.fractionAddition("-1/2+1/2") << endl;
    cout << s.fractionAddition("-1/2+1/2+1/3") << endl;
    cout << s.fractionAddition("1/3-1/2") << endl;
    return 0;
}