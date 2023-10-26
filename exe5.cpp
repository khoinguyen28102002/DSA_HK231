#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
        dir = 0;
    }
};

bool isValid(int x, int y)
{
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

bool canEatFood(int maze[5][5], int fx, int fy)
{
    if (maze[0][0] == 0) {
        return false; 
    }
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    stack<node> stk;
    stk.push(node(0, 0));
    while (!stk.empty()) {
        node current = stk.top();
        stk.pop();
        visited[current.x][current.y] = true;
        if (current.x == fx && current.y == fy) {
            return true;
        }
        for (int i = current.dir; i < 4; i++) {
            int newX = current.x, newY = current.y;
            if (i == 0)
                newX--;
            else if (i == 1)
                newY--;
            else if (i == 2)
                newX++;
            else if (i == 3)
                newY++;
            if (isValid(newX, newY) && maze[newX][newY] == 1 && !visited[newX][newY]) {
                stk.push(node(newX, newY));
                current.dir = i + 1;
                stk.push(current);
                break;
            }
        }
    }
    return false;
}

int main()
{
    int maze[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1}
    };
  
    int fx = 1, fy = 4;
  
    bool result = canEatFood(maze, fx, fy);
    if (result) {
        cout << "There exists a path for the rat to reach the food." << endl;
    } else {
        cout << "There is no path for the rat to reach the food." << endl;
    }
  
    return 0;
}
