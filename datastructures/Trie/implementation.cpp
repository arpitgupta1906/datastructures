#include <bits/stdc++.h>
using namespace std;


struct TrieNode{
  struct TrieNode *children[26];
  bool isEndOfWord;
};

struct TrieNode* getNode(void){
  struct TrieNode* temp=new TrieNode;
  temp->isEndOfWord=false;
  for(int i=0;i<26;i++){
    temp->children[i]=NULL;
  }

  return temp;
}

void insert(struct TrieNode *root,string key){
  struct TrieNode *temp=root;

  for(int i=0;i<key.size();i++){
    int index=key[i]-'a';

    if(!temp->children[index])
        temp->children[index]=getNode();

    temp=temp->children[index];
  }

  temp->isEndOfWord=true;
}


bool search(struct TrieNode* root,string key){
  struct TrieNode* temp=root;

  for(int i=0;i<key.size();i++){
    int index=key[i]-'a';

    if(!temp->children[index])
      return false;

    temp=temp->children[index];
  }

  return (temp!=NULL && temp->isEndOfWord);
}

bool isEmpty(TrieNode* root){
  for(int i=0;i<26;i++){
    if(root->children[i])
      return false;
  }
  return true;
}

struct TrieNode* remove(TrieNode* root,string key,int depth=0){
  if(!root)
    return NULL;

  if(depth==key.size()){
    if(root->isEndOfWord)
      root->isEndOfWord=false;

    if(isEmpty(root)){

      delete(root);
      root=NULL;
    }
    return root;
  }

  int index=key[depth]-'a';
  root->children[index]=remove(root->children[index],key,depth+1);

  if(isEmpty(root) && root->isEndOfWord==false)
    {
      delete(root);
      root=NULL;
    }
    return root;
}

int wordCount(struct TrieNode* root){
  int result=0;

  if(root->isEndOfWord)
    result++;

  for(int i=0;i<26;i++){
    if(root->children[i])
      result+=wordCount(root->children[i]);
  }

    return result;
}

void display(struct TrieNode* root,char str[],int level=0){
  if(root->isEndOfWord){
    str[level]='\0';
    cout<<str<<endl;
  }

  for(int i=0;i<26;i++){
    if(root->children[i]){
      str[level]=i+'a';
      display(root->children[i],str,level+1);
    }
  }
}

int main(){
  string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();


    for (int i = 0; i < n; i++)
        insert(root, keys[i]);


    search(root, "the")? cout << "Yes\n" : cout << "No\n";
    search(root, "these")? cout << "Yes\n" :cout << "No\n";

    remove(root,"the");
    char str[20];
    display(root,str);
    return 0;
}
