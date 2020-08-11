#### 题意

所谓最小栈就是要在本来栈的定义上多了一个操作，`getMin()`操作——返回栈中最小值。

#### 思路

- 很朴素的一个想法是用返回最小值的时候从头到尾遍历一遍找最小。也就是下面代码1.0。实际上提交发现这个是非常耗时的（300ms+）。
- 代码1.0的缺陷在于每次获得最小值都要去遍历一遍操作。在此基础上，有了另一个想法，我们可以用一个变量来保存最小值。**不难想到，当出栈的元素刚好是保存的最小值的元素的时候，我们如何找到下一个最小值。**我的想法很干脆，遍历一遍找就好了。出乎意料的是，表现竟然还可以（60ms+），和题解的表现基本持平。
- 最后这个思路是看了题解才知道的，用辅助栈的思路。每次入栈元素的时候辅助栈就入队当前的最小元素。即**任何时刻栈的最小元素都在辅助栈栈顶**。实在是妙🤔。典型的「用空间换时间」思想。

#### 代码1.0

```c++
class MinStack {
private:
    vector<int> sk;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        sk.push_back(x);
    }
    
    void pop() {
        sk.erase(sk.end() - 1);
    }
    
    int top() {
        return sk.back();
    }
    
    int getMin() {
        int min = sk[0];
        for(int i=0;i<sk.size();i++)
            if(sk[i] < min) min = sk[i];
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

#### 代码2.0

```c++
class MinStack {
private:
    vector<int> sk;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        sk.push_back(x);
        if(sk.size() == 1)  min = sk[0];
        else if(x < min)    min = x;
    }
    
    void pop() {
        if(sk.back() == min)
        {
            min = sk[0];
            for(int i=1;i<sk.size() - 1;i++)
                if(sk[i] < min)     min = sk[i];
        }
        sk.erase(sk.end() - 1);
    }
    
    int top() {
        return sk.back();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

#### 题解代码

以下代码取自题解～

```c++
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
```

