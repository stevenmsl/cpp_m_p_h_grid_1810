

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
  private:
    unordered_map<char, tuple<int, int, char>> dirs =
        unordered_map<char, tuple<int, int, char>>{
            {'U', make_tuple(-1, 0, 'D')},
            {'D', make_tuple(1, 0, 'U')},
            {'L', make_tuple(0, -1, 'R')},
            {'R', make_tuple(0, 1, 'L')}};
    void buildGrid(
        GridMaster &gm, vector<vector<int>> &grid,
        const pair<int, int> &pos, pair<int, int> &target);

  public:
    /*
      - we shouldn't know the dimensions of
        the hidden grid and hard code the m
        as 100 per the constraints
      - we add it here so it's easier to
        debug without creating a big
        matrix
    */
    int minCost(GridMaster &gm, int m);
  };

}
#endif