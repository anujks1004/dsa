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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        ListNode* prevB = list1;
        for(int i = 0; i <= b; i++)
        {
            if(i == a - 1)
                prevA = prevB;
            prevB = prevB->next;
        }
        
        ListNode* temp = list2;
        while(temp->next)
            temp = temp->next;
        
        prevA->next = list2;
        temp->next = prevB;

        return list1;
        

    }
};