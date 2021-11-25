#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
  char data;
  struct list_node *next;
} Node;

Node *find(Node *head, char item);
void append(Node *head, char data);
char get(Node *head, int index);
int length(Node *head);
void printList(Node *head);

int main(void){
  Node *head;
  head = malloc(sizeof(Node));
  head->data='A';
  head->next=NULL;

  append(head,'B');
  append(head,'C');
  append(head,'D');
  append(head,'E');

  printList(head);
  printf("D: %p\n",find(head,'D'));
  printf("Len: %i\n",length(head));
  printf("Pos 1: %c\n",get(head,1));

  return 0;
}


void append(Node *head, char data){
  if (head->next == NULL){
    head->next = malloc(sizeof(Node));
    head->next->data = data;
    head->next->next = NULL;
  }
  else{
    append(head->next, data);
  }
}


Node *find(Node *head, char item){

  if(head->data == item){
    return head;
  }

  else if (head->next == NULL){
    return NULL;
  }

  return find(head->next, item);
}


int length(Node *head){
  int length = 1;
  Node *current_node = head;
  while (current_node->next != NULL){
    length++;
    current_node = current_node -> next;
  }
  return length;
}


char get(Node *head, int index){
  
  if (index < 0 || head == NULL){
    return '\0';
  }
  else if (index == 0){
    return head->data;
  }

  return get(head->next, index - 1);
}


void printList(Node *head){
  
  Node *current_node = head;
  printf("[") ;
  
  while (current_node != NULL){
    printf("%c",current_node->data);
    
    if (current_node->next != NULL){
      printf(", ");
    }
    current_node = current_node -> next;
  }
  
  printf("]\n");
}