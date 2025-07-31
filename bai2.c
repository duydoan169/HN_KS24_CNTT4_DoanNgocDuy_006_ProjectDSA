#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char content[100];
    int isAction;
    struct Node* yesChild;
    struct Node* noChild;
}Node;
Node* createNode(char content[100]) {
    Node* newNode=malloc(sizeof(Node));
    newNode->noChild=NULL;
    newNode->yesChild=NULL;
    strcpy(newNode->content, content);
    return newNode;
}
void startGame(Node* root) {
    if (root==NULL) {
        printf("cay rong\n");
        return;
    }
    Node* current=root;
    getchar();
    while (current!=NULL) {
        char choice[4];
        printf("content: %s\n\n", current->content);
        printf("nhap lua chon cua ban(Yes/No): ");
        fgets(choice, 4, stdin);
        if (strcspn(choice, "\n")==strlen(choice)) {
            while (getchar()!='\n');
        }else {
            choice[strcspn(choice, "\n")]='\0';
        }
        if (strcmp(choice, "yes")==0) {
            current=current->yesChild;
        }else if (strcmp(choice, "No")==0) {
            current=current->noChild;
        }else {
            printf("khong hop le\n\n");
        }
    }
}
void preorder(Node* root) {
    if (root==NULL) {
        return;
    }
    printf("%s \n", root->content);
    preorder(root->yesChild);
    preorder(root->noChild);
}
int main(void) {
    int n;
    Node* root=NULL;
    do {
        printf("\n========MENU========\n");
        printf("1. Bat dau tro choi\n");
        printf("2. Hien thi cay quyet dinh\n");
        printf("3. Them cau hoi/hanh dong\n");
        printf("4. Xoa mot nut trong cay\n");
        printf("5. Thoat\n");
        printf("=====================\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                startGame(root);
                break;
            case 2:
                if (root==NULL) {
                    printf("cay rong\n");
                }else {
                    preorder(root);
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("khong hop le\n");
        }
    }while (n!=5);
    return 0;
}