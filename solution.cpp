#include "solution.h"
#include <vector>
using namespace sol1810;
using namespace std;

GridMaster::GridMaster(vector<vector<int>> grid, int sx, int sy, int tx, int ty)
{
  _grid = vector<vector<int>>(grid);
  curPos = start = make_pair(sx, sy);
  target = make_pair(tx, ty);
  ROWS = grid.size();
  COLS = grid[0].size();
}

bool GridMaster::canMove(char dir)
{
  auto x = curPos.first + dirs[dir].first;
  auto y = curPos.second + dirs[dir].second;

  return x >= 0 && x < ROWS && y >= 0 && y < ROWS && _grid[x][y] >= 1;
}
int GridMaster::move(char dir)
{
  if (canMove(dir))
  {
    curPos.first = curPos.first + dirs[dir].first;
    curPos.second = curPos.second + dirs[dir].second;
    return _grid[curPos.first][curPos.second];
  }
  return -1;
}
bool GridMaster::isTarget()
{
  return curPos == target;
}
