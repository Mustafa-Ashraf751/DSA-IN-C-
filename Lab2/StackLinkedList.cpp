#include <iostream>

using namespace std;

template <class U>
class StackNode
{
public:
  StackNode<U> *prev;
  U data;

  StackNode(U data)
  {
    this->data = data;
    prev = NULL;
  }
};

template <class T>
class Stack
{
private:
  StackNode<T> *tail;

public:
  Stack()
  {
    tail = NULL;
  }

  void push(T value)
  {
    StackNode<T> *newNode = new StackNode<T>(value);
    if (tail == NULL)
    {
      tail = newNode;
      return;
    }
    newNode->prev = tail;
    tail = newNode;
  }

  T pop()
  {
    if (tail == NULL)
    {
      throw runtime_error("The stack is empty no thing to return");
    }

    StackNode<T> *temp = tail;
    T data = tail->data;
    tail = tail->prev;
    delete temp;
    return data;
  }

  T peek()
  {
    if (tail == NULL)
    {
      throw runtime_error("The stack is empty no thing to return");
    }
    return tail->data;
  }

  void display()
  {
    if (tail == NULL)
    {
      throw runtime_error("The stack is empty no thing to display");
    }
    StackNode<T> *current = tail;
    while (current != NULL)
    {
      cout << current->data << "\t";
      current = current->prev;
    }
    cout << endl;
  }
};

int main()
{
  Stack<int> s;
  try
  {
    s.push(25);
    s.push(50);
    s.push(60);
    s.push(85);
    s.push(105);
    cout << s.peek() << endl;
    cout << s.peek() << endl;
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    // s.display();
    s.pop();
  }
  catch (runtime_error r)
  {
    cout << r.what();
  }

  return 0;
}