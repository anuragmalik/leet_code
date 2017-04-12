//LeetCode - 61
// rotating list - given a linked list and rotation amount K
#include <cstdio>
#include <iostream>

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return head;

    ListNode *ecur= head, *kcur = head;
    int steps = 0, len = 0;

    while(ecur != NULL) {
        len++;
        ecur = ecur->next;
    }

    k = k % len;
    if(k == 0) return head;

    ecur = head;
    while(steps++ < k)
        ecur = ecur->next;

    while(ecur->next != NULL) {
        ecur = ecur->next;
        kcur = kcur->next;
    }

    ecur->next = head;
    head = kcur->next;
    kcur->next = NULL;

    return head;
}

void print_llist(ListNode* list) {
    while(list != NULL) {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << "\n";
}

int main(){
    ListNode* list = new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, NULL)))));
    print_llist(list);
    list = rotateRight(list, 4);
    print_llist(list);
}
