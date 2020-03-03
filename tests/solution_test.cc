#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(FindPathShould, ReturnFalse) {
  Solution solution;
  std::vector<std::vector<int>> thismaze ={
                                              {1,1,0,0,0},
                                              {1,1,1,1,1},
                                              {0,1,0,0,1},
                                              {1,0,0,0,0},
                                              {1,1,1,1,1}
                                          };
  std::pair<int, int> start = std::make_pair(0,0);
  std::pair<int, int> end = std::make_pair(4,4);
  bool actual = solution.Maze(thismaze, start, end);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(FindPathShould, ReturnTrue) {
  Solution solution;
  std::vector<std::vector<int>> thismaze ={
                                              {1,1,0,0,0},
                                              {1,1,1,1,1},
                                              {0,1,0,0,1},
                                              {1,0,0,0,0},
                                              {1,1,1,1,1}
                                          };
  std::pair<int, int> start = std::make_pair(0,0);
  std::pair<int, int> end = std::make_pair(2,4);
  bool actual = solution.Maze(thismaze, start, end);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}