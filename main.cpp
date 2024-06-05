#include <iostream>
using namespace std;

//Creating a class node as done in the earlier code
class Node{
  public:
    int data;
    Node* next;

    Node () {
     data = 0;
     next = NULL;
    }

    Node (int data) {
    this->data = data;
    next = NULL;
   }
};

//get Length function
int getLength(Node* head) {
  int len = 0;
  while(head != NULL) {
    head = head->next;
    len++;
  }
  return len;
}

//Deleting at head
void deleteatHead(Node* &head) {
  //Step 1
  Node* temp = head;
  //Step 2
  head = head -> next;
  //Step 3
  temp -> next = NULL;
  //Step 4
  delete temp;
}

//Deleting at tail
void deleteatTail(Node* &head) {

  //Step 1
  Node* prev = head;
  Node* temp = head;
  //Step 2 : Find (prev and temp)
  while(temp -> next != NULL) {
    prev = temp;
    temp = temp -> next;
  }
  //Step 3
  prev -> next = NULL;
  //Step 4
  delete temp;
}

void deleteatPos(Node* &head, int pos) {
  //Step 1 : Check empty 
  if(head == NULL) 
    return;
  //Step 2 : Check for the position
  if(pos == 1) {
    deleteatHead(head);
    return;
  }
  else if(pos >= getLength(head)) {
    deleteatTail(head);
    return;
  }

  //Step 3 : Delete at Position

    //subStep 1 : Find prev and curr
    Node* prev = head;
    Node* curr = head;

    //subStep 2 : Find the position
    int i = 0;
    while(i < pos-1) {
      prev = curr;
      curr = curr -> next;
      i++;
    }

    //subStep 3 : prev->next = curr->next
    prev -> next = curr -> next;

    //subStep 4 : curr->next = NULL
    curr -> next = NULL;

    //subStep 5 : delete curr
    delete curr;
}

//Print function as use din previous code
void print ( Node* &head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << " ";
  temp = temp->next;
  }
  cout << endl;
}

int main() {

  //Making a node
  Node* first;
  //Created a node in heap memory
  first = new Node(10);

  Node* second;
  second = new Node(20);
  Node* third;
  third = new Node(30);
  Node* fourth;
  fourth = new Node(40);
  Node* fifth;
  fifth = new Node(50);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;

  print(first);

  deleteatPos(first, 10);
  print(first);

  return 0;
}