struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {    
    int aux;
    int v[1000000];
    int count = 0;
    struct ListNode * comeco = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (listsSize < 1)
        return comeco;

    // Insere os valores no Vetor
    for (int i = 0; i < listsSize; i++) {
        struct ListNode * p =  lists[i];
        while (p != NULL){
            v[count] = p->val;
            count++;
            p = p->next;
        }
    }


    // Ordena os valores no Vetor
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (v[i] > v[j]) {
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }

    // cria uma lista encadeada com os valores contidos no Vetor

    
    comeco->val = v[0];

    struct ListNode * k = comeco;

    for (int i = 1; i < count-1; i++) {
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        k->next = new;
        new->val = v[i];
    }

    return comeco;

}
