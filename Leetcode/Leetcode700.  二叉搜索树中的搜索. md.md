#### 题意

在二叉搜索树中查找指定节点并返回以它为根的子树，如果不存在则返回NULL

#### 思路

- 1⃣️迭代法。利用BST的性质，我们知道当前节点的值比目标值小时就往右走，反之就往左走。不存在回溯的问题，所以也不需要使用栈。
- 2⃣️递归法。思路也差不多，根据不同情况往左或往右递归即可

#### 代码（迭代法）

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = root;
        while(ans && ans->val != val)
        {
            if(ans->val < val)
                ans = ans->right;
            else
                ans = ans->left;
        }
        return ans;
    }
};
```

#### 代码（递归法）

```c++
class Solution {
public:
    TreeNode* search(TreeNode *cur, int target)
    {
        if(cur == NULL || cur-> val == target) return cur;
        if(target < cur->val)   return search(cur->left, target);
        if(target > cur->val)   return search(cur->right, target);
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *ans = search(root, val);
        return ans;
    }
};
```

