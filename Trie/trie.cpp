#include<bits/stdc++.h>
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define read(x) int x; cin>>x
#define readll(x) ll x; cin>>x
#define strr(str) string str; cin>>str

//Aliases
using ll= long long;
using lld= long double;
using ull= unsigned long long;
 
//Constants
const lld pi= 3.141592653589793238;
const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7;

//speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Champion cout.tie(NULL);


using namespace std;

class TrieNode{
   public:
     char data;
     TrieNode* children[26];
     bool isTerminal;

     TrieNode(char ch){
       data = ch;
       for(int i = 0; i<26; i++){
        children[i] = NULL;
       }
       isTerminal = false;
     }
};

class Trie{
  public:
  TrieNode* root;

  Trie(){
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode* root, string word){
       if(word.length() == 0){
         root->isTerminal = true;
         return;
       }
       // words will be in CAPS
       int idx = word[0] - 'A';
       TrieNode* child;

       if(root->children[idx] != NULL){
        child = root->children[idx];
       }
       else{
        child = new TrieNode(word[0]);
        root->children[idx] = child;
       }
       
       insertUtil(child, word.substr(1));

  }
  void insertWord(string word){
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode* root, string word){
       if(word.length() == 0){
        return root->isTerminal;
       }

       int idx = word[0] - 'A';

       TrieNode* child;
       if(root->children[idx] != NULL){
         child = root->children[idx];
       }
      else{
        return false;
      }
      
      return searchUtil(child, word.substr(1));

  }

  bool searchWord(string word){
    return searchUtil(root, word);
  }
  

};
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}



int main(){
    init_code();
    Code By Champion
    
    Trie *t = new Trie();
    t->insertWord("abcd");
    cout<<"Present or Not" <<" "<< t->searchWord("abcde")<<'\n';
    return 0;
}