#### 题意

就是题目的字面意思

#### 思路

- 1⃣️不修改链表结构的话只能从头往后遍历，而输出是反的，结合栈的特性，可以利用栈来实现。我这里用的是`vector + reverse()`
- 2⃣️遍历顺序和输出顺序相反 + 用到栈。还可以联想到递归

#### 代码（栈）

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* cur = head;
        vector<int> ans;
        while(cur != NULL) {
            ans.emplace_back(cur->val);
            cur = cur->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### 代码（递归）

```c++
class Solution {
public:
    vector<int> ans;
    void dfs(ListNode* cur) {
        if(cur->next == NULL) {
            ans.emplace_back(cur->val);
            return;
        }
        dfs(cur->next);
        ans.emplace_back(cur->val);
    }
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL) {
            return {};
        }
        dfs(head);
        return ans;
    }
};
```

