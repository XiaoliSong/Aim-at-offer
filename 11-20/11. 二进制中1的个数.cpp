/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8
题目：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
分析：可以有三种解法
移位法1：每次取出末位，为1则加1，然后n右移1位，循环32次
移位法2：设置flag初始为1;如果n&flag!=0则res++，flag每次都左移直到flag为0。flag的一个1从右往左直到移出。
n-1法：当n!=0时，res++，n=n&(n-1)。n=n&(n-1)相当于把1的个数减少了一个。
*/

/*
//移位法1
class Solution {
public:
     int  NumberOf1(int n) {
         int res=0;
         for(int i=0;i<32;i++){
             res+=n&1;
             n=n>>1;
         }
         return res;
     }
};
*/

/*
//移位法2
class Solution {
public:
    int NumberOf1(int n){
        int res=0;
        int flag = 1;
        while (flag!= 0){
            if ((n&flag)!= 0) {
                res++;
            }
            flag=flag<<1;
        }
        return res;
    }
};
*/


//n-1法
class Solution {
public:
     int  NumberOf1(int n) {
         int res=0;
         while(n!=0){
             res++;
             n=n&(n-1);
         }
         return res;
     }
};