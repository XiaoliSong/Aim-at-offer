/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00
题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
分析：可以乘以n次，当然需要注意小于0时，应该等于1/res；
改进：用一个32长数组保存base^1,2,3....32，然后比较n的每一位，为1则乘上去
再改进：可以把数组去了，直接求base^1,2,3....32，同时比较n的每一位，为1则乘上去
*/

/*累乘
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0||base==1) return 1;
        double res=1;
        int flag=1;
        if(exponent<0){
            flag=0;
            exponent=-exponent;
        }
        for(int i=0;i<exponent;i++){
            res=res*base;
        }
        if(flag==0){
            res=1/res;
        }
        return res;
    }
};
*/

/*数组保存base^1,2,3....32
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0||base==1) return 1;
        int flag=1;
        if(exponent<0){
            flag=0;
            exponent=-exponent;
        }
        
        vector<double> v(32);
        v[0]=base;
        for(int i=1;i<32;i++){
            v[i]=v[i-1]*v[i-1];
        }
        
        double res=1;
        for(int i=0;i<32;i++){
             if((exponent&1)==1){
                 res*=v[i];
             }
             exponent=exponent>>1;
         }
        if(flag==0){
            res=1/res;
        }
        return res;
    }
};
*/

//无需数组
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0||base==1) return 1;
        int flag=1;
        if(exponent<0){
            flag=0;
            exponent=-exponent;
        }
        
        double cur=base;
        double res=1;
        for(int i=0;i<32;i++){
            if((exponent&1)==1){
                res*=cur;
            }
            cur=cur*cur;
            exponent=exponent>>1;
        }
        
        if(flag==0){
            res=1/res;
        }
        return res;
    }
};
