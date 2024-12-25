#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
  int data;
  Node<T> *Right;
  Node<T> *Left;
  Node(int _data)
  {
    data = _data;
    Right = Left = NULL;
  }
};
template <class U>
class Tree
{
private:
  Node<U> *root;
  Node<U> *getNodeByData(int data)
  {
    Node<U> *current = root;
    while (current != NULL)
    {
      if (data == current->data)
      {
        return current;
      }
      else if (data > current->data)
      {
        current = current->Right;
      }
      else
      {
        current = current->Left;
      }
    }
    return NULL;
  }
  Node<U> *getParent(Node<U> *node)
  {
    Node<U> *parent = root;
    while (parent != NULL)
    {
      if (node == parent->Right || node == parent->Left)
      {
        return parent;
      }
      else if (node->data > parent->data)
      {
        parent = parent->Right;
      }
      else
      {
        parent = parent->Left;
      }
    }
    return NULL;
  }
  Node<U> *getMaxRight(Node<U> *node)
  {
    Node<U> *current = node; // Start Point
    while (current->Right != NULL)
    {
      current = current->Right;
    }
    return current;
  }

  void display(Node<U> *node)
  {
    if (node == NULL)
    {
      return;
    }
    display(node->Left);
    cout << node->data << " : ";
    display(node->Right);
  }

public:
  Tree()
  {
    root = NULL;
  }
  void add(int data)
  {
    // Create Node
    Node<U> *newNode = new Node<U>(data);
    if (root == NULL)
    {
      root = newNode;
    }
    else
    {
      Node<U> *current = root;
      Node<U> *parent = NULL;
      while (current != NULL)
      {
        parent = current; // Before Current Jumping
        if (data > current->data)
        {
          /*if(current->Right == NULL){
              current->Right=newNode;
              return;
          }*/
          current = current->Right; //
        }
        else
        {
          /*if(current->Left == NULL){
              current->Left=newNode;
              return;
          }*/
          current = current->Left;
        }
      }
      if (data > parent->data)
      {
        parent->Right = newNode;
      }
      else
      {
        parent->Left = newNode;
      }
    }
  }
  int findDataInTree(int data)
  {
    if (getNodeByData(data) == NULL)
    {
      return 0;
    }
    return 1;
  }
  int getParentBydata(int data)
  {
    Node<U> *node = getNodeByData(data);
    if (node == root)
    {
      throw "The Node is Root Not Have Parent";
    }
    if (node != NULL)
    {
      Node<U> *parent = getParent(node);
      if (parent != NULL)
      {
        return parent->data;
      }
    }
    else
    {
      throw " Node Not Found , Not Have Parent";
    }
  }
  int getMaxRightByData(int data)
  {
    Node<U> *node = getNodeByData(data);
    if (node == NULL)
    {
      throw " Node Not Found";
    }
    Node<U> *maxR = getMaxRight(node);
    return maxR->data;
  }

  void displayAll()
  {
    display(root);
  }

  void Remove(int data)
  {
    Node<U> *node = getNodeByData(data);
    if (node == nullptr)
    {
      throw runtime_error("The tree is empty nothing to delete!");
    }
    if (node == this->root)
    {
      // This case the node is the root
      if (root->Right == nullptr && root->Left == nullptr)
      {
        this->root = nullptr;
      }
      else if (root->Left == nullptr)
      {
        root = root->Right;
      }
      else if (root->Right == nullptr)
      {
        root = root->Left;
      }
      else
      {
        Node<U> *newRoot = root->Left;
        Node<U> *maxRight = getMaxRight(newRoot);
        maxRight->Right = root->Right;
        root = newRoot;
      }
    }
    else
    {
      // Incase we delete any element except the root node
      // we should have another ptr to track the parent of the node we want to delete
      Node<U> *parent = getParent(node);
      if (node->Left == nullptr && node->Right == nullptr)
      {
        // check where the node to the parent right or left
        if (parent->Left == node)
        {
          parent->Left = nullptr;
        }
        else
        {
          parent->Right = nullptr;
        }
      }
      else if (node->Left == nullptr)
      {
        if (parent->Left == node)
        {
          parent->Left = node->Right;
        }
        else
        {
          parent->Right = node->Right;
        }
      }
      else if (node->Right == nullptr)
      {
        if (parent->Left == node)
        {
          parent->Left = node->Left;
        }
        else
        {
          parent->Right = node->Left;
        }
      }
      else
      {
        // Incase the node has right and left we delete it like we did in root
        Node<U> *newNode = node->Left;
        Node<U> *maxRight = getMaxRight(newNode);
        maxRight->Right = node->Right;
        if (parent->Left == node)
        {
          parent->Left = newNode;
        }
        else
        {
          parent->Right = newNode;
        }
      }
    }
    delete node;
  }

  int findMin()
  {
    if (this->root == NULL)
    {
      throw "The tree is empty no thing to return";
    }
    Node<U> *current = this->root;
    while (current->Left != NULL)
    {
      current = current->Left;
    }
    return current->data;
  }

  int findMax()
  {
    if (this->root == NULL)
    {
      throw "The tree is empty no thing to return";
    }
    Node<U> *current = this->root;
    while (current->Right != NULL)
    {
      current = current->Right;
    }
    return current->data;
  }
};

int main()
{
  Tree<int> t;
  t.add(50);
  t.add(40);
  t.add(70);
  t.add(30);
  t.add(65);
  t.add(60);
  t.add(35);
  t.add(42);
  t.add(45);
  t.add(48);
  t.add(25);
  t.add(22);
  try
  {
    cout << "Minimum element is the tree :" << t.findMin() << endl;
    cout << "Maximum element is the tree :" << t.findMax() << endl;
  }
  catch (const char *msg)
  {
    cout << msg;
  }
  t.displayAll();
  cout << endl;
  t.Remove(40);
  t.displayAll();
  return 0;
}
