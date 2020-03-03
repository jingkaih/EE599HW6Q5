# EE599HW6Q5
I used a stack to store the current path that is under exploring. 

A node is explored by checking if it can further go up, go right, go left or go up. 

If any of the four directions is available, go and visit the next node.

If there is no ways to go, which means either there is a block or out of the maze's range, go back to the previous node and check if the other 3 directions are available.

Until the stack is empty, which means the current node becomes the start point again, then it should return false.

>>The start node and the end node MUST be free cells.

# RUNTIME
Run time should be the number of all the reachable free cells from the start.