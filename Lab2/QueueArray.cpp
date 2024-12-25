#include <iostream>

using namespace std;

template <class T>
class Queue
{
  int size;
  int front;
  int rear;
  T *items;

public:
  Queue(int size)
  {
    this->size = size;
    front = -1;
    rear = -1;
    items = new T[size];
  }

  int isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      return 1;
    }
    return 0;
  }

  int isFull()
  {
    if (front == 0 && rear == size - 1)
    {
      return 1;
    }
    if (rear == front - 1) // after filling the array and full it from the start
    {
      return 1;
    }
    return 0;
  }

  void enqueue(T value)
  {
    if (isFull())
    {
      throw runtime_error("The queue is full please try again later");
    }
    if (isEmpty())
    {
      front = rear = 0;
    }
    else if (rear == size - 1)
    {
      rear = 0;
    }
    else
    {
      rear++;
    }
    items[rear] = value;
  }

  T dequeue()
  {
    if (isEmpty())
    {
      throw runtime_error("The queue is empty no thing to return");
    }
    T data = items[front];
    if (rear == front)
    {
      rear = front = -1;
    }
    else if (front == size - 1) // won't make front 0 and rear not bigger that it
    {
      front = 0;
    }
    else
    {
      front++;
    }
    return data;
  }

  T getFront()
  {
    if (isEmpty())
    {
      throw runtime_error("The queue is empty no thing to return");
    }
    return items[front];
  }

  T getRear()
  {
    if (isEmpty())
    {
      throw runtime_error("The queue is empty no thing to return");
    }
    return items[rear];
  }

  void display()
  {
    if (isEmpty())
    {
      throw runtime_error("The queue is empty no thing to display");
    }

    for (int i = front; i < size; i++)
    {
      cout << items[i] << "\t";
    }
    if (front != 0)
    {
      for (int j = 0; j <= rear; j++)
      {
        cout << items[j] << "\t";
      }
    }
    cout << endl;
  }
};

int main()
{
  try
  {
    Queue<int> q(5);

    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    /* cout << q.getFront() << endl;
     cout << q.getRear() << endl;
     q.display();
     cout << q.dequeue() << endl;
     cout << q.dequeue() << endl;
     q.enqueue(70);
     q.enqueue(80);
     cout << q.getFront() << endl;
     cout << q.getRear() << endl;*/
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    q.display();
  }
  catch (runtime_error r)
  {
    cout << r.what() << endl;
  }

  return 0;
}