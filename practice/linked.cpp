
#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node* next;
};

void print(Node* n)
{
  while(n != 0)
  {
    cout << n->data << endl;
    n = n->next;
  }
}

void insert (Node** head_ref, int value)
{
  Node* head = *head_ref;
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = NULL;

  if(*head_ref == NULL)
  {
    *head_ref = new_node;

  }
  else 
  {
    while(head->next != NULL)
    {
      head = head->next;
    }
    head->next = new_node;
  }
}

int main()
{
  Node* head = NULL;
  insert(&head, 6);
  insert(&head, 7);  
  insert(&head, 9);
  insert(&head, 56);
  insert(&head, 14);
  insert(&head, 3);  
  print(head);
  return 0;
}
