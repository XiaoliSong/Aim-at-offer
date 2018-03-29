/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
分析：
类似8.跳台阶，7.类似斐波那契数列
由于小矩形不能够这样摆放
  1 1
1 1
所以每次都是横放（2块）或者竖放一块的选择
*/

//递归
/*
class Solution {
public:
    int rectCover(int n) {
        if(n<=1) return 1;
        return rectCover(n-1)+rectCover(n-2);
    }
};
*/

//备忘录方法
/*
class Solution {
public:
    vector<int> nums;
    int rectCover(int n) {
        nums.resize(n+1,0);
        return jumpProcess(n);
    }
    
    int rectCoverProcess(int n){
        if(n<=1) return 1;
        if(nums[n]!=0) return nums[n];
        else{
            nums[n]=rectCoverProcess(n-1)+rectCoverProcess(n-2);
        }
        return nums[n];
    }
};
*/
//循环方法
class Solution {
public:
    int rectCover(int n) {
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