#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
};
bool check(struct Node* root, Node *pre){
    if (root){
        if (!check(root->left, pre))
          return false;
        if (pre != NULL && root->value <= pre->value)
          return false;
        pre = root;
        return check(root->right, pre);
    }
    return true;
}

bool is_BST(Node *root){
   Node *pre = NULL;
   return check(root, pre);
}

int main(){
    ifstream fin("check.in");
    ofstream fout("check.out");
    int N;
    fin>>N;
    if(!N) {
        fout << "YES";
        return 0;
    }
    vector<pair<int, pair<int, int> > > line(N + 1);
    for(int i = 1; i <= N; i++) {
        int value, left, right;
        fin >> value >> left >> right;
        line[i] = {value, {left, right}};
    }
    
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = line[1].first;
    root->left = NULL;
    root->right = NULL;
    queue<pair<Node*, pair<int, int> > > q;
    q.push({root, {line[1].second.first, line[1].second.second}});
    while(q.size()){
        pair<Node*, pair<int, int> > x = q.front();
        q.pop();
        if(x.second.first){
            Node* temp_Node = (Node*)malloc(sizeof(Node));
            temp_Node->value = line[x.second.first].first;
            temp_Node->left = NULL;
            temp_Node->right = NULL;
            x.first->left = temp_Node;
            q.push({x.first->left, {line[x.second.first].second.first, line[x.second.first].second.second}});
        }
        if(x.second.second){
            Node* temp_Node = (Node*)malloc(sizeof(Node));
            temp_Node->value = line[x.second.second].first;
            temp_Node->left = NULL;
            temp_Node->right = NULL;
            x.first->right = temp_Node;
            q.push({x.first->right, {line[x.second.second].second.first, line[x.second.second].second.second}});
        }
    }
       if (is_BST(root))
        fout << "YES";
    else
        fout << "NO";
}
