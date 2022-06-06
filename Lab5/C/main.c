#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fin;
FILE *fout;

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct node* root = NULL;

struct node* newNode (int x){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data=x;
    node->l=NULL;
    node->r=NULL;
    return (node);
}

int LeftMostValue( struct node* root ){
    while ( root->l != NULL )
        root = root->l;
    return root->data;
}

int LeftOf( const int value, const struct node* root ){
    return value < root->data;
}

int RightOf( const int value, const struct node* root ){
    return value > root->data;
}

bool Search( const struct node* root, int value ){
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->l, value );
    }else if( RightOf( value, root ) ){
        return Search( root->r, value );
    }return 0;
}

struct node* insert(struct node* root, int x){
    if (Search(root, x)) {
        return 0;
    }
    if(root==NULL){
        return(newNode(x));
    }
    else{
        if(x < root->data){
            root->l =insert(root->l,x);
        }
        else{
            root->r=insert(root->r,x);
        }
        return(root);
    }
}

struct node* find_min(struct node* root)
{
    while(root->l != NULL) root = root->l;
    return root;
}

struct node* delete(struct node *root, int value){

    if(root == NULL) return root;
    else if(value < root->data) root->l = delete(root->l, value);
    else if (value > root->data) root->r = delete(root->r, value);
    else {
        if(root->l == NULL && root->r == NULL) {
            root = NULL;
        }
        else if(root->l == NULL) {
            struct node *temp = root;
            root = root->r;
            temp = NULL;
        }
        else if(root->r == NULL) {
            struct node *tem = root;
            root = root->l;
            tem = NULL;
        }
        else {
            struct node *temp = find_min(root);
            root->data = temp->data;
            root->r = delete(root->r, temp->data);
        }
    }
    return root;
}

struct node* next(int x){
    struct node* cur = root;
    struct node* res = NULL;
    while (cur != NULL) {
        if (cur->data > x) {
            res = cur;
            cur = cur->l;
        }else{
            cur = cur->r;
        }
    }return res;
}

struct node* prev(int x){
    struct node* cur = root;
    struct node* res = NULL;
    while (cur != NULL) {
        if (cur->data < x) {
            res = cur;
            cur = cur->r;
        }else{
            cur = cur->l;
        }
    }return res;
}

int main() {
    fin = fopen("bstsimple.in", "r");
    fout = fopen("bstsimple.out", "w");
    char s;
    int x;
    while ((s = fgetc(fin)) != EOF) {
        if (s == 'i') {
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            root = insert(root, x);
        }
        else if (s == 'e') {
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            if (Search(root, x)) {
                fprintf(fout, "true\n");
            }else
                fprintf(fout, "false\n");
        }
        else if (s == 'd'){
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            root = delete(root, x);
        }
        else if (s == 'n'){
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            if (next(x) == NULL) {
                fprintf(fout, "none\n");
            }else{
                struct node* res = next(x);
                fprintf(fout, "%d\n", res->data);
            }
        }
        else if (s == 'p'){
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            if (prev(x) == NULL) {
                fprintf(fout, "none\n");
            }else{
                struct node* res = prev(x);
                fprintf(fout, "%d\n", res->data);
            }
        }
    }
    return 0;
}
