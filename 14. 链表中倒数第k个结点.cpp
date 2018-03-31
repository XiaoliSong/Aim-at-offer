/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a
题目：输入一个链表，输出该链表中倒数第k个结点。
分析：
法1：计数法，先计算链表的长度N，再从头求出N-K个节点。
法2：pre指针比last指针前K，所以当pre指向尾时，last则指向了倒数第k个结点。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/*
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k<=0){
            return NULL;
        }
        int count=0;
        ListNode* tmp=pListHead;
        while(tmp!=NULL){
            tmp=tmp->next;
            count++;
        }
        
        k=count-k;
        if(k<0) return NULL;
        
        tmp=pListHead;
        while(tmp!=NULL&&k>0){
            tmp=tmp->next;
            k--;
        }
        return tmp;
    }
};
*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k<=0){
            return NULL;
        }
        ListNode* pre=pListHead;
        for(int i=0;i<k;i++){
            pre=pre->next;
            if(pre==NULL&&i<k-1) return NULL;
            //注意i<k-1，如果取第一个的话，不加条件会返回NULL
        }
        
        ListNode* last=pListHead;
        while(pre!=NULL){
            pre=pre->next;
            last=last->next;
        }
        return last;
    }
};