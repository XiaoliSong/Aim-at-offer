/*
链接：https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
分析：
如果采用递归，则需要很多的重复计算，可以采用备忘录方法进行存储避免不必要的重复计算
当然可以注意到类似于斐波那契数列，跳n次台阶的方法数目=跳n-1次台阶的方法数目+跳n-2次台阶的方法数目
所以可以采用循环方法解决
*/

//递归
/*
class Solution {
public:
    int jumpFloor(int n) {
        if(n<=1) return 1;
        return jumpFloor(n-1)+jumpFloor(n-2);
    }
};
*/

//备忘录方法
/*
class Solution {
public:
    vector<int> nums;
    int jumpFloor(int n) {
        nums.resize(n+1,0);
        return jumpProcess(n);
    }
    
    int jumpProcess(int n){
        if(n<=1) return 1;
        if(nums[n]!=0) return nums[n];
        else{
            nums[n]=jumpProcess(n-1)+jumpProcess(n-2);
        }
        return nums[n];
    }
};
*/
//循环方法
class Solution {
public:
    int jumpFloor(int n) {
        if(n<=1) return 1;
        int pre1=1,pre2=1;
        n=n-1;
        while(n>0){
            int cur=pre1+pre2;
            pre2=pre1;
            pre1=cur;
            n--;
        }
        return pre1;
    }
};