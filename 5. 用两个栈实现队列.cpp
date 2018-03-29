/*
链接：https://www.nowcoder.com/questionTerminal/54275ddae22f475981afa2244dd448c6
题目：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
分析：
入栈时，用stack1入栈
出栈时，如果stack2为空，则把stack1全部出栈压入stack2；否则直接stack2出栈
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.empty()&&stack2.empty()){
            throw(1);
        }
        
        int res;
        if(stack2.empty()){
            while(!stack1.empty()){
                res=stack1.top();
                stack1.pop();
                stack2.push(res);
            }
            stack2.pop();
        }
        else{
            res=stack2.top();
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};