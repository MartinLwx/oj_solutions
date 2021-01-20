#### 题意

根据前序遍历和中序遍历重建二叉树

#### 思路

- 递归法。树是递归定义的，所以重建二叉树也是用的递归法
  - 前序遍历是：根左右，区间的第一个元素就是根
  - 中序遍历是：左根右
  - 每一次根据前序遍历的根节点的信息在中序遍历中定位「根」，将中序遍历分为`[左子树，根， 右子树]`，递归建立二叉树就好

#### 代码

```c++
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR) {
        if(preL > preR) {
            return NULL;
        }
        int pos = 0;
        int root_val = preorder[preL];
        TreeNode* root = new TreeNode(root_val);

        for(pos=inL;pos<inR;pos++) {
            if(inorder[pos] == root_val) {
                break;
            }
        }
        int numLeft = pos - inL;
        root->left = build(preorder, preL + 1, preL + numLeft, inorder, inL, pos - 1);
        root->right = build(preorder, preL + numLeft + 1, preR, inorder, pos + 1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return root;
    }
};
```

