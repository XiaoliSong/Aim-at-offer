/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423
题目：
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
分析：
新建个数组s保存str，然后遍历s，遇到空格则对str加"%20"，否则加原符号，当然最后别忘了置'\0'
复杂度：时间O(N)，空间O(N)
*/


class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s(str);
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str[j++]='%';
                str[j++]='2';
                str[j++]='0';
            }
            else{
                str[j++]=s[i];
            }
        }
        str[j]='\0';
	}
};

/*
分析：
或者从后往前修改
先计算出空格的数量，则替换空格后的字符数量为原数量+2*空格的数量
从后往前遍历原字符串，遇到空格修改为"%20"，否则赋值为原字符
复杂度：时间O(N)，空间O(1)
实际运行，比上面的时间要长！
*/

/*
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int newLength=length;
        for(int i=0;i<length;i++){
            if(str[i]==' ') newLength+=2;
        }
        
        str[newLength]='\0';
        int j=newLength-1;
        for(int i=length-1;i>=0&&i<j;i--){
            if(str[i]==' '){
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }
            else{
                str[j--]=str[i];
            }
        }
	}
};
*/