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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(), *node = head;
        while(list1 != NULL or list2 != NULL){
            if(list1 && ((list2 && list1->val < list2->val) || !list2)){
                head->next = list1;
                list1 = list1->next;
            }   
            else if(list2 && ((list1 && list1->val >= list2->val) || !list1)){
                head->next = list2;
                list2 = list2->next;
            } 
            head = head->next;
        }
        return node->next;
    }
};