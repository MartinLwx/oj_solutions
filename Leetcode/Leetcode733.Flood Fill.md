#### 题意

给定一个二维数组和初始坐标，要求从上下左右四个方向进行扩展，如果当前扩展的格子的颜色不等于初始坐标的颜色，那么就进行更改

#### 思路

- 1️⃣四个方向扩展很自然地想到了广度优先搜索BFS，队列中存储坐标，每当取出一个坐标就往上下左右四个方向上进行扩展，并对扩展的坐标进行如下判断：是否越界——>是否不等于初始坐标的颜色，通过判断之后就修改并将节点入队。最后队列中没有队列就表示处理完。 

- 2⃣️另一个想法是用深度优先搜索DFS，同样是往四个方向上进行扩展，关于是否满足修改的条件可以在要进入下一层递归函数的时候就进行判断。

- 注意⚠️

  - **如果起点的颜色就和目标颜色一样，就可以直接返回。**第一次提交发现了一个死循环。因为一开始我是直接对扩展的状态进行修改然后入队，那么如果要修改的颜色和起点颜色一样，那么就会出现重复入队重复处理的死循环（如下所示⬇️）。➡️于是就开了一个vis数组来标志节点是否已经修改过。虽然过了，但是效率表现不佳。看了题解发现只要一开始判断颜色一致就可以返回了👀

    ```c++
    [[0,0,0],
     [0,1,1]]
    sr = 1, sc = 1, newColor = 1
    //对(1,1)处理完后，(1,2)入队，改为1。在(1,2)扩展状态的时候(1,1)又回入队
    ```

  - BFS的边界判断注意要先检查「坐标是否越界」然后再检查「对应的位置的状态」。比如扩展出来的坐标是`(-1,-1)`，如果先判断`image[-1][-1]`就会出现越界错误。解决的办法就是利用**短路求值**的特性先判断是否越界

#### BFS代码

```c++
//BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row_length = image.size();
        if(row_length == 0)   return {{}};
        int column_length = image[0].size();

        vector<vector<int>> vis;
        for(int i=0;i<row_length;i++)
        {
            vector<int> t;
            for(int j=0;j<column_length;j++)
                t.push_back(0);
            vis.push_back(t);
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] == 1;
        int init_color = image[sr][sc];
        image[sr][sc] = newColor;   
        while(!q.empty())
        {
            auto element = q.front();   q.pop();
            int x = element.first;
            int y = element.second;
            for(int i=0;i<4;i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >=0 && new_x < row_length && new_y >=0 && new_y < column_length && image[new_x][new_y] == init_color && vis[new_x][new_y] == 0)
                {
                    image[new_x][new_y] = newColor;
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};
```

#### DFS代码

```c++
class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int init, int target)
    {
        int row_length = image.size();
        int column_length = image[0].size();
        image[x][y] = target;

        if(x-1>=0 && image[x-1][y] == init)   dfs(image, x-1, y, init, target);
        if(x+1<row_length && image[x+1][y] == init)   dfs(image, x+1, y, init, target);
        if(y-1>=0 && image[x][y-1] == init)   dfs(image, x, y-1, init, target);
        if(y+1<column_length && image[x][y+1] == init)    dfs(image, x, y+1, init, target);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row_length = image.size();
        if(row_length == 0)     return {{}};
        int column_length = image[0].size();
        int init_color = image[sr][sc];
        if(init_color == newColor)      return image;

        dfs(image, sr, sc, init_color, newColor);
        return image;
    }
};
```

