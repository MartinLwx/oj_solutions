#### 题意

将一个二叉树转换为它的镜像树

#### 思路

- 很容易想到镜像树是要交换左右孩子，而且是递归式的，也就是说还要对它的左孩子和右孩子这么做。
- 本质是对遍历算法的理解，显然这里是用后序遍历比较合理的，后序遍历是左右根的顺序，也就是遍历到当前根结点的时候左右子树都已经遍历过也处理好了（翻转为镜像）

#### 代码

```c++
class Solution {
public:
    void post_order(TreeNode* root) {
        if(root) {
            post_order(root->left);
            post_order(root->right);
            swap(root->left, root->right);
        } 
    } 
    TreeNode* mirrorTree(TreeNode* root) {
        post_order(root);
        return root;
    }
};
```

