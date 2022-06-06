#include <iostream>
#include <fstream>
#include <string>
#define Size 100003

using namespace std;

struct node {
    string key;
    string data;
    node* next;
};

node* hTable[Size] = {nullptr};

int hash_key (string key){
    int k = 0;
    for (int i=0; i<key.length(); i++) {
        k += ((int)key[i])*(i+1);
    }return k%97;
}

node* search_key(string key){
    int k = hash_key(key);
    node* p = hTable[k];
    while (p!=nullptr && p->key != key) {
        p = p->next;
    }
    if (p == nullptr) {
        return nullptr;
    }return p;
}

string get_command(string key){
    if (search_key(key)) {
        return search_key(key)->data;
    }return "none";
}

void put_command(string key, string data){
    node* p = search_key(key);
    int k = hash_key(key);
    if (p!=nullptr) {
        p->data = data;
        return;
    }else{
        node* p1 = new node();
        p1->key = key;
        p1->data = data;
        p1->next = nullptr;
        if (hTable[k] == nullptr) {
            hTable[k] = p1;
        }else{
            p1->next = hTable[k];
            hTable[k] = p1;
        }return;
    }
}

void delete_command(string key){
    int k = hash_key(key);
    node* p = hTable[k];
    node* p1 = nullptr;
    while (p != nullptr && p->key != key) {
        p1 = p;
        p = p->next;
    }
    if (p == nullptr) {
        return;
    }
    else if (p == hTable[k]){
        hTable[k] = hTable[k]->next;
    }else
        p1->next = p->next;
}

int main(){
    ifstream fin("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6B/map.in");
    ofstream fout("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6B/map.out");
    string command, key, data;

    while (fin >> command) {
        string key, data;
        if (command == "put") {
            fin >> key >> data;
            put_command(key, data);
        }
        if (command == "delete") {
            fin >> key;
            delete_command(key);
        }
        if (command == "get") {
            fin >> key;
            fout << get_command(key) << endl;
        }
    }
    return 0;
}
///Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6B
