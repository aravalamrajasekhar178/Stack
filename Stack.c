#include<stdio.h>
#include<stdlib.h>
struct Stack{
    unsigned capacity;
    int top;
    int* arr;
};
struct Stack* create(int capacity){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->capacity=capacity;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int));
    return s;
}
int isFull(struct Stack* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
void push(struct Stack* s,int val){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->arr[s->top]=val;
    printf("%d is added to the Stack successfully\n");
}
void pop(struct Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("%d is removed from the Stack successfully\n",s->arr[s->top]);
    s->top--;
}
void peek(struct Stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Element at Top of the Stack: ");
    printf("%d\n",s->arr[s->top]);
}
void print(struct Stack* s){
    int x=s->top;
    printf("Stack elements from top to bottom\n");
    while(x>-1){
        printf("%d\t",s->arr[x]);
        x--;
    }
    printf("\n");
}
int main(){
    int size;
    printf("Enter the Stack size: ");
    scanf("%d",&size);
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Printing the stack from top to bottom\n");
    printf("Other than this: Exit\n");
    struct Stack* s=create(size);
    while(1){
        int n,val,flag=0;
        printf("Select your option:\n");
        scanf("%d",&n);
        switch(n){
        case 1:if(s->top==s->capacity-1){
                  printf("Stack is full\n");
               }else{
               printf("Enter the element to push into the Stack: ");
               scanf("%d",&val);
               push(s,val);
               }
               break;
        case 2:pop(s);
               break;
        case 3:peek(s);
               break;
        case 4:print(s);
               break;
        default:flag=1;
                break;
    }
    if(flag==1){
        break;
    }
            
    }
}