#include <iostream>
#include <fstream>
#define Size 1000010

using namespace std;

typedef struct Node {
    int val;
    Node * next;
}node;

node *hTable[Size];

bool exists(int x) {
    int key = abs(x%Size);
    node *p;
    for (p=hTable[key]; p!=NULL; p=p->next) {
        if (p->val == x) {
            return 1;
        }
    }return 0;
}

void insert(int x) {
    int key = abs(x%Size);
    node* a, *b;
    a = new node();
    a->val = x;
    a->next = NULL;
    if (hTable[key] == NULL) {
        hTable[key] = a;
    }
    else{
        for (b=hTable[key]; b->next !=NULL; b=b->next) {
            b->next = a;
        }
    }
}

void deleteNode(int x) {
    int key = abs(x%Size);
    node* a, *b;
    if (hTable[key]->val == x) {
        hTable[key] = hTable[key]->next;
        return;
    }
    for (a = hTable[key]; a->next!=NULL; a=a->next) {
        b = a->next;
        if (b->val == x) {
            a->next = b->next;
            break;
        }
    }
}

int main(){
    for (int i = 0; i < Size; i++){
        hTable[i] = NULL;
    }
    string c;
    int x;
    ifstream fin("set.in");
    ofstream fout("set.out");
    while ( fin >> c ){
        fin >> x;
        if (c == "insert" ){
            if (!exists(x)) {
                insert(x);
            }
        }
        else if (c == "delete" ){
            if (exists(x)) {
                deleteNode(x);
            }
        }
        else if (c == "exists" ){
            if (exists(x)) {
                fout << "true" << endl;
            }else
                fout << "false" << endl;
        }
    }
}
