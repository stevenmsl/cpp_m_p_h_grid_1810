#include "solution.h"
#include <vector>
#include <queue>
using namespace sol1810;
using namespace std;

/*takeaways
  - use DFS to build the grid and then BFS to visit the grid
    with the help of minHeap to find the minimum cost
  - why we need a much bigger matrix (2mx2m) when building the grid?
    - use textfixture1 as an example, and set m=2 for simplicity :
      2 3
      1 1
    - robot's start point is (0,0). The grid we will build
      x x x x
      x x x x
      x x 2 3
      x x 1 1
    - robot's start point is (2,2). The grid we will build
      x x x x
      x 2 3 x
      x 1 1
      x x x x
*/

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

void Solution::buildGrid(
    GridMaster &gm, vector<vector<int>> &grid,
    const pair<int, int> &pos, pair<int, int> &target)
{
  if (gm.isTarget())
    target = pos;

  for (auto e : dirs)
  {
    auto dir = e.first;
    int dx, dy;
    char oppDir; // opposite direction
    tie(dx, dy, oppDir) = e.second;
    int x = pos.first + dx;
    int y = pos.second + dy;

    /*
      - grid[x][y] == -1 serves the same purpose
        as denoting a position has been visited
      - how is the start's cost updated? It's
        updated by its neighbor
        start->neighbor; neighbor->start
    */
    if (gm.canMove(dir) && grid[x][y] == -1)
    {
      grid[x][y] = gm.move(dir);
      auto newPos = make_pair(x, y);
      buildGrid(gm, grid, newPos, target);
      /*
        - move the robot back to where it was
        - we need to reset it back before
          visiting next neighbor as robot
          is currently in one this position's
          neighbor
      */
      gm.move(oppDir);
    }
  }
}

int Solution::minCost(GridMaster &gm, int m)
{
  /*
     - pick the spot (right in the center)
       to allow enough room for the grid
       to grow in the direction needed
       while building it
     - the grid will grow left-and-up if the
       robot's start position is in the right
       bottom corner
  */
  const auto start = make_pair(m, m);
  auto target = make_pair(2 * m, 2 * m);
  /* 2mx2m grid
     - make sure there is enough room to
       build the grid however you need
  */
  auto grid = vector<vector<int>>(2 * m, vector<int>(2 * m, -1));

  buildGrid(gm, grid, start, target);

  auto visited = vector<vector<bool>>(2 * m, vector<bool>(2 * m, false));
  auto minHeap = priority_queue<tuple<int, pair<int, int>>,
                                vector<tuple<int, pair<int, int>>>,
                                greater<>>();
  /* start cost is zero */
  minHeap.push(make_tuple(0, start));

  /* BFS
     - at first I was confused why can you be
       so sure that the next node you pick
       from the queue will form a valid
       path as we use a minHeap here
     - we accumulate the cost along the way
       - start->4->2 is same as start->6
       - so two moves from the start
         costs 4+2 is the same as one
         move costs 6
       - you can also think of keep
         replacing start's neighbor
         with a more expensive one
  */

  while (!minHeap.empty())
  {
    auto t = minHeap.top();
    auto cost = get<0>(t);
    const auto pos = get<1>(t);
    minHeap.pop();

    if (pos == target)
      return cost;
    if (visited[pos.first][pos.second])
      continue;
    visited[pos.first][pos.second] = true;

    for (auto d : dirs)
    {
      auto dir = d.second;
      auto dx = get<0>(dir);
      auto dy = get<1>(dir);
      const auto x = pos.first + dx;
      const auto y = pos.second + dy;
      /* out-of-bound */
      if (x < 0 || x == 2 * m || y < 0 || y == 2 * m)
        continue;
      if (visited[x][y] || grid[x][y] == -1)
        continue;
      /* make sure you accumulate the cost! */
      minHeap.push(make_tuple(cost + grid[x][y], make_pair(x, y)));
    }
  }

  return -1;
}