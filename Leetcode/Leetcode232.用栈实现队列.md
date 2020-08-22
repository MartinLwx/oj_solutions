#### 题意

用栈来实现队列。题目保证所有操作是合法的（不用担心从空队列中取数之类的）

#### 思路

应该是比较好想的，栈作为LIFO的数据结构，而队列是FIFO，用栈模拟队列的时候会出现队头元素在栈底的情况，这时候取队头势必要把其他栈中的元素弹出来。就很自然的想到了用第二个栈**「辅助栈」**来辅助我们进行操作。

具体如下⬇️

- 1⃣️入队：第一个栈用来模拟入队，入队的时候直接往第一个栈中放元素就好
- 2⃣️出队：这个时候就把第一个栈的元素倒入辅助栈中，只留下一个，这个栈底元素就是我们要的。存储结果之后就把这个元素弹出（但是不放入辅助栈），然后此时再将辅助栈中的元素依次弹出放入第一个栈（即**复原操作**）。当然也可以选择不复原，但这个时候就要记住**「只有辅助栈为空的时候第一个栈才能往辅助栈中倒入元素」**，否则会⚠️破坏本来模拟队列中元素的相对位置
- 3⃣️看队头元素：类似2⃣️，只是此时不会丢弃第一个栈的栈底元素
- 下面给出示意⬇️

```c++
|   |			|	  |
|   |			|   |
| 3 |			|   |
| 2 |			|   |
|_1_|			|___|
//第一个栈  辅助栈
  
|   |			|	  |
|   |			|   |
|   |			|   |
|   |			| 2 |
|_1_|			|_3_|
//取队头元素，即「1」

|   |			|	  |
|   |			|   |
|   |			|   |
| 3 |			|   |
|_2_|			|___|
//复原操作
```

#### 代码

```c++
class MyQueue {
public:
    stack<int> sk1;
    stack<int> sk2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ans;
        while(!sk1.empty())
        {
            if(sk1.size() == 1)     //弹出的时候最后一个元素丢弃
            {
                ans = sk1.top();
                break;
            }
            sk2.push(sk1.top()); 
            sk1.pop();
        }
        sk1.pop();  //丢弃元素
        while(!sk2.empty())
        {
            sk1.push(sk2.top());
            sk2.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        int ans;
        while(!sk1.empty())
        {
            if(sk1.size() == 1)    
            {
                ans = sk1.top();
                // break;
            }
            sk2.push(sk1.top()); 
            sk1.pop();
        }
        while(!sk2.empty())
        {
            sk1.push(sk2.top());
            sk2.pop();
        }
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

