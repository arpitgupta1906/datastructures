#include <bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node *left;
    node *right;
};

class binarytree{
    private:

        void destroy_tree(node *leaf);
        void insert(int key,node *leaf);
        node *search(int key,node *leaf);
        int maxDepth(node *leaf);
        node *deletenode(node *leaf,int key);
        node *minvaluenode(node *leaf);
    public:
        node *root;
        binarytree();
        ~binarytree();
        int maxDepth();
        void insert(int key);
        bool search(int key);
        void deletenode(int key);
        void postorderTransversal(node *leaf);
        void inorderTransversal(node *leaf);
        void preorderTransversal(node *leaf);

};

binarytree::binarytree(){
    root=NULL;
}

int binarytree::maxDepth(node *leaf){
    if(leaf==NULL)
    return 0;
    else
    {
        int ld=maxDepth(leaf->left);
        int rd=maxDepth(leaf->right);
        if(ld>rd)
        return (ld+1);
        else
        {
            return (rd+1);
        }

    }

}

int binarytree::maxDepth(){
    return maxDepth(root);
}

node *binarytree::search(int key,node *leaf){
    if(leaf!=NULL){
        if(key==(leaf->data))
            return leaf;
        else if(key<=(leaf->data))
            return search(key,leaf->left);
        else
            return search(key,leaf->right);
    }
    else
    {
        return NULL;
    }

}

void binarytree::postorderTransversal(node *leaf){
    if(leaf!=NULL){
    postorderTransversal(leaf->left);
    postorderTransversal(leaf->right);
    cout<<leaf->data<<" ";
    }

}


void binarytree::preorderTransversal(node *leaf){
    if(leaf!=NULL){
    cout<<leaf->data<<" ";
    postorderTransversal(leaf->left);
    postorderTransversal(leaf->right);
    }

}

node *binarytree::minvaluenode(node *leaf){
    node* temp=leaf;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node *binarytree::deletenode(node *leaf,int key){
    if(leaf==NULL)
    return leaf;
    if(key<(leaf->data))
        leaf->left=deletenode(leaf->left,key);
    else if(key>(leaf->data))
        leaf->right=deletenode(leaf->right,key);
    else
    {
        if(leaf->left==NULL){
            node *temp=leaf->right;
            free(leaf);
            return temp;
        }
        else if(leaf->right ==NULL)
        {
            node *temp=leaf->left;
            free(leaf);
            return temp;

        }
        node *temp=minvaluenode(leaf->right);
        leaf->data=temp->data;
        leaf->right=deletenode(leaf->right,temp->data);

    }
    return leaf;

}

void binarytree::deletenode(int key){
    deletenode(root,key);
}

void binarytree::inorderTransversal(node *leaf){
    if(leaf!=NULL){
    postorderTransversal(leaf->left);
    cout<<leaf->data<<" ";
    postorderTransversal(leaf->right);
    }
}

void binarytree::insert(int key,node *leaf){
    if(key <(leaf->data)){
        if((leaf->left!=NULL)){
            insert(key,leaf->left);
        }
        else{
            leaf->left=new node;
            leaf->left->data=key;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }
    else if(key>=(leaf->data)){
        if((leaf->right!=NULL)){
            insert(key,leaf->right);
        }
        else{
            leaf->right=new node;
            leaf->right->data=key;
            leaf->right->right=NULL;
            leaf->left->left=NULL;
        }
    }
}


void binarytree::insert(int key){
    if(root!=NULL){
        insert(key,root);
    }
    else{
        root=new node;
        root->data=key;
        root->right=NULL;
        root->left=NULL;
    }
}

void binarytree::destroy_tree(node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        free(leaf);
    }
}

bool binarytree::search(int key){
    return (search(key,root)!=NULL);
}

binarytree::~binarytree(){
    destroy_tree(root);
    root=NULL;
}

int main(){
    binarytree bt=binarytree();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        bt.insert(d);
    }

    bt.postorderTransversal(bt.root);
    cout<<"\nmax depth is"<<bt.maxDepth();

    bt.~binarytree();
    return 0;
}
