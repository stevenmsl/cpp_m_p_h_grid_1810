#include <vector>
#include <queue>
#include <set>
#include <iterator>
#include <functional>
#include "util.h"

using namespace sol1810;

/*
  - insert a vec into a set
  - set might have elements in it already
*/
void Util::insert(set<int> &target, vector<int> &input)
{
    copy(input.begin(), input.end(), inserter(target, target.end()));
}

vector<int> Util::toVec(set<int> &set)
{
    return vector<int>(set.begin(), set.end());
}

string Util::toString(vector<int> input)
{
    string result = "[";
    for (auto e : input)
    {
        result += to_string(e);
        result += ",";
    }
    /* remove the last comma */
    if (result.size() > 1)
        result.pop_back();
    result += "]";
    return result;
}
