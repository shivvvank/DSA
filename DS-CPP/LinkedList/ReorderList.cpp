
void reorderList(ListNode* head) {
    map<int,ListNode*> m;
    ListNode* temp = head;
    int i=0,j=0;
    while(temp)
    {
        m[j++]=temp;
        temp=temp->next;
    }
    j--;
    while(i<j)
    {
        m[j-1]->next=m[j]->next;
        m[j]->next=m[i]->next;
        m[i]->next=m[j];
        i++;
        j--;
    }
    temp=head;
    while(temp->next)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<temp->val<<endl;
}