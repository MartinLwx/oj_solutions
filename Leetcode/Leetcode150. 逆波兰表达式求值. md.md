#### 题意

逆波兰表达式求值，题目保证输入的逆波兰表达式是有效可解的

#### 思路

- 表达式求值是栈的经典应用，可以说是很熟悉了。和算数式->逆波兰表达式相比，这个求值可以说是小儿科
- 主要思路就是——构造一个栈用来存放运算数，当遇到操作符的时候出栈2个运算数，进行相应的运算，算完之后将结果压入栈中，如此往复直到处理完
- 注意⚠️
  - 要处理好'-'号和负数的判断，我这里是通过首字符和长度来判断的
  - 先后出栈的元素分别是表达式`a ? b`的`b`和`a`
  - C++中可以使用`std::stoi(string s)`来将string转化为int类型的数

#### 代码

```c++
class Solution {
public:
    int calculate(int x, int y, char op)
    {
        switch(op){
            case '+':   return x + y;
            case '-':   return x - y;
            case '/':   return x / y;
            case '*':   return x * y;
        }
        return 1;    //表示执行成功，实际执行不会运行到这里
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto token: tokens)
        {
            if(token[0] == '+' || token[0] == '/' || token[0] == '*' ||  token[0] == '-' && token.size() == 1 )
            {
                auto right = nums.top();
                nums.pop();
                auto left = nums.top();
                nums.pop();
                int val = calculate(left, right, token[0]);
                nums.push(val);
            }else   
                nums.push(stoi(token));
        }
        return nums.top();
    }
};
```

