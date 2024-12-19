#include <iostream>

using namespace std;

template <class U>
class QueueNode
{
public:
  U data;
  QueueNode<U> *next;
  QueueNode(U data)
  {
    this->data = data;
    next = NULL;
  }
};

template <class T>
class Queue
{
  QueueNode<T> *front;
  QueueNode<T> *rear;

public:
  Queue()
  {
    front = NULL;
    rear = NULL;
  }

  void enqueue(T value)
  {
    QueueNode<T> *newNode = new QueueNode<T>(value);
    if (front == NULL && rear == NULL)
    {
      front = newNode;
      rear = newNode;
      return;
    }
    rear->next = newNode;
    rear = newNode;
  }

  T dequeue()
  {
    int data = 0;
    if (front == NULL)
    {
      throw runtime_error("The queue is empty");
    }
    QueueNode<T> *temp = front;
    data = front->data;
    front = front->next;
    // To make sure that the rear won't point to null
    if (front == NULL)
    {
      rear = NULL;
    }
    delete temp;
    return data;
  }

  T getFront()
  {
    if (front == NULL)
    {
      throw runtime_error("The queue is empty");
    }
    return this->front->data;
  }

  T getRear()
  {
    if (rear == NULL)
    {
      throw runtime_error("The queue is empty");
    }
    return this->rear->data;
  }

  void display()
  {
    if (front == NULL)
    {
      throw runtime_error("The queue is empty no thing to display");
    }
    QueueNode<T> *current = front;
    while (current != NULL)
    {
      cout << current->data << "\t";
      current = current->next;
    }
    cout << endl;
  }
};

int main()
{
  try
  {
    Queue<int> q;

    q.enqueue(50);
    q.enqueue(65);
    q.enqueue(78);
    q.enqueue(100);
    q.enqueue(160);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
  }
  catch (runtime_error r)
  {
    cout << r.what() << endl;
  }

  return 0;
}