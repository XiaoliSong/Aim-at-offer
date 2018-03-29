/*
链接：https://www.nowcoder.com/questionTerminal/c6c7742f5ba7442aada113136ddea0c3
题目：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

分析：
如果采用递归则需要重复计算很多已经计算了的值
采用循环则非常快
*/

/*
递归方法
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n<=2) return 1;
        else return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
*/
//非递归
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n<=2) return 1;
        int pre1=1,pre2=1;//pre2倒数第一，pre1倒数第二
        n=n-2;
        while(n>0){
            int cur=pre1+pre2;
            pre2=pre1;
            pre1=cur;
            n--;
        }
        return pre1;
    }
};