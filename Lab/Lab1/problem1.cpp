#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

struct linklist {
        int val;
        linklist *next;
};

linklist* init_linklist(){
        linklist *phead=(linklist*)malloc(sizeof(linklist));
        phead->next=NULL;
        return phead;
}

void insert_linklist(linklist* phead,int val)
{
        while(phead->next!=NULL) {
                if(phead->next->val>=val) break;
                phead=phead->next;
        }
        linklist *cur=(linklist*)malloc(sizeof(linklist));
        cur->val=val;
        cur->next=phead->next;
        phead->next=cur;
}

bool is_exist_linklist(linklist *phead, int val){
        while(phead->next!=NULL) {
                if(phead->next->val==val) return true;
                phead=phead->next;
        }
        return false;
}

int search_linklist(linklist *phead,int val){
        int pos=1;
        if(is_exist_linklist(phead,val)) {
                while(phead->next->val!=val) {
                        pos++;
                        phead=phead->next;
                }
                printf("%d in the %d postion\n",val,pos);
                return pos;
        }
        printf("%d NOT FOUND\n",val);
        return -1;
}

void del_linklist(linklist* phead,int val){
        while(phead->next!=NULL) {
                if(phead->next->val==val) {
                        linklist *tmp=(linklist*)malloc(sizeof(linklist));
                        tmp=phead->next;
                        phead->next=tmp->next;
                        free(tmp);
                        return;
                }
                phead=phead->next;
        }
        return;
}

int linklist_len(linklist *phead){
        int len=0;
        while(phead->next!=NULL) {
                len++;
                phead=phead->next;
        }
        return len;
}

void print_linklist(linklist *phead){
        if(phead->next==NULL) return;
        phead=phead->next;
        while(phead!=NULL) {
                printf("%d ",phead->val);
                phead=phead->next;
        }
        printf("\n");
}

void reverse_linklist_op(linklist *phead){
        if(phead->next==NULL) return;
        reverse_linklist_op(phead->next);
        if(phead->next->next==NULL) {
                phead->next->next=phead;
                phead->next=NULL;
        }
}

void reverse_linklist(linklist *phead){
        if(phead->next==NULL) return;
        linklist *pend=phead;
        while(pend->next!=NULL) pend=pend->next;
        reverse_linklist_op(phead->next);
        phead->next=pend;
}

void destroy_linklist(linklist *phead){
        if(phead==NULL) return;
        destroy_linklist(phead->next);
        free(phead);
}

int main(int argc, char const *argv[]) {
        freopen("input.txt","r",stdin);

        int num[2333];
        int n=0;
        while(scanf("%d",&num[n])!=EOF) n++;

        linklist *phead=init_linklist();
        for (int i = 0; i < n; i++) insert_linklist(phead,num[i]);
        print_linklist(phead);

        search_linklist(phead,1);
        search_linklist(phead,-233);

        insert_linklist(phead,-5623);
        print_linklist(phead);

        del_linklist(phead, -233);
        print_linklist(phead);

        printf("LINKLIST LENTH = %d\n",linklist_len(phead));

        reverse_linklist(phead);
        print_linklist(phead);

        destroy_linklist(phead);
        return 0;
}
