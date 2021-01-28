#### 题意

给定每一个学生的开始时间和结束时间，问某个时间点有多少人正在做作业

#### 思路

- 我们只要开一个数组，用`count[i]`表示这个时间点有多少人在做作业，那么我们每读入`[开始时间, 结束时间]`就将其对应区间的`count[i]`加一

#### 代码

```c++
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> count(1001, 0);
        for(int i=0;i<startTime.size();i++) {
            int st = startTime[i];
            int ed = endTime[i];
            for(int j=st;j<=ed;j++) {
                count[j]++;
            }
        }
        return count[queryTime];
    }
};
```

