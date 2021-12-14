#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<std::vector<string> > product(const std::vector<std::vector<string> > &lists)
{
    std::vector<std::vector<string> > result;
    if (std::find_if(begin(lists), end(lists),
                     [](auto e) -> bool
                     { return e.size() == 0; }) != end(lists))
    {
        return result;
    }
    for (auto &e : lists[0])
    {
        result.push_back({e});
    }
    for (size_t i = 1; i < lists.size(); ++i)
    {
        std::vector<std::vector<string> > temp;
        for (auto &e : result)
        {
            for (auto f : lists[i])
            {
                auto e_tmp = e;
                e_tmp.push_back(f);
                temp.push_back(e_tmp);
            }
        }
        result = temp;
    }
    return result;
}
int main()
{
    std::vector<std::vector<string> > lists{{"A", "B", "C"}, {"A", "B", "C"}, {"A", "B", "C"}};
    std::vector<std::vector<string> > result = product(lists);
    for (auto &e : result)
    {
        for (auto f : e)
        {
            std::cout << f << " ";
        }
        std::cout << std::endl;
    }
}