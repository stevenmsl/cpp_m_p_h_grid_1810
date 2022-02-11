#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;
namespace sol1810
{
    class Util
    {
    public:
        static void insert(set<int> &target, vector<int> &input);
        static vector<int> toVec(set<int> &set);
        static string toString(vector<int> input);
    };
}
#endif