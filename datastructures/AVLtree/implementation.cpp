#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a,int b){
  return (a>b)?a:b;
}

int height(Node *n){
  if(n==NULL)
  return 0;
  else
  return n->height;
}

int getBalance(Node *n){
  if(n==NULL)
  return 0;
  return height(n->left)-height(n->right);
}

Node* newnode(int key){
  Node* node=new Node();
  node->key=key;
  node->right=node->left=NULL;
  node->height=1;

  return node;
}

Node *rightRotate(Node* y){
  Node *x=y->left;
  Node *t2=x->right;

  x->right=y;
  y->left=t2;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;

  return x;
}

Node *leftRotation(Node *y){
  Node* l=y->right;
  Node* t2=l->left;

  y->right=t2;
  l->left=y;

  y->height=max(height(y->left),height(y->right))+1;
  l->height=max(height(l->left),height(l->right))+1;

  return l;
}

Node* insert(Node* node,int key){
  if(node==NULL)
    return newnode(key);

  if(key< node->key)
    node->left=insert(node->left,key);
    else if(key> node->key)
      node->right=insert(node->right,key);
    else
      return node;

      node->height=1+max(height(node->left),height(node->right));

      int balance=getBalance(node);

      //left left case
      if(balance>1 && key<node->left->key)
      return rightRotate(node);

      //right right case
      if(balance<-1 && key>node->right->key)
      return leftRotation(node);

      //left right case
      if(balance >1 && key>node->right->key){
        node->left=leftRotation(node->left);
        return rightRotate(node);
      }

      //right left case
      if(balance< -1 && key<node->right->key){
        node->right=rightRotate(node->right);
        return leftRotation(node);
      }

      return node;
}

Node* minValueNode(Node* root){
  Node* temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}

Node* deletenode(Node* root,int key){
  if(root==NULL)
    return NULL;
  else if(key<root->key)
    root->left=deletenode(root->left,key);
  else if(key>root->key)
      root->right=deletenode(root->right,key);

  else{
    if((root->left==NULL) || root->right==NULL){
      Node* temp=root->left?root->left:root->right;

      if(temp==NULL){
        temp=root;
        root=NULL;

      }
      else{
        *root=*temp;
      }
      free(temp);
    }
    else{
      Node* temp=minValueNode(root->right);

      root->key=temp->key;
      root->right=deletenode(root->right,temp->key);

    }
    if(root==NULL)
    return root;

    root->height=1+ max(height(root->left),height(root->right));

    int balance=getBalance(root);


    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotation(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotation(root);
    }

    return root;
  }
}

void preOrder(Node* root){
  if(root!=NULL){
    cout<<root->key<<" ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main(){
  Node *root=NULL;

  root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout<<"preOrder traversal of the avl tree is \n";
    preOrder(root);

    return 0;
}
