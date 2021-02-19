#### 题意

如题目所示

#### 思路

- 链表中双指针法的典型应用之一。设想我们分别各设置指针指向两个链表，我们当然希望这两个指针在遍历的时候可以在公共结点同时遇到，这样好判断哪个是公共结点。为了打倒这个目的，我们可以计算两个链表的长度差，让较长的链表的指针先走「距离差的步数」
  - 1⃣️如果有公共结点，因为现在两个链表的指针距离公共结点的距离一样，他们一起出发，一定可以在公共结点那里遇见
  - 2⃣️如果没有公共结点，那么他们都会走到链表末尾，指向`NULL`，此时也满足两个链表的指针指向的节点一样（都是`NULL`）

#### 代码

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        int len1 = 0, len2 = 0;
        while(cur1) {
            len1++;
            cur1 = cur1->next;
        }
        while(cur2) {
            len2++;
            cur2 = cur2->next;
        }
        int dis = abs(len1 - len2);     //统计长度差，
        ListNode *longer, *shorter;
        if(len1 > len2) {
            longer = headA;
            shorter = headB;
        }else {
            longer = headB;
            shorter = headA;
        }       //选出较长的链表，设置指针
        while(dis--) {
            longer = longer->next;
        }       //较长链表的指针先走「距离差的步数」
        while(longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }       //直到周到公共结点orNUll为止
        return longer;
    }
};
```

