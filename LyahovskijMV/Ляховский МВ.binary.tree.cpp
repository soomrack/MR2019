#include <iostream>

using namespace std;

class Node
{
public:
   int data;                              //information in node
   Node *parent;                          //address of parent node
   Node *LeftChild;                       //address of left node (data is less than parent data)
   Node *RightChild;                      //address of right node (data is more than parent data)

//create new node with stored data
   Node(int data)
   {
      this->data = data;
      parent = nullptr;
      LeftChild = nullptr;
      RightChild = nullptr;

      cout << "Node constructor" << endl;
   }
};

class Tree
{
public:
   //pointer to root node of the tree
   Node *root;

   //tree constructor, root node has not created yet
   Tree()
   {
      root = nullptr;

      cout << "Tree constructor" << endl;
   }

   //adds new node to the tree
   void AddNode(int data);

   //delete node from tree
   void DeleteNode(int data);
   
   //find address of node with data
   Node *FindNode(Node *address, int data);

private:
   //find address of node for new child
   Node *find_parent_for_new_child(int NewData, Node *CurrentSearchNodeAddress);

   //find address node with the smallest data
   Node *FindMin(Node *address);
   Node *FindMax(Node* address);
};

void Tree::AddNode(int data)
{
   //if we dont have root -> create root and return
   if (root == nullptr)
   {
      root = new Node(data);
      return;
   }

   //create pointer to new child
   Node *NewChild = new Node(data);

   //create pointer to parent and find appropriate node
   Node *Parent = find_parent_for_new_child(data, root);

   NewChild->parent = Parent;

   //if new data <= parent data
   if (data <= Parent->data)
   {
      //set new child's address to left child pointer of parent
      Parent->LeftChild = NewChild;
   }
   else
   {
      Parent->RightChild = NewChild;
   }
}

Node *Tree::find_parent_for_new_child(int NewData, Node *CurrentSearchNodeAddress)
{
   //here we have to find first empty left/right child pointer of node

   //if new data less than data of current node in search
   if (NewData <= CurrentSearchNodeAddress->data)
   {
      //if pointer to left child is empty 
      if (CurrentSearchNodeAddress->LeftChild == nullptr)
      {
         //return current search address node
         return CurrentSearchNodeAddress;
      }
      else
      {
         //search deep
         return find_parent_for_new_child(NewData, CurrentSearchNodeAddress->LeftChild);
      }
   }
   else
   {
      //if pointer to left child is empty 
      if (CurrentSearchNodeAddress->RightChild == nullptr)
      {
         //return current search address node
         return CurrentSearchNodeAddress;
      }
      else
      {
         //search deep
         return find_parent_for_new_child(NewData, CurrentSearchNodeAddress->RightChild);
      }
   }
}

void Tree::DeleteNode(int data)
{
   Node *RemovedNode = FindNode(root, data);
   Node *ParentOfRemovedNode = RemovedNode->parent;

   //if removing data is left child
   if (data < ParentOfRemovedNode->data)
   {
      //set right child of removed node to left child of removed node parent
      ParentOfRemovedNode->LeftChild = RemovedNode->RightChild;

      //lowest node from right child of removed node
      Node *LowestNode = FindMin(RemovedNode->RightChild);

      //set left child of removed node to left child of the lowest node from removed one :)
      LowestNode->LeftChild = RemovedNode->LeftChild;

      //delete node and set memory free
      delete RemovedNode;
   }
   else if (data > ParentOfRemovedNode->data)
   {
      //set right child of removed node to rgith child of removed node parent
      ParentOfRemovedNode->RightChild = RemovedNode->RightChild;

      //lowest node from right child of removed node
      Node *LowestNode = FindMin(RemovedNode->RightChild);

      //set left child of removed node to left child of the lowest node from removed one :)
      LowestNode->LeftChild = RemovedNode->LeftChild;

      //delete node and set memory free
      delete RemovedNode;
   }
}

Node *Tree::FindNode(Node *address, int data)
{
   //if we dont have root
   if (root == nullptr)
   {
      return root;
   }      
   
   //if we fonud equal data
   if (data == address->data)
   {
      return address;
   }
   //if data less that current node data
   else if (data < address->data)
   {
      //search deep
      return FindNode(address->LeftChild, data);
   }   
   //if data more than current node data
   else if (data > address->data)
   {
      //search deep
      return FindNode(address->RightChild, data);
   }
}

Node *Tree::FindMin(Node * address)
{
   //if left child of current node is empty
   if (address->LeftChild == nullptr)
   {
      //we found lowest node -> return its address
      return address;
   }      
   else
   {
      //search deep
      return FindMin(address->LeftChild);
   }      
}

Node* Tree::FindMax(Node* address)
{
   //if right child of current node is empty
   if (address->RightChild == nullptr)
   {
      //we found biggest node -> return its address
      return address;
   }
   else
   {
      //search deep
      return FindMin(address->RightChild);
   }
}

int main()
{
   Tree MyTree;

   MyTree.AddNode(20);
   MyTree.AddNode(10);
   MyTree.AddNode(8);
   MyTree.AddNode(9);
   MyTree.AddNode(15);
   MyTree.AddNode(13);
   MyTree.AddNode(17);
   MyTree.AddNode(12);
   MyTree.AddNode(14);
   MyTree.AddNode(16);
   MyTree.AddNode(18);   

   MyTree.DeleteNode(15);

   cout << "Main" << endl;

   return 0;
}
