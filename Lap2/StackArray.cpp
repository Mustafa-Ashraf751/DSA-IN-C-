#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
  int top;
  int size;
  T *items;

public:
  Stack(int size)
  {
    this->size = size;
    top = -1;
    items = new T[size];
  }

  void push(T value)
  {
    if (top == size - 1)
    {
      throw runtime_error("Sorry the stack is full!");
    }
    top++;
    items[top] = value;
  }

  T pop()
  {
    if (top == -1)
    {
      throw runtime_error("The stack is empty no thing to return");
    }
    return items[top--];
  }

  T peek()
  {
    if (top == -1)
    {
      throw runtime_error("The stack is empty no thing to return");
    }
    return items[top];
  }

  void display()
  {
    if (top == -1)
    {
      cout << "The stack is empty";
    }
    for (int i = top; i >= 0; i--)
    {
      cout << items[i] << "\t";
    }
    cout << endl;
  }

  ~Stack()
  {
    delete[] items;
  }
};

int main()
{
  Stack<int> s(5);
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
    s.display();
    s.pop();
  }
  catch (runtime_error r)
  {
    cout << r.what();
  }

  return 0;
}