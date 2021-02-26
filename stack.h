
#ifndef stack_h
#define stack_h
#include "node.h"

typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;

void push(StackPtr s, char value){
  NodePtr first = (NodePtr)malloc(sizeof(NodePtr));
  if(first){
    first->data=value;
    first->nextPtr= s->top;
    s->size += 1;
    s->top = first;
  } 
}

char pop(StackPtr s){
  
  char value;
  NodePtr t = s->top;
  if(s->top!=NULL){

    value=t->data;
    s->top = t->nextPtr;

  }
  
  free(t);
  s->size -= 1;

  return value;

}

void pop_all(StackPtr s){
  char value;
  while(s->size != 0){
    value = pop(s);
    printf("popping %c \n",value);
  }
}

#endif
