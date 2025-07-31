#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[100];
    struct Node* next;
}Node;
typedef struct Stack {
    Node* top;
}Stack;
typedef struct Queue {
    Node* front;
    Node* rear;
}Queue;
Node* createNode(char title[100]) {
    Node* newNode=malloc(sizeof(Node));
    strcpy(newNode->title, title);
    newNode->next=NULL;
    return newNode;
}
Stack* createStack() {
    Stack* newStack=(Stack*)malloc(sizeof(Stack));
    newStack->top=NULL;
    return newStack;
}
Queue* createQueue() {
    Queue* newQueue=(Queue*)malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->rear=NULL;
    return newQueue;
}
void pushStack(Stack* stack) {
    char title[100];
    getchar();
    printf("nhap ten sach: ");
    fgets(title, 100, stdin);
    if (strcspn(title, "\n")==strlen(title)) {
        while (getchar()!='\n');
    }else {
        title[strcspn(title, "\n")]='\0';
    }
    Node* newNode=createNode(title);
    if (stack->top==NULL) {
        stack->top=newNode;
        return;
    }
    newNode->next=stack->top;
    stack->top=newNode;
}
void popStack(Stack* stack) {
    if (stack->top==NULL) {
        return;
    }
    Node* temp=stack->top;
    stack->top=stack->top->next;
    free(temp);
}
void enqueue(Queue* queue, Stack* stack) {
    if (stack->top==NULL) {
        return;
    }
    if (queue->front==NULL && queue->rear==NULL) {
        queue->front=queue->rear=createNode(stack->top->title);
        return;
    }
    Node* temp=createNode(stack->top->title);
    queue->rear->next=temp;
    queue->rear=temp;
}
void peekStack(Stack* stack) {
    if (stack->top==NULL) {
        printf("khong co sach dang mo\n");
        return;
    }
    printf("thong tin sach gan nhat: \n");
    printf("title: %s\n", stack->top->title);
}
void showStack(Stack* stack) {
    if (stack->top==NULL) {
        printf("khoong co sach dang mo\n");
        return;
    }
    printf("thong tin cac sach dang mo: \n\n");
    Node* current=stack->top;
    while (current!=NULL) {
        printf("title: %s\n\n", current->title);
        current=current->next;
    }
}
void showQueue(Queue* queue) {
    if (queue->front==NULL) {
        printf("khong co sach da dong\n");
        return;
    }
    Node* current=queue->front;
    while (current!=NULL) {
        printf("title: %s\n\n", current->title);
        current=current->next;
    }
}
void dequeue(Queue* queue) {
    if (queue->front==NULL) {
        return;
    }
    Node* temp=queue->front;
    queue->front=queue->front->next;
    if (queue->front==NULL) {
        queue->rear=NULL;
    }
    free(temp);
}
void pushStackQueue(Queue* queue, Stack* stack) {
    Node* newNode=createNode(queue->front->title);
    if (stack->top==NULL) {
        stack->top=newNode;
        return;
    }
    newNode->next=stack->top;
    stack->top=newNode;
}
int main(void) {
    Stack* stack=createStack();
    Queue* queue=createQueue();
    int n;
    do {
        printf("\n========MENU========\n");
        printf("1. Mo sach moi\n");
        printf("2. Dong sach hien tai\n");
        printf("3. Xem sach dang doc gan nhat\n");
        printf("4. Lich su dong sach\n");
        printf("5. Khoi phuc sach\n");
        printf("6. Hien thi sach dang mo\n");
        printf("7. Thoat\n");
        printf("=====================\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                pushStack(stack);
                break;
            case 2:
                if (stack->top==NULL) {
                    printf("khong co sach dang mo\n");
                }else {
                    enqueue(queue, stack);
                    popStack(stack);
                }
                break;
            case 3:
                peekStack(stack);
                break;
            case 4:
                showQueue(queue);
                break;
            case 5:
                if (queue->front==NULL) {
                    printf("khong co sach da dong\n");
                }else {
                    pushStackQueue(queue, stack);
                    dequeue(queue);
                }
                break;
            case 6:
                showStack(stack);
                break;
            case 7:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("khong hop le\n");
        }
    }while (n!=7);
    printf("Hello, World!\n");
    return 0;
}