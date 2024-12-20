#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
  T data;
  Node<T> *next;
  Node<T> *prev;

  Node(T data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }

  ~Node()
  {
  }
};

template <class U>
class LinkedList
{
private:
  Node<U> *head;
  Node<U> *tail;
  int numOfNodes;

public:
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    numOfNodes = 0;
  }

  void add(U num)
  {
    Node<U> *newNode = new Node<U>(num);
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
    Node<U> *current = head;
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

  Node<U> *getNodeUsingData(U data)
  {
    Node<U> *current = head;
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

  int remove(U data)
  {
    Node<U> *res = getNodeUsingData(data);
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
      Node<U> *first = res->prev;
      Node<U> *after = res->next;
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

  void insertAfter(U data, U afterData)
  {
    Node<U> *find = getNodeUsingData(data);
    if (find == NULL)
    {
      cout << "Sorry the node not found please try again" << endl;
      return;
    }

    Node<U> *newNode = new Node<U>(afterData);
    // Find the element after the element i want
    Node<U> *after = find->next;
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
    Node<U> *find = getNodeUsingData(data);
    if (find == NULL)
    {
      cout << "Sorry the node not found please try again" << endl;
      return;
    }

    Node<U> *newNode = new Node<U>(beforeData);
    // Find the element after the element i want
    Node<U> *before = find->prev;
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
    Node<U> *current = head;
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

  LinkedList linearSearch(U value)
  {

    int counter = 0;
    int flag = 1;
    LinkedList<U> l;
    Node<U> *current = head;
    if (current == NULL)
    {
      cout << "The list is empty element not found";
    }
    else
    {
      while (current != NULL)
      {
        if (current->data == value)
        {
          flag = 0;
          l.add(counter);
        }
        current = current->next;
        counter++;
      }
      if (flag)
      {
        cout << "Element not found please try again" << endl;
      }
    }
    return l;
  }

  int binarySearch(U value)
  {
    int start = 0;
    int end = getCount() - 1;
    int mid = (start + end) / 2;
    int iteration = 0;
    Node<U> *current = head;
    while (start <= end)
    {
      if (getDataByIndex(mid) == value)
      {
        cout << "Number of iteration is " << iteration << endl;
        cout << "Number found at " << mid << endl;
        return mid;
      }
      else if (getDataByIndex(mid) < value)
      {
        start = mid + 1;
      }
      else if (getDataByIndex(mid) > value)
      {
        end = mid - 1;
      }
      mid = (start + end) / 2;
      iteration++;
    }
    cout << "Element not found !" << endl;
    cout << "Number of iteration is " << iteration << endl;
    return -1;
  }

  void swapNodes(Node<U> *node1, Node<U> *node2)
  {
    if (node1 == node2)
    {
      return;
    }

    Node<U> *prevNode1 = node1->prev;
    Node<U> *nextNode2 = node2->next;

    if (prevNode1 != NULL)
    {
      prevNode1->next = node2;
    }
    if (nextNode2 != NULL)
    {
      nextNode2->prev = node1;
    }

    node1->next = nextNode2;
    node2->prev = prevNode1;

    node1->prev = node2;
    node2->next = node1;

    if (node1 == head)
    {
      head = node2;
    }
    if (node2 == tail)
    {
      tail = node1;
    }
  }

  void bubbleSort()
  {
    if (head == NULL || head->next == NULL)
    {
      cout << "List can't be sorted it's too short." << endl;
      return;
    }
    Node<U> *current = head;
    int size = getCount();
    for (int i = 0; i < size - 1; i++)
    {
      current = head;
      for (int j = 0; j < size - 1 - i; j++)
      {
        if (current->data > current->next->data)
        {
          swapNodes(current, current->next);
        }
        else
        {
          current = current->next;
        }
      }
    }
  }
};

int main()
{

  LinkedList<int> l;
  /*l.add(10);
  l.add(20);
  l.add(30);
  l.add(40);
  l.add(50);
  LinkedList result = l.linearSearch(10);
  result.display();
  l.binarySearch(30);*/
  l.add(50);
  l.add(40);
  l.add(30);
  l.add(20);
  l.add(10);
  l.display();
  l.bubbleSort();
  l.display();
  return 0;
}