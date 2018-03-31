/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49
题目：
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

分析：
采用两个栈，一个为普通栈，另一个栈保存当前最小值。

问题：最小值被重复存储多次，和普通栈同大小，如何减少最小值栈的存储空间？
可以进栈时比较最小值栈的栈顶和进栈的value，小于等于value则进栈；出栈时，比较普通栈和最小值栈的栈顶，相等时则两个都出栈，否则只有普通栈出栈

扩展：最大栈？最大最小栈？
最大栈和最小栈类似，最大最小栈把两个结合起来就行了
*/

class Solution {
private:
    stack<int> mins;
    stack<int> s;
public:
    void push(int value) {
        s.push(value);
        if(mins.size()==0||mins.top()>=value){
            mins.push(value);
        }
    }
    void pop() {
        if(s.size()==0) return;
        if(mins.top()==s.top()){
            mins.pop();
        }
        s.pop();
    }
    int top() {
        if(s.size()==0) return 0;
        return s.top();
    }
    int min() {
        if(mins.size()==0) return 0;
        return mins.top();
    }
};