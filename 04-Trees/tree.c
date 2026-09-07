#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *right;
    struct node *left;
}node;

node* insert(int num, node *n){

    if(n == NULL){
        n = malloc(sizeof(*n));
        n->number = num;
        n->left = NULL;
        n->right = NULL;
    }
    else if(num < n->number){
        n->left = insert(num, n->left);
    }
    else{
        n->right = insert(num, n->right);
    }
    return n;
}

void print_tree_preorder(node *n){
    if(n != NULL){
        printf(" %d ", n->number);
        print_tree_preorder(n->left);
        print_tree_preorder(n->right);
    }
}

void print_tree_inorder(node *n){
    if(n != NULL){
        print_tree_inorder(n->left);
        printf(" %d ", n->number);
        print_tree_inorder(n->right);
    }
}

void print_tree_postorder(node *n){
    if(n != NULL){
        print_tree_postorder(n->left);
        print_tree_postorder(n->right);
        printf(" %d ",n->number);
    }
}

node* search(int num, node *n){
    if(n == NULL || num == n->number)
    {
        return n;
    }

    if(num < n->number)
    {
        return search(num, n->left);
    }

    return search(num, n->right);

}

node* removeNode(int num, node *n){
    if(n == NULL){
        return n;
    }
    if(num < n->number){
        n->left = removeNode(num, n->left);
    }
    else if(num > n->number){
        n->right = removeNode(num, n->right);
    }
    else{
        if(n->left == NULL){
            node *temp = n->right;
            free(n);
            return temp;
        }
        else if(n->right == NULL){
            node *temp = n->left;
            free(n);
            return temp;
        }

        node *temp = n->right;
        while(temp && temp->left != NULL){
            temp = temp->left;
        }

        n->number = temp->number;
        n->right = removeNode(temp->number, n->right);
    }
    return n;
}

int tree_height(node *n) {
    if (n == NULL) {
        return 0;
    } else {
        int left_height = tree_height(n->left);
        int right_height = tree_height(n->right);
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

void free_tree(node *n) {
    if (n != NULL) {
        free_tree(n->left);
        free_tree(n->right);
        free(n);
    }
}

int main(void) {
    node *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting values into the BST: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(values[i], root);
    }
    printf("\n\n");

    printf("Preorder Traversal : ");
    print_tree_preorder(root);
    printf("\n");

    printf("Inorder Traversal  : ");
    print_tree_inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    print_tree_postorder(root);
    printf("\n\n");

    int target = 40;
    node *found = search(target, root);
    if (found != NULL) {
        printf("Search for %d: Found in the tree!\n", target);
    } else {
        printf("Search for %d: Not found in the tree.\n", target);
    }

    target = 99;
    found = search(target, root);
    if (found != NULL) {
        printf("Search for %d: Found in the tree!\n", target);
    } else {
        printf("Search for %d: Not found in the tree.\n", target);
    }

    printf("\nRemoving 20 from the tree.\n");
    root = removeNode(20, root);
    printf("Inorder Traversal after removing 20: ");
    print_tree_inorder(root);

    printf("\n\nTree height: %d\n", tree_height(root));

    free_tree(root);

    return 0;
}
