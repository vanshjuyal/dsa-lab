#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int data){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=top;
    top=p;
}
void peek(){
    if(top==NULL){
        printf("no ele\n");
    }
    else{
        printf("%d\n",top->data);
    }
}
void pop(){
    if(top==NULL){
        printf("underflow\n");
    }
    else{
        struct node*d=top;
        top=top->next;
        printf("%d\n",d->data);
        free(d);
    }
}
void display(){
    if(top==NULL){
        printf("no ele\n");
    }
    else{
        struct node*t=top;
        while(t!=NULL){
            printf("%d\n",t->data);
            t=t->next;
        }
    }
}
void main(){
    push(8);
    push(80);
    push(100);
    display();
}
