/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593
题目：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
分析：
法1：插排法，遍历数组，如果为偶数，则向后查找一个奇数替换到偶数位置，同时把所找到的中间偶数全部后移；直到没有奇数为止
法2：改进插排法
法3：保存到奇数数组和偶数数组，再移到原数组

法1：插排法实现稍微复杂，但没有额外空间，时间复杂度根奇数的个数、出现位置有关。最差情况：N/2个奇数且全出现在后面，需要移动(N^2)/4次
法2：相对于法1，减少了对中间一些偶数的重复判断，查找保证奇数一直向前
法3实现非常简单，但多余了存储空间O(N)

扩展：如果是保存在链表上呢？
维护两个链表，奇数添加到奇数链表，偶数则添加到偶数链表，最好把偶数链表添到奇数尾，返回奇数链表头
*/

/*
//法1：插排法
class Solution {
public:
    void reOrderArray(vector<int> &array) {
       int i=0;
       while(i<array.size()){
           if(array[i]%2==0){
               int j=i+1;
               while(j<array.size()&&array[j]%2==0) j++;
               if(j==array.size()){
                   //无奇数了
                   return;
               }
               int tmp=array[i];
               array[i]=array[j];
               for(int k=j;k>i+1;k--){
                   array[k]=array[k-1];
               }
               array[i+1]=tmp;
           }
           i++;
       }
       return;
    }
};
*/

/*
//改进的插排法
class Solution {
public:
    void reOrderArray(vector<int> &array) {
       int i=0;
       int oddIndex=0;
       while(i<array.size()){
           if(array[i]%2==0){
               if(oddIndex<=i){
                   //oddIndex不大于当前下标，需要当前下标往后一个
                   oddIndex=i+1;
               }
               else{
                   oddIndex++;
               }
               
               //找到下一个奇数下标
               while(oddIndex<array.size()&&array[oddIndex]%2==0) oddIndex++;
               if(oddIndex==array.size()){
                   //无奇数了
                   return;
               }
               int tmp=array[i];
               array[i]=array[oddIndex];
               for(int j=oddIndex;j>i+1;j--){
                   array[j]=array[j-1];
               }
               array[i+1]=tmp;
           }
           i++;
       }
       return;
    }
};
*/


//保存到奇数数组和偶数数组，再移到原数组
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> oddArr;
        vector<int> evenArr;
        oddArr.reserve(array.size()/2);
        evenArr.reserve(array.size()/2);
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1) oddArr.push_back(array[i]);
            else evenArr.push_back(array[i]);
        }
        
        int i=0;
        for(int i=0;i<oddArr.size();i++){
            array[i]=oddArr[i];
        }
        for(int i=0;i<evenArr.size();i++){
            array[oddArr.size()+i]=evenArr[i];
        }
    }
};