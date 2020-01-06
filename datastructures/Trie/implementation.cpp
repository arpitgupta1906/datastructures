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

int main(){
  string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0; 
}
