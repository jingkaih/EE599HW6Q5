#include <iostream>
#include "src/lib/solution.h"

int main()
{
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
    bool result = solution.Maze(thismaze, start, end);
    std::cout<< result;

    return EXIT_SUCCESS;
}