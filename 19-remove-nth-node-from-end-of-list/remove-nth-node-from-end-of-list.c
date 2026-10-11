/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy ;
    dummy.next = head;
    struct ListNode *slow = &dummy;
    struct ListNode *fast = &dummy;

    for(int i = 0 ; i<n ; i++){
        fast = fast->next;
    }

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}