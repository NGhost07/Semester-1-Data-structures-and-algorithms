#include <iostream>
#include <fstream>
#include <queue>
#include<vector>
using namespace std;
struct node {
    int value;
    node* left;
    node* right;
};

int The_Height(node* Root_Node){
    if (Root_Node == NULL)
        return 0;
    int Left_side_height = The_Height(Root_Node->left);
    int Right_side_height = The_Height(Root_Node->right);
    return max(Left_side_height, Right_side_height) + 1;
}

int main(){
    ifstream fin("height.in");
    ofstream fout("height.out");

    int n;
    fin >> n;
    if(!n){
        fout << 0;
        return 0;
    }

    vector<pair<int, pair<int, int> > > LINE(n + 1);
    for(int i = 1; i <= n; i++) {
        int value, left_node, right_node;
        fin >> value >> left_node >> right_node;
        LINE[i] = {value, {left_node, right_node}};
    }
    node* root=(node*)malloc(sizeof(node));
    root->value = LINE[1].first;
    root->left = NULL;
    root->right = NULL;
    queue<pair<node*, pair<int, int> > > queue_of_values;
    queue_of_values.push({root, {LINE[1].second.first, LINE[1].second.second}});
    while(queue_of_values.size()) {
        pair<node*, pair<int, int> > x = queue_of_values.front();
        queue_of_values.pop();
        if(x.second.first)
        {
            node* tem_node = (node*)malloc(sizeof(node));
            tem_node->value = LINE[x.second.first].first;
            tem_node->left = NULL;
            tem_node->right = NULL;
            x.first->left = tem_node;
            queue_of_values.push({x.first->left, {LINE[x.second.first].second.first, LINE[x.second.first].second.second}});
        }
        if(x.second.second){
            node* tem_node = (node*)malloc(sizeof(node));
            tem_node->value = LINE[x.second.second].first;
            tem_node->left = NULL;
            tem_node->right = NULL;
            x.first->right = tem_node;
            queue_of_values.push({x.first->right, {LINE[x.second.second].second.first, LINE[x.second.second].second.second}});
        }
    }
    fout << The_Height(root) << endl;
}
