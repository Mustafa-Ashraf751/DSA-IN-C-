#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }

  ~Node()
  {
  }
};

class LinkedList
{
private:
  Node *head;
  Node *tail;
  int numOfNodes;

public:
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    numOfNodes = 0;
  }

  void add(int num)
  {
    Node *newNode = new Node(num);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      numOfNodes++;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    numOfNodes++;
  }

  void display()
  {
    Node *current = head;
    if (current == NULL)
    {
      cout << "LinkedList is empty!";
      return;
    }

    while (current != NULL)
    {
      cout << current->data << "\t";
      current = current->next;
    }
    cout << endl;
  }

  Node *getNodeUsingData(int data)
  {
    Node *current = head;
    if (current == NULL)
    {
      cout << "LinkedList is empty!";
      return NULL;
    }

    while (current != NULL)
    {
      if (current->data == data)
      {
        return current;
      }
      current = current->next;
    }
    return NULL;
  }

  int remove(int data)
  {
    Node *res = getNodeUsingData(data);
    if (res == NULL)
    {
      return 0;
    }
    if (res == head)
    {
      if (res == tail)
      {
        // Only one element in the list
        head = tail = NULL;
        numOfNodes--;
      }
      // First element in the list
      head = head->next;
      head->prev = NULL;
      numOfNodes--;
    }
    else if (res == tail)
    {
      // Last one case
      tail = tail->prev;
      tail->next = NULL;
      numOfNodes--;
    }
    else
    {
      // Mid case
      Node *first = res->prev;
      Node *after = res->next;
      first->next = after;
      after->prev = first;
      numOfNodes--;
    }
    delete res;
    return 1;
  }

  int getCount()
  {
    return this->numOfNodes;
  }

  void insertAfter(int data, int afterData)
  {
    Node *find = getNodeUsingData(data);
    if (find == NULL)
    {
      cout << "Sorry the node not found please try again" << endl;
      return;
    }

    Node *newNode = new Node(afterData);
    // Find the element after the element i want
    Node *after = find->next;
    if (find == head)
    {
      if (find == tail)
      {
        tail = newNode;
        tail->prev = newNode;
        head->next = newNode;
        numOfNodes++;
      }

      newNode->prev = head;
      head->next = newNode;
      after->prev = newNode;
      newNode->next = after;
      numOfNodes++;
    }
    else if (find == tail)
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
      numOfNodes++;
    }
    else
    {

      find->next = newNode;
      newNode->prev = find;
      after->prev = newNode;
      newNode->next = after;
      numOfNodes++;
    }
  }
  void insertBefore(int data, int beforeData)
  {
    Node *find = getNodeUsingData(data);
    if (find == NULL)
    {
      cout << "Sorry the node not found please try again" << endl;
      return;
    }

    Node *newNode = new Node(beforeData);
    // Find the element after the element i want
    Node *before = find->prev;
    if (find == head)
    {
      if (find == tail)
      {

        head = newNode;
        head->next = newNode;
        tail->prev = newNode;
        numOfNodes++;
      }

      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      numOfNodes++;
    }
    else if (find == tail)
    {
      newNode->next = tail;
      tail->prev = newNode;
      before->next = newNode;
      newNode->prev = before;
      numOfNodes++;
    }
    else
    {

      find->prev = newNode;
      newNode->next = find;
      before->next = newNode;
      newNode->prev = before;
      numOfNodes++;
    }
  }

  int getDataByIndex(int index)
  {
    int currentCounter = 0;
    Node *current = head;
    while (current != NULL)
    {
      if (index == currentCounter)
      {
        return current->data;
      }
      current = current->next;
      currentCounter++;
    }
  }
  /*int removeAll(int data){

  }*/
};

int main()
{

  LinkedList l;
  l.add(50);
  l.add(30);
  l.add(20);
  l.add(10);

  // l.insertAfter(20, 150);
  // l.insertBefore(20, 120);
  // cout << l.getCount() << endl;
  cout << l.getDataByIndex(1) << endl;
  l.display();
  /* l.remove(50);
   l.display();*/

  return 0;
}