

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
namespace sol1810
{

  class GridMaster
  {
  private:
    vector<vector<int>> _grid;
    pair<int, int> curPos;
    pair<int, int> start;
    pair<int, int> target;
    int ROWS;
    int COLS;
    unordered_map<char, pair<int, int>> dirs = unordered_map<char, pair<int, int>>{
        {'U', make_pair(-1, 0)},
        {'D', make_pair(1, 0)},
        {'L', make_pair(0, -1)},
        {'R', make_pair(0, 1)}};

  public:
    GridMaster(vector<vector<int>> grid, int sx, int sy, int tx, int ty);
    bool canMove(char dir);
    int move(char dir);
    bool isTarget();
  };

  class Solution
  {
  public:
  };

}
#endif