#### 题意

用队列来实现栈，保证了所有操作合法

#### 思路

- 刚做完用栈实现队列的题目，所以一开始想用2个队列，利用第二个队列来存储前`n-1`个元素，但是后来转念一想🤔，不如直接用一个队列，把前`n-1`个元素重新入队，那么此刻队头可不就是要的栈顶元素了吗！👀

#### 代码

```c++
class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size();
        for(int i=0;i<q.size()-1;i++)
        {
            auto element = q.front();
            q.pop();
            q.push(element);
        }
        auto top = q.front();
        q.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        int size = q.size();
        for(int i=0;i<q.size()-1;i++)
        {
            auto element = q.front();
            q.pop();
            q.push(element);
        }
        auto top = q.front();
        q.pop();
        q.push(top);
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

