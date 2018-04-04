/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163

题目：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

分析：
方法1：先排序，然后取中间值，中间值出现次数大于一半则返回中间值，否则0
方法2：hashMap，对全部数计数，寻找出现次数大于一半的数
方法3：打擂法，超过一半的数最终会赢得擂台。
方法4：快排的划分，参考：查找数组中任意第K大的数字的复杂度为O(N)，可以找第N/2大的数，然后计数，复杂度O(N)
*/

/*
//排序法,复杂度O(NLogN)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(),numbers.end());
        
        int res=numbers[numbers.size()/2];
        int count=1;
        for(int i=numbers.size()/2-1;i>=0;i--){
            if(numbers[i]==res) count++;
            else break;
        }
        for(int i=numbers.size()/2+1;i<numbers.size();i++){
            if(numbers[i]==res) count++;
            else break;
        }
        
        if(count*2>numbers.size()) return res;
        else return 0;
    }
};
*/

/* HashMap法，复杂度O(N)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,int> m;
        for(auto x:numbers){
            m[x]++;
        }
        
        for(auto x:m){
            if(x.second*2>numbers.size()){
                return x.first;
            }
        }
        return 0;
    }
};
*/

/*
//打擂法，复杂度O(N)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()<1) return 0;
        
        int count=1,res=numbers[0];
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]==res){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                res=numbers[i];
                count++;
            }
        }
        
        count=0;
        for(auto x:numbers){
            if(x==res) count++;
        }
        if(count*2>numbers.size()) return res;
        else return 0;
    }
};
*/

//方法4：先找出第N/2大的数，再计数。复杂度O(N)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        nth_element(numbers.begin(),numbers.begin()+numbers.size()/2,numbers.end());
        int res=numbers[numbers.size()/2];
        int count=1;
        for(int i=numbers.size()/2-1;i>=0;i--){
            if(numbers[i]==res) count++;
            else break;
        }
        for(int i=numbers.size()/2+1;i<numbers.size();i++){
            if(numbers[i]==res) count++;
            else break;
        }
        
        if(count*2>numbers.size()) return res;
        else return 0;
    }
};