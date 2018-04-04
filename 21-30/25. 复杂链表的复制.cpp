/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba

题目：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

分析：
复杂链表：next指向下一节点，而random指向整个链表的任意一个节点

哈希表法：
复制整个链表，哈希表保存原链表指针和新链表指针的对应关系。遍历新链表更新random指针

之字法：
1   2   3
↓ ↗↓ ↗↓
1'  2'  3'
创建新链表的时候，用原结点的next指针指向对应新结点，新结点的next指针指向下一个原结点，以此类推，形成之字形关联。然后，就可以先更新新链表的random指针，再解除next关联，更新next指针。这种方法不需要map来辅助，不管查找next还是random指针都是O(1)的，效率很高。
*/


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

/*
//map关联
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* pHead1=pHead;//原链表
        RandomListNode* pHead2=new RandomListNode(pHead1->label);//新链表
        RandomListNode* newHead=pHead2;
        m[pHead1]=pHead2;
        while(pHead1){
            if(pHead1->next) pHead2->next=new RandomListNode(pHead1->next->label);
            else pHead2->next=NULL;
            pHead1=pHead1->next;
            pHead2=pHead2->next;
            m[pHead1] = pHead2;//保存原链表和新链表的对应关系
        }

        pHead1=pHead;
        pHead2=newHead;
        while(pHead1){
            //更新新链表的random
            pHead2->random=m[pHead1->random];
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return newHead;
    }
};
*/

//之字法
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        
        RandomListNode *newHead=new RandomListNode(pHead->label);
        RandomListNode *pHead1=NULL,*pHead2=NULL;

        //上链，使新旧链表成之字形链接
        for(pHead1=pHead,pHead2=newHead;pHead1!=NULL;){
            RandomListNode* pHead1Next=pHead1->next;
            pHead1->next=pHead2;
            pHead2->next=pHead1Next;
            // next
            pHead1=pHead1Next;
            if(pHead1) pHead2=new RandomListNode(pHead1->label);
            else pHead2=NULL;
        }

        // 更新新链表的random指针
        for(pHead1=pHead,pHead2=newHead;pHead1!=NULL;){
            if(pHead1->random) pHead2->random=pHead1->random->next;
            else pHead2->random=NULL;

            pHead1=pHead2->next;
            if(pHead1!=NULL) pHead2=pHead1->next;
            else pHead2=NULL;
        }

        // 脱链，更新各链表的next指针
        for(pHead1=pHead,pHead2=newHead;pHead1!=NULL;){
            pHead1->next=pHead2->next;
            if(pHead1->next) pHead2->next=pHead1->next->next;
            else pHead2->next=NULL;

            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }

        return newHead;
    }
};