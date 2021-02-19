#### 题意

如题所示

#### 思路

- 二叉树的深度是一个老生常谈的问题了，不管是先序遍历，中序遍历还是后序遍历，都只要多加一个深度信息`level`，和全局的深度`depth`进行比较就可以直到二叉树的深度了
- 因为这三个遍历我们都能访问到所有的节点，所以我们肯定也是能够访问到最深的节点从而得到深度的

#### 代码

```c++
class Solution {
public:
    int depth = 0;
    void get_depth(TreeNode* root, int level) {
        if(root) {
            get_depth(root->left, level + 1);
            if(level > depth) {
                depth = level;
            }
            get_depth(root->right, level + 1);
        }
    }
    int maxDepth(TreeNode* root) {

        get_depth(root, 1);
        return depth;
    }
};
```

