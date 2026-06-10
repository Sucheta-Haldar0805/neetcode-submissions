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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        //find midpoint
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse and split 
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        //merge
        slow = head;
        fast = prev;

        while(fast != NULL){
            ListNode* temp1 = slow->next;
            ListNode* temp2 = fast->next;

            slow->next = fast;
            fast->next = temp1;

            slow = temp1;
            fast = temp2;
        }
    }
};
