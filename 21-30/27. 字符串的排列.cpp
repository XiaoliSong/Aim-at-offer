/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163

题目：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
分析：
方法1：递归方法
方法2：迭代字典排序全排列
方法3：STL字典序全排列
*/

//递归方法
/*
class Solution {
public:
    vector<string> Permutation(string str) {
        sort(str.begin(),str.end());//由于字典序，所以先排序
        vector<string> res;
        PermutationProcess(res,str,0);
        sort(res.begin(),res.end());//由于字典序，所以结果需要排序
        return res;
    }
private:
    void PermutationProcess(vector<string> &res,string &str,int i){
        if(i==str.size()-1){
            res.push_back(str);
            return;
        }
        for(int j=i;j<str.size();j++){
            if(i!=j&&str[i]==str[j]){
                continue;
            }
            swap(str[i],str[j]);
            PermutationProcess(res,str,i+1);
            swap(str[i],str[j]);
        }
    }
};
*/

/*
//自己编写的字典排序全排列
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return vector<string>();
        
        vector<string> res;
        sort(str.begin(),str.end());
        res.push_back(str);
        while(true){
            //从后往前找到第一个变小的数字,下标为i-1
            int i=str.size()-1;
            while(i>0&&str[i-1]>=str[i]) i--;
            if(i==0) break;
            
            //从下标i开始找最后一个大于str[i-1]的数，下标为j-1
            int j=i;
            while(j<str.size()&&str[j]>str[i-1]) j++;
            
            swap(str[i-1],str[j-1]);
            reverse(str.begin()+i,str.end());
            res.push_back(str);
        }
        return res;
    }
};
*/

//STL字典序全排列
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return vector<string>();
        
        vector<string> res;
        do{
            res.push_back(str);
        }while(next_permutation(str.begin(),str.end()));
        return res;
    }
};