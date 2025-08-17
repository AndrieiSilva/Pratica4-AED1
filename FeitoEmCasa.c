/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *ponteiros[10000];

int cmp(const void * a, const void * b) {
    return (*((struct ListNode **)(a)))->val - (*((struct ListNode **)(b)))->val;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {    
    int total = 0;

    for (int i = 0; i < listsSize; i++) {
        for (struct ListNode *tmp = lists[i]; tmp; tmp = tmp->next) {
            ponteiros[total] = tmp;
            total++;
        }
    }

    qsort(ponteiros, total, sizeof(struct ListNode *), cmp);

    for (int i = 0; i < total - 1; i++) {
        ponteiros[i]->next = ponteiros[i + 1];
    }

    if (total) {
        ponteiros[total - 1]->next = NULL;
    } else {
        ponteiros[0] = NULL;
    }

    return ponteiros[0];
}
