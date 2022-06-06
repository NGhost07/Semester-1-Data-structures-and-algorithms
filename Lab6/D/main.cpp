#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#define Size 1000003

using namespace std;

ifstream fin("multimap.in");
ofstream fout("multimap.out");

struct node {
    string key_value;
    vector <vector <string>> key;
    node() {
        key.resize(311); //Когда мы добавляем элемент в key, мы увеличиваем размер
    }
};

struct Multi_map {
    vector <vector <node>> set;
    Multi_map() {
        set.resize(Size); // Когда мы добавляем элемент в set, мы увеличиваем размер
    }
};

Multi_map map;

int hash_function(string key_value, int size) {
    int k ,multi_plier = 1;
    int count = 0;
    for (int i = 0; i < key_value.length(); i++) {
        count += (key_value[i] - 'a' + 1) * multi_plier;
        multi_plier *= 21; // создает пустые позиции в массиве для оптимизации hashTable
    }
    k = abs(count) % size;
    return k;
}

void delete_command(string key_value){
    int k = hash_function(key_value, Size);
    for (auto & i : map.set[k]){
        if (i.key_value == key_value){
            for (auto & j : i.key){ // удалить vector key
                while(!j.empty()){ // удаляйте каждый элемент, пока key не станет пустым
                    j.pop_back();
                }
            }return;
        }
    }
}

void delete_pair_command(string key_value, string value){
    int k = hash_function(key_value, Size);
    for (auto & i: map.set[k]){
        if (i.key_value == key_value){
            int valk = hash_function(value, 311);
            for (int j = 0; j < i.key[valk].size(); j++){
                if (i.key[valk][j] == value){
                    i.key[valk].erase(i.key[valk].begin() + j);
                    return;
                }
            }
        }
    }
}

void put_command(string key_value, string value){
    int k = hash_function(key_value, Size);
    for (auto & i : map.set[k]){
        if (i.key_value == key_value){
            int valk = hash_function(value, 311);
            for (auto & j : i.key[valk]){
                if (j == value){
                    return;
                }
            }
            i.key[valk].push_back(value);
            return;
        }
    }
    node* x1 = new node();
    x1->key_value = key_value;
    x1->key[hash_function(value, 311)].push_back(value);
    map.set[k].push_back(*x1);
    delete(x1);
}


vector<string> get(string key_value){
    vector<string> rest;
    int k = hash_function(key_value, Size);
    for (auto & i: map.set[k]){
        if (i.key_value == key_value){
            for (auto & j: i.key){
                for (auto & k: j){
                    rest.push_back(k);
                }
            }
            return rest;
        }
    }
    return rest;
}

int main() {
    string command,key_value,value;
    while (fin >> command) {
        fin >> key_value;
        if (command == "put") {
            fin >> value;
            put_command(key_value, value);
        }
        else if (command == "deleteall")
            delete_command(key_value);
        else if (command == "get") {
            vector<string> res = get(key_value);
            fout << res.size() << " ";
            for (const string  & i: res)
                fout << i << " ";
            fout << "\n";
        }
        else if (command == "delete") {
            fin >> value;
            delete_pair_command(key_value, value);
        }
    }
    return 0;
}
