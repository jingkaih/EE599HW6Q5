#include "solution.h"

bool Solution::Maze(std::vector<std::vector<int>> maze, std::pair<int, int> start, std::pair<int, int> end)
{
  std::stack<std::pair<int, int>> stk;//there is a stack stores the coordinates of now been tring node
  stk.push(start);//push the start point
  std::pair<int, int> current = start;
  std::vector<std::vector<bool>> visited_(maze.size(),std::vector<bool> (maze[0].size(), false));//boolean matrix same size with the maze
  visited_[current.first][current.second] = true;
  bool success = false;

  while(true)
  {
    if(current.first + 1 <= maze.size() - 1 && maze[current.first + 1][current.second] == 1 && visited_[current.first + 1][current.second] == false)//if I can go down
    {
      current = std::make_pair(current.first + 1, current.second);
      stk.push(current);//then go down, push downside node into stack
      visited_[current.first][current.second] = true;//mark this node as visited
      if(current == end)//if it is destination?
      {
        success = true;
        break;
      }
    }
    else if(current.second + 1 <= maze[0].size() - 1 && maze[current.first][current.second + 1] == 1 && visited_[current.first][current.second + 1] == false)//Okay I can't go down check if I can go right
    {
      //I can go right
      current = std::make_pair(current.first, current.second + 1);
      stk.push(current);//then go right, push rightside node into stack
      visited_[current.first][current.second] = true;//mark this node as visited
      if(current == end)//if it is destination?
      {
        success = true;
        break;
      }
    }
    else if(current.second - 1 >= 0 && maze[current.first][current.second - 1] == 1 && visited_[current.first][current.second - 1] == false)//Oh! I cant go right and down, then check if i can go left
    {
      //I can go left
      current = std::make_pair(current.first, current.second - 1);
      stk.push(current);//then go left, push leftside node into stack
      visited_[current.first][current.second] = true;//mark this node as visited
      if(current == end)//if it is destination?
      {
        success = true;
        break;
      }
    }
    else if(current.first - 1 >= 0 && maze[current.first - 1][current.second] == 1 && visited_[current.first - 1][current.second] == false)//cant go left, check if I can go up
    {
      //I can go up
      current = std::make_pair(current.first - 1, current.second);
      stk.push(current);//then go up, push upside node into stack
      visited_[current.first][current.second] = true;//mark this node as visited
      if(current == end)//if it is destination?
      {
        success = true;
        break;
      }
    }
    else//i cant go down, cant go right ,cant go up, cant go left. I have to return to my caller and never try what I have tried.
    {
      stk.pop();
      current = stk.top();//back to the previous node and check if it can go along other directions


      if(current == start)//I tried every path but can't find one take me to the destination
      {
        success = false;
        break;
      }
    }
    
  }
  
  return success;
}
