#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1810;

/*
Input: grid = [[2,3],[1,1]], r1 = 0, c1 = 1, r2 = 1, c2 = 0
Output: 2
*/
tuple<vector<vector<int>>, int, int, int, int, int> testfixture1()
{
  auto grid = vector<vector<int>>{{2, 3}, {1, 1}};
  return make_tuple(grid, 0, 1, 1, 0, 2);
}

/*
Input: grid = [[0,3,1],[3,4,2],[1,2,0]], r1 = 2, c1 = 0, r2 = 0, c2 = 2
Output: 9
*/
tuple<vector<vector<int>>, int, int, int, int, int> testfixture2()
{
  auto grid = vector<vector<int>>{{0, 3, 1}, {3, 4, 2}, {1, 2, 0}};
  return make_tuple(grid, 2, 0, 0, 2, 9);
}

/*
Input: grid = [[1,0],[0,1]], r1 = 0, c1 = 0, r2 = 1, c2 = 1
Output: -1
*/
tuple<vector<vector<int>>, int, int, int, int, int> testfixture3()
{
  auto grid = vector<vector<int>>{{1, 0}, {0, 1}};
  return make_tuple(grid, 0, 0, 1, 1, -1);
}

void test1()
{
  auto f = testfixture1();
  auto grid = get<0>(f);
  auto gm = GridMaster(grid, get<1>(f), get<2>(f), get<3>(f), get<4>(f));
  int m = max(grid.size(), grid[0].size());
  Solution sol;
  auto result = sol.minCost(gm, m);

  cout << "Test 1 - expect to see "
       << to_string(get<5>(f)) << ": " << to_string(result) << endl;
}

void test2()
{
  auto f = testfixture2();
  auto grid = get<0>(f);
  auto gm = GridMaster(grid, get<1>(f), get<2>(f), get<3>(f), get<4>(f));
  int m = max(grid.size(), grid[0].size());
  Solution sol;
  auto result = sol.minCost(gm, m);

  cout << "Test 2 - expect to see "
       << to_string(get<5>(f)) << ": " << to_string(result) << endl;
}

void test3()
{
  auto f = testfixture3();
  auto grid = get<0>(f);
  auto gm = GridMaster(grid, get<1>(f), get<2>(f), get<3>(f), get<4>(f));
  int m = max(grid.size(), grid[0].size());
  Solution sol;
  auto result = sol.minCost(gm, m);

  cout << "Test 3 - expect to see "
       << to_string(get<5>(f)) << ": " << to_string(result) << endl;
}

void testGridMaster()
{
  auto f = testfixture1();
  auto gm = GridMaster(get<0>(f), get<1>(f), get<2>(f), get<3>(f), get<4>(f));

  auto result = gm.canMove('U');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('D');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('L');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('R');
  cout << (result ? "true" : "false") << endl;
  auto cost = gm.move('L');
  cout << to_string(cost) << endl;
  result = gm.isTarget();
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('U');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('D');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('L');
  cout << (result ? "true" : "false") << endl;
  result = gm.canMove('R');
  cout << (result ? "true" : "false") << endl;
  cost = gm.move('D');
  cout << to_string(cost) << endl;
  result = gm.isTarget();
  cout << (result ? "true" : "false") << endl;
  cost = gm.move('L');
  cout << to_string(cost) << endl;
  cost = gm.move('R');
  cout << to_string(cost) << endl;
}

main()
{
  test1();
  test2();
  test3();
  // testGridMaster();

  return 0;
}