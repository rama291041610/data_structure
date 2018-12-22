#include <bits/stdc++.h>
using namespace std;

struct BST {
        int val;
        BST *left,*right,*parent;
};

int success,fail;

BST* search(BST *root,int key){
        int cnt=0;
        while(root) {
                cnt++;
                if(key==root->val) break;
                else if(key<root->val) root=root->left;
                else root=root->right;
        }
        if(root==NULL) {
                fail+=cnt;
                return root;
        }
        else if(root->val==key) {
                success+=cnt;
                return root;
        }
}

BST* creat_node(int val){
        BST *node=(BST*)malloc(sizeof(BST));
        node->val=val;
        node->left=NULL,node->right=NULL,node->parent=NULL;
        return node;
}

void insert(BST* root,int val){
        BST *node=creat_node(val);
        BST *par=NULL,*child=root;
        while(child) {
                par=child;
                if(val<par->val) child=child->left;
                else child=child->right;
        }
        node->parent=par;
        if(node->val<par->val) par->left=node;
        else par->right=node;
}

BST* minum(BST *root){
        while(root->left) root=root->left;
        return root;
}

void trans(BST* &root,BST *u,BST* v){
        if(u->parent==NULL) root=v;
        else if (u==u->parent->left) u->parent->left=v;
        else u->parent->right=v;
        if(!v) v->parent=u->parent;
}


void del(BST *root,int val){
        BST *node=search(root,val);
        if(node->left==NULL) trans(root,node,node->right);
        else if(node->right==NULL) trans(root,node,node->left);
        else {
                BST *tmp=minum(node->right);
                if(tmp->parent!=node) {
                        trans(root,tmp,tmp->right);
                        tmp->right=node->right;
                        tmp->right->parent=tmp;
                }
                trans(root,node,tmp);
                tmp->left=node->left;
                tmp->left->parent=tmp;
        }
        free(node);
}

void sort_BST(BST *root){
        if(root==NULL) return;
        sort_BST(root->left);
        cout<<root->val<<" ";
        sort_BST(root->right);
}

bool half_search(int num[],int val,int len){
        int left=0,right=len-1;
        int cnt=0,mid;
        while(left!=right) {
                cnt++;
                mid=(left+right)/2;
                if(num[mid]==val) break;
                else if(num[mid]<val) left=mid+1;
                else right=mid;
        }
        if(left==right) {
                fail+=cnt;
                return false;
        }
        else{
                success+=cnt;
                return true;
        }
}

int main(){
        freopen("data.txt","r",stdin);
        int a[1024],b[1024];
        for(int i=0; i<1024; i++) cin>>a[i];
        BST *order=creat_node(a[0]);
        for(int i=1; i<1024; i++) insert(order,a[i]);

        fail=0,success=0;
        for(int i=0; i<2049; i++) search(order,i);
        cout<<fail/1024.0<<" "<<success/1024.0<<endl;

        for(int i=0; i<1024; i++) cin>>b[i];
        BST *random=creat_node(b[0]);
        for(int i=1; i<1024; i++) insert(random,b[i]);

        fail=0,success=0;
        for(int i=0; i<2049; i++) search(random,i);
        cout<<fail/1024.0<<" "<<success/1024.0<<endl;

        fail=0,success=0;
        for(int i=0; i<2049; i++) half_search(a, i,1024);
        cout<<fail/1024.0<<" "<<success/1024.0<<endl;
}
