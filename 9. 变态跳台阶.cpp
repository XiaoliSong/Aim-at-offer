/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
题目：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
分析：
可以采用递归跳n次台阶的方法数目=跳n-i次台阶的方法数目求和(i,1,n)
同样可以采用备忘录和循环的方法
继续优化：
跳n次台阶的方法数目=跳n-i次台阶的方法数目求和(i,1,n)
跳1次台阶的方法数目=跳1次台阶的方法数目
跳2次台阶的方法数目=跳1次台阶的方法数目+跳0次台阶的方法数目
跳3次台阶的方法数目=跳2次台阶的方法数目+跳1次台阶的方法数目+跳0次台阶的方法数目
跳n次台阶的方法数目=2*跳n-1次台阶的方法数目
所以跳n次台阶的方法数目=2^(n-1)
*/
/*递归
class Solution {
public:
    int jumpFloorII(int n) {
    	if(n<=1) return 1;
    	int res=0;
    	for(int i=1;i<=n;i++){
    		res+=jumpFloorII(n-i);
    	}
    	return res;
    }
};
*/
//
/*备忘录
class Solution {
public:
    vector<int> nums;
    int jumpFloorII(int n) {
    	nums.resize(n+1,0);
        return jumpProcess(n);
    }
    int jumpProcess(int n){
        if(n<=1) return 1;
        if(nums[n]==0){
            int res=0;
            for(int i=1;i<=n;i++){
                res+=jumpProcess(n-i);
            }
            nums[n]=res;
        }
        return nums[n];
    }
};
*/
/*
class Solution {
public:
    int jumpFloorII(int n) {
        if(n<=1) return 1;
    	vector<int> nums(n+1);
        nums[1]=1;
        int res=0;
        for(int i=2;i<=n;i++){
            int sum=0;
            for(int j=1;j<i;j++){
                sum+=nums[j];
            }
            sum=sum+1;
            nums[i]=sum;
        }
        return nums[n];
    }
};
*/
/*
class Solution {
public:
    int jumpFloorII(int n) {
    	int res=1;
        while(n>1){
            res=res*2;
            n--;
        }
        return res;
    }
};
*/

class Solution {
public:
    int jumpFloorII(int n) {
    	int res=1;
        return res<<(n-1);
    }
};