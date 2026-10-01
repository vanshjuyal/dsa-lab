#include<stdio.h>
int arr[100];
int top=-1;
void push(int x){
    top++;
    if(top==100){
        printf("overflow\n");
        top--;
    }
    else{
        arr[top]=x;
            }
}
void peek(){
    if(top==-1){
        printf("no ele\n");
    }
    else{
    printf("%d\n",arr[top]);
        }
}
void pop(){
    if(top==-1){
        printf("underflow\n");
    }
    else{
        printf("%d\n",arr[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("no ele\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",arr[i]);
        }
    }
}
void main(){
    push(5);
    push(19);
    push(34);
    push(89);
    pop();
    display();
    display();
}
