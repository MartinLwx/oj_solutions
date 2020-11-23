#### 题意

给矩阵A，求出转置矩阵

#### 思路

- 如果是方阵，就很好写了，只要一个双重循环就好了⬇️，如果不是方针，思想是类似的，就是把**矩阵A的列转变成行**

```c++
for(int i=0;i<row;i++)
	for(int j=0;j<column;j++)
		swap(A[i][j], A[j][i]);
```

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        if(row == 0)    return {{}};
        int column = A[0].size();
        vector<vector<int>> ans(column, vector<int>(row));   //定义转置矩阵的大小
        for(int c=0;c<column;c++)
        {
            for(int r=0;r<row;r++)
            {
                ans[c][r] = A[r][c];
            }
        }
        return ans;
    }
};
```

