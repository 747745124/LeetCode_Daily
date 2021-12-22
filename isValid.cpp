#include "header.hpp"

bool isValid(List<Person> ids, string str)
{

    for (Person elem : ids)
    {
        if (str.length() != 8)
            continue;

        bool beginWithABC = (str[0] == 'A') || (str[0] == 'B') || (str[0] == 'C');
        bool dobMatch = (str[2] == elem.getDob().getYear % 10);
        bool isFound = (str == elem.getIdCode());
        bool checkSum = ((stoi(str[6]) + stoi(str[7])) == 7);
        if (beginWithABC && dobMatch && isFound && checkSum)
            return true;
    }

    return false;
}