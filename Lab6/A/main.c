#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
FILE *fin;
FILE *fout;

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct node* root = NULL;

struct node* newNode(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->l = temp->r = NULL;
    return temp;
}

int findMin(struct node* root){
    while (root->l != NULL) {
        root = root->l;
    }return root->data;
}

bool Exists(struct node* root, int x){
    if (root == NULL) {
        return false;
    }else if (x == root->data){
        return true;
    }else if (x < root->data){
        return Exists(root->l, x);
    }else if (x > root->data){
        return Exists(root->r, x);
    }return 0;
}

struct node* Insert(struct node* root, int x){
    if (root == NULL) {
        return newNode(x);
    }else if (x<root->data){
        root->l = Insert(root->l, x);
    }else if (x>root->data){
        root->r = Insert(root->r, x);
    }return root;
}

struct node* Delete(struct node* root, int x){
    if (!Exists(root, x)) {
        return root;
    }else if (x < root->data){
        root->l = Delete(root->l, x);
    }else if (x > root->data){
        root->r = Delete(root->r, x);
    }else{
        if (root->l == NULL) {
            struct node* newRoot = root->r;
            free(root);
            return newRoot;
        }
        if (root->r == NULL) {
            struct node* newRoot = root->l;
            free(root);
            return newRoot;
        }
        root->data = findMin(root->r);
        root->r = Delete(root->r, root->data);
    }return root;
}

int main() {
    fin = fopen("set.in", "r");
    fout = fopen("set.out", "w");
    char c;
    int x;
    while ((c=getc(fin)) != EOF) {
        if (c=='i') {
            while((fgetc(fin))!=' ');
            fscanf(fin, "%d", &x);
            root = Insert(root, x);
        }
        else if (c=='e') {
            while ((fgetc(fin))!=' ');
            fscanf(fin, "%d", &x);
            if (Exists(root, x)) {
                fprintf(fout, "true\n");
            }else
                fprintf(fout, "false\n");
        }
        else if (c=='d') {
            while((fgetc(fin))!=' ');
            fscanf(fin, "%d", &x);
            root = Delete(root, x);
        }
    }
    return 0;
}
