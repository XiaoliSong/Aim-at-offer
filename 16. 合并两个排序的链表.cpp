/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337
题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode* cur;
        if(pHead1->val<pHead2->val) {
            cur=pHead1;
            pHead1=pHead1->next;
        }
        else {
            cur=pHead2;
            pHead2=pHead2->next;
        }
        
        //保存新的链表头
        ListNode* newHead=cur;
        
        while(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->val<pHead2->val){
                cur->next=pHead1;
                cur=pHead1;
                pHead1=pHead1->next;
            }
            else {
                cur->next=pHead2;
                cur=pHead2;
                pHead2=pHead2->next;
            }
        }
        
        if(pHead1==NULL){
            cur->next=pHead2;
        }
        else{
            cur->next=pHead1;
        }
        return newHead;
    }
};