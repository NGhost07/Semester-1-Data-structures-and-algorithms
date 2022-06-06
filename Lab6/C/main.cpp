#include <iostream>
#include <fstream>
#include <cstdlib>
#define TABLESIZE 100003

using namespace std;

struct node {
    string key;
    string value;
    int index;
    node* next;
};

node* H_table[TABLESIZE] = {nullptr};
string value_array[100003];
int counter = 0;

int hash_function(string key) {
    int k = 0;
    for (int i=0; i<key.length(); i++) {
        k += ((int)key[i])*(i+1);
    }return k%97;
}
    
string get_command(string key) {
    node* X;
    int k = hash_function(key);
    X = H_table[k];
    if (!X) {
        return "";
    }
    if (X->key == key) {
        return X->value;
    }
    while (X->next) {
        if (X->key == key)
            return X->value;
        X = X->next;
    }
    if (X->key == key) {
        return X->value;
    }
    else {
        return "";
    }
}

void put_command(string key, string value){
    int k = hash_function(key);
    node* X = new node();
    X->key = key;
    X->value = value;
    X->next = nullptr;
    if (H_table[k] == nullptr) {
        H_table[k] = X;
        H_table[k]->index = counter;
        value_array[counter] = value;
        counter++;
    }
    else {
        node* X1;
        X1 = H_table[k];
        while (X1->next) {
            if (X1->key == key) {
                X1->value = value;
                value_array[X1->index] = value;
                return;
            }
            X1 = X1->next;
        }

        if (X1->key != key) {
            X1->next = X;
            X->index = counter;
            value_array[counter] = value;
            counter++;
        }
        else {
            X1->value = value;
            value_array[X1->index] = value;
        }
    }
}

void delete_command(string key) {
    node* X;
    int index_value = hash_function(key);
    X = H_table[index_value];
    if (X == nullptr)
        return;
    if (X->key == key) {
        value_array[H_table[index_value]->index] = "";
        H_table[index_value] = X->next;
        return;
    }
    while (X->next) {
        if (X->next->key == key) {
            value_array[X->next->index] = "";
            X->next = X->next->next;
            return;
        }
        X = X->next;
    }
}

string next_command(string key) {
    int k = hash_function(key);
    node* X = H_table[k];
    if (!X) {
        return "";
    }
    if (X->key == key) {
        for (int i = X->index + 1; i < counter; i++) {
            if (value_array[i] != "") {
                return value_array[i];
            }
        }
        return "";
    }
    while (X->next) {
        if (X->key == key) {
            for (int i = X->index + 1; i < counter; i++) {
                if (value_array[i] != "") {
                    return value_array[i];
                }
            }
            return "";
        }
        X = X->next;
    }
    if (X->key == key) {
        for (int i = X->index + 1; i < 100000; i++) {
            if (value_array[i] != "") {
                return value_array[i];
            }
        }
        return "";
    }
    else {
        return "";
    }
}

string prev_command(string key_value) {
    int index_value = hash_function(key_value);
    node* X = H_table[index_value];
    if (!X) {
        return "";
    }
    if (X->key == key_value) {
        for (int i = X->index - 1; i >= 0; i--) {
            if (value_array[i] != "") {
                return value_array[i];
            }
        }
        return "";
    }
    while (X->next) {
        if (X->key == key_value) {
            for (int i = X->index - 1; i >= 0; i--) {
                if (value_array[i] != "") {
                    return value_array[i];
                }
            }
            return "";
        }
        X = X->next;
    }
    if (X->key == key_value) {
        for (int i = X->index - 1; i >= 0; i--) {
            if (value_array[i] != "") {
                return value_array[i];
            }
        }
        return "";
    }
    else {
        return "";
    }
}

int main() {
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string comm,key,value;
    while (fin >> comm) {
        fin >> key;
        if (comm == "put") {
            fin >> value;
            put_command(key, value);
        }
        else if (comm == "delete")
            delete_command(key);
        else if (comm == "get") {
            value = get_command(key);
            if (value != "") {
                fout << value << "\n";
            }
            else {
                fout << "none" << "\n";
            }
        }
        else if (comm == "next") {
            string next = next_command(key);
            if (next != "") {
                fout << next << "\n";
            }
            else {
                fout << "none" << "\n";
            }
        }
        else if (comm == "prev") {
            string prev = prev_command(key);
            if (prev != "") {
                fout << prev << "\n";
            }
            else {
                fout << "none" << "\n";
            }
        }
    }
    return 0;
}
