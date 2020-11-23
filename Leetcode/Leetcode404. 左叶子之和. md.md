#### 题意

要求对二叉树中对所有左孩子结点对值进行求和

#### 思路

其实就是二叉树的遍历问题，可以采用DFS解决，问题的关键在于如何表示当前的叶子结点是左孩子，容易想到在DFS里加个参数`isleft`表示是从父结点的左边or父结点的右边过来到当前结点。

#### 代码

```c++
class Solution {
public:
    void dfs(TreeNode* root, bool isleft, int& sum)
    {
        if(!root->left && !root->right && isleft)
        {
            sum += root->val;
            return;
        }
        if(root->left)  dfs(root->left, 1, sum);
        if(root->right) dfs(root->right, 0, sum);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        if(!root->left && !root->right) return 0;
        int ans = 0;
        dfs(root, 1, ans);
        return ans;
    }
};
```

