/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  int length(ListNode* head)
      {
        if(head==NULL)
        return 0;
        return 1+length(head->next);
      }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
        return head; 
        if(!head)
        return nullptr;
        ListNode*p=head;
        int len=length(head);
        int limit=len/k;
        ListNode*temp=nullptr;
        ListNode*hd=head;
        bool flag=true;
        cout<<p->val<<endl;
        while(limit>0)
        {

            cout<<limit<<endl;
             ListNode*ptr=p;
             ListNode*prev=nullptr,*cur2=p,*nxt=nullptr;
             int count=1;
             while(count<=k&&ptr)
             {
              nxt=ptr->next;
              ptr->next=prev;
              prev=ptr;
              ptr=nxt;
              count++;
             }

              if(temp)
              {
                temp->next=prev;
              }
              if(flag)
              {
                hd=prev;
                flag=!flag;
              }
              
             temp=p;
             p=nxt;
             
             limit--;
        }
        if(len%k!=0)
        {
            temp->next=p;
        }
        cout<<hd->val<<endl;
        return hd;
    }
};