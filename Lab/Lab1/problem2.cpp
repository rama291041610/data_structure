#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

struct X {
        int a,E;
};

struct linklist {
        X val;
        linklist *next;
};

linklist* init_linklist(){
        linklist *phead=(linklist*)malloc(sizeof(linklist));
        phead->next=NULL;
        return phead;
}

void del_linklist(linklist* phead,X val){
        while(phead->next!=NULL) {
                if(phead->next->val.E==val.E&&phead->next->val.a==val.a) {
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

void insert_linklist(linklist* phead,X val)
{
        if(val.a==0) return;
        linklist *tmp=phead;
        while(phead->next!=NULL) {
                if(phead->next->val.E>val.E) break;
                if(phead->next->val.E==val.E) {
                        phead->next->val.a+=val.a;
                        if(phead->next->val.a==0) {
                                del_linklist(tmp,phead->next->val);
                        }
                        return;
                }
                phead=phead->next;
        }
        linklist *cur=(linklist*)malloc(sizeof(linklist));
        cur->val=val;
        cur->next=phead->next;
        phead->next=cur;
}

bool is_exist_linklist(linklist *phead, X val){
        while(phead->next!=NULL) {
                if(phead->next->val.E==val.E&&phead->next->val.a==val.a) return true;
                phead=phead->next;
        }
        return false;
}

int search_linklist(linklist *phead,X val){
        int pos=1;
        if(is_exist_linklist(phead,val)) {
                while(phead->next->val.E!=val.E||phead->next->val.a!=val.a) {
                        pos++;
                        phead=phead->next;
                }
                printf("[%d %d] in the %d postion\n",val.a,val.E,pos);
                return pos;
        }
        printf("[%d %d] NOT FOUND\n",val.a,val.E);
        return -1;
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
                printf("[%d %d] ",phead->val.a,phead->val.E);
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

        int n;
        cin>>n;
        for(int i=0; i<n; i++) {
                linklist *x=init_linklist();
                linklist *y=init_linklist();
                linklist *ans=init_linklist();

                while (true) {
                        X tmp;
                        cin>>tmp.a>>tmp.E;
                        insert_linklist(x,tmp);
                        if(tmp.E<0) break;
                }

                while (true) {
                        X tmp;
                        cin>>tmp.a>>tmp.E;
                        insert_linklist(y,tmp);
                        if(tmp.E<0) break;
                }
                //print_linklist(x);
                //print_linklist(y);

                x=x->next;
                y=y->next;
                while(x!=NULL&&y!=NULL) {
                        if(x->val.E>y->val.E) {
                                insert_linklist(ans,y->val);
                                y=y->next;
                        }
                        else if(x->val.E<y->val.E) {
                                insert_linklist(ans,x->val);
                                x=x->next;
                        }
                        else{
                                X tmp={x->val.a+y->val.a,x->val.E};
                                if(tmp.a) insert_linklist(ans, tmp);
                                x=x->next;
                                y=y->next;
                        }
                }
                while(x!=NULL) {
                        insert_linklist(ans, x->val);
                        x=x->next;
                }
                while(y!=NULL) {
                        insert_linklist(ans, y->val);
                        y=y->next;
                }

                reverse_linklist(ans);
                print_linklist(ans);
                destroy_linklist(x);
                destroy_linklist(y);
                destroy_linklist(ans);
        }
        return 0;
}
