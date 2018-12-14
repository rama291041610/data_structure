#include <bits/stdc++.h>
using namespace std;


struct Node {
        string val;
        Node *left,*right;
};

map<string,Node*> dict;

Node* creat_node(string val){
        Node *cur=(Node*)malloc(sizeof(Node));
        dict[val]=cur;
        cur->val=val;
        cur->left=NULL;
        cur->right=NULL;
        return cur;
}


void add_node(string val,string par,string pos){
        Node *cur=creat_node(val);
        if(pos=="L") dict[par]->left=cur;
        else if(pos=="R") dict[par]->right=cur;
}


void pre_order_1(Node *root) {
        if(root==NULL) return;
        cout<<root->val<<" ";
        pre_order_1(root->left);
        pre_order_1(root->right);
}

void pre_order_2(Node *root){
        if(root==NULL) return;
        stack<Node*> tmp;
        Node *cur=root;
        while(cur) {
                cout<<cur->val<<" ";
                if(cur->right!=NULL) tmp.push(cur->right);
                cur=cur->left;
                if(cur==NULL&&!tmp.empty()) {
                        cur=tmp.top();
                        tmp.pop();
                }
        }
}

void mid_order_1(Node *root){
        if(root==NULL) return;
        mid_order_1(root->left);
        cout<<root->val<<" ";
        mid_order_1(root->right);
}

void mid_order_2(Node *root){
        if(root==NULL) return;
        stack<Node*> tmp;
        Node *cur=root;
        while(cur) {
                tmp.push(cur);
                cur=cur->left;
                while(cur==NULL&&!tmp.empty()) {
                        cur=tmp.top();
                        tmp.pop();
                        cout<<cur->val<<" ";
                        cur=cur->right;
                }

        }
}

void back_order_1(Node *root){
        if(root==NULL) return;
        back_order_1(root->left);
        back_order_1(root->right);
        cout<<root->val<<" ";
}

void back_order_2(Node *root) {
        if(root==NULL) return;
        stack<Node*> tmp;
        Node *cur,*pastvis;
        cur=root;
        pastvis=NULL;

        while(cur) {
                /*遍历左子树*/
                tmp.push(cur);
                cur=cur->left;
        }

        while (!tmp.empty()) {
                cur=tmp.top();
                tmp.pop();

                if(cur->right==NULL||cur->right==pastvis) {
                        /*已遍历右子树或无右子树*/
                        cout<<cur->val<<" ";
                        pastvis=cur;
                }
                else if(cur->left==pastvis) {
                        tmp.push(cur);
                        cur=cur->right;
                        while(cur) {
                                tmp.push(cur);
                                cur=cur->left;
                        }
                }
        }
}

void lever_order(Node *root){
        if(root==NULL) return;
        queue<Node*> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
                Node *cur=tmp.front();
                tmp.pop();
                if(cur->left!=NULL) tmp.push(cur->left);
                if(cur->right!=NULL) tmp.push(cur->right);
                cout<<cur->val<<" ";
        }
}

void print_tree(Node *root,int space){
        while(root) {
                print_tree(root->right, space+4);
                for(int i=0; i<space; i++) printf(" ");
                cout<<root->val<<endl;
                print_tree(root->left, space+4);
                root=NULL;
        }
}

bool is_complete_BTtree(Node *root){
        queue<Node*> tmp;
        tmp.push(root);
        while(!tmp.empty()) {
                Node *cur=tmp.front();
                tmp.pop();
                if(cur==NULL) break;
                else{
                        tmp.push(cur->left);
                        tmp.push(cur->right);
                }
        }
        while (!tmp.empty()) {
                Node *cur=tmp.front();
                if(cur) return false;
                else tmp.pop();
        }
        return true;
}

void destroy(Node *root){
        if(root==NULL) return;
        destroy(root->left);
        destroy(root->right);
        free(root);
}

int main() {
        freopen("ex2_tree1.txt","r",stdin);

        Node *root=(Node*)malloc(sizeof(Node));
        string val,par,pos;

        while (cin>>val&&val!="-1") {
                cin>>par>>pos;
                if(par=="-1"&&pos=="-1") root=creat_node(val);
                else add_node(val,par,pos);
                //cout<<val<<par<<pos<<endl;
        }

        cout<<"Binary Tree:"<<endl;
        print_tree(root, 0);
        cout<<"\n"<<endl;

        cout<<"Pre Order"<<endl;
        pre_order_1(root);
        cout<<endl;
        pre_order_2(root);
        cout<<"\n"<<endl;

        cout<<"Mid Order"<<endl;
        mid_order_1(root);
        cout<<endl;
        mid_order_2(root);
        cout<<"\n"<<endl;

        cout<<"Back Order"<<endl;
        back_order_1(root);
        cout<<endl;
        back_order_2(root);
        cout<<"\n"<<endl;

        cout<<"Lever Order"<<endl;
        lever_order(root);
        cout<<endl;

        if(is_complete_BTtree(root)) cout<<"This is a Complete Binary Tree"<<endl;
        else cout<<"This is not a Complete Binary Tree"<<endl;

        destroy(root);
        return 0;
}
