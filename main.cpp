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

void test1()
{
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
  testGridMaster();
  // test1();
  return 0;
}