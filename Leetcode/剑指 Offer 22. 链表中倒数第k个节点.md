#### 题意

返回链表的倒数第K个节点，索引从1开始

#### 思路

- 采用链表中的快慢指针法，让快的指针先走`k`步
- 如下所示⬇️

```c++
1->2->3->4  , k = 2时
//1.快指针先走2步
1->2->3->4
			^
			|
      fast
//2.快慢指针一起出发直到fast指向NULL
1->2->3->4
            ^
					  |
						fast
			^
			|
			slow
```

#### 代码

```c++
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(k--) {
            fast = fast->next;
        }   //快指针先走k步
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }   //快慢指针一起出发
        return slow;
    }
};
```

