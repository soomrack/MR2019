#include <iostream>

using namespace std;

/*
*  t - max pointers in one node
*  t-1 - max amount of data in one node
*/

class Node
{
public:
   int *DataArray;
   Node **AddressArray;
   Node *ParentAddress;

   //current amount of numbers in node counter
   int DataCounter;   

   //node leaf status flag
   bool leaf;

   //create new node
   Node(int data, int t)
   {
      //create data array
      this->DataArray = new int[t-1];

      for (int i = 0; i < t - 1; i++)
      {
         this->DataArray[i] = NULL;
         //this->DataArray[i] = i;
      }

      //create address array
      this->AddressArray = new Node *[t];

      for (int i = 0; i < t; i++)
      {
         this->AddressArray[i] = nullptr;
      }

      //write new data to node array
      this->DataArray[0] = data;

      this->DataCounter = 1;

      ParentAddress = nullptr;

      this->leaf = true;

      cout << "Node constructor" << endl;
   }   

private:   

};

class Tree
{
public:
   Node *root;

   Tree(int t)
   {
      root = nullptr;

      this->t = t;

      cout << "Tree constructor" << endl;
   }

   //add new data to the tree
   void AddData(int NewData);

   //find and write new data to appropriate place
   void FindAppropriatePlace(int NewData, Node *address);

   //mode elements in node data array forward from appropriate place
   void MoveElementsForward(Node *address, int AppropriatePlace);

   //mode elements in node data array backaward from appropriate place
   void MoveElementsBackward(Node* address, int AppropriatePlace);

   //split node into two parts, returns address of new created node with right half of splitted one
   Node *SplitNode(int NewData, Node *address);

   //find and delete goal data
   bool DeleteData(int DataToDelete, Node *address);

   void DeleteNode(Node *address);

   //insert new data to specific node
   void InsertData(int NewData, Node *address);

   //find data in specific node and retrn its place
   int FindDataInNode(int GoalData, Node *address);

   Node *FindData(int GoalData, Node* address);

   void PrintTree(Node *address);

private:
   unsigned int t;
};

void Tree::AddData(int NewData)
{
   //if tree has no root -> create root node
   if (root == nullptr)
   {
      root = new Node(NewData, this->t);
      return;
   }

   //find and write to appropriate place
   FindAppropriatePlace(NewData, root);
}

void Tree::FindAppropriatePlace(int NewData, Node *address)
{
   //all elements check
   for (int i = 0; i < (address->DataCounter); i++)
   {
      //if new data less than current element
      if (NewData < address->DataArray[i])
      {
         //and if this node is a leaf
         if (address->leaf == true)
         {
            //and if this node has empty space
            if (address->DataCounter < (t - 1))
            {
               //move existing elements forward to set free appropriate place for new data
               MoveElementsForward(address, i);
               
               //write new data
               address->DataArray[i] = NewData;
               address->DataCounter++;

               //exit
               return;
            }
            //if this node has no empty space
            else
            {
               //split node and write new data to appropriate place
               SplitNode(NewData, address);  
               return;
               //find new place and write new data to it
               //return FindAppropriatePlace(NewData, root);
            }            
         }
         //if this node is not a leaf
         else
         {
            //search deep
            return FindAppropriatePlace(NewData, address->AddressArray[i]);
         }
      }
   }

   //check is over, new data is more than all elements in node data array
   //hence we have to place new data to the right side of current node
   //check if it is a leaf
   if (address->leaf == true)
   {
      //if this node has empty space
      if (address->DataCounter < (t - 1))
      {
         //write new data
         address->DataArray[address->DataCounter] = NewData;
         address->DataCounter++;
      }
      else
      {
         //split node
         SplitNode(NewData, address);
         //return FindAppropriatePlace(NewData, root);
      }      
   }
   //if it is not a leaf
   else
   {
      //search deep inlast child
      return FindAppropriatePlace(NewData, address->AddressArray[address->DataCounter]);
   }   
}

void Tree::MoveElementsForward(Node *address, int AppropriatePlace)
{
   //index for moving left
   int index = address->DataCounter - 1;

   while (index >=0 && index != (AppropriatePlace - 1))
   {
      //copy current element forward
      address->DataArray[index + 1] = address->DataArray[index];
      address->AddressArray[index + 2] = address->AddressArray[index + 1];

      index--;
   }

   //after this action i can write new data to appropriate place in leaf node
}

void Tree::MoveElementsBackward(Node *address, int AppropriatePlace)
{
   //index for moving right
   int index = AppropriatePlace;

   if (index == 0)
   {
      while (index < (address->DataCounter))
      {
         //copy current element backward
         address->DataArray[index] = address->DataArray[index + 1];

         index++;
      }

      index = 0;

      while (index < (address->DataCounter + 1))
      {
         //copy current element backward
         address->AddressArray[index] = address->AddressArray[index + 1];

         index++;
      }
   }
   else
   {
      while (index < (address->DataCounter))
      {
         //copy current element backward
         address->DataArray[index] = address->DataArray[index + 1];
         address->AddressArray[index + 1] = address->AddressArray[index + 2];

         index++;
      }
   }   

   address->DataArray[address->DataCounter] = NULL;
   address->AddressArray[address->DataCounter + 1] = nullptr;
}

Node *Tree::SplitNode(int NewData, Node *address)
{
   //if we need to split root
   if (address == root)
   {
      //create new empty root
      root = new Node(NULL, t);
      root->DataCounter = 0;
      root->leaf = false;

      //create new empty node
      Node *RightHalf = new Node(NULL, t);
      RightHalf->DataCounter = 0;

      //if current splitting node is not a leaf
      if (address->leaf != true)
      {
         //new node is not a leaf too
         RightHalf->leaf = false;
      }

      int MovingDataCounter = address->DataCounter;

      int DataToMoveUp = address->DataArray[MovingDataCounter / 2];
      
      //mvoe first right address to new node
      RightHalf->AddressArray[0] = address->AddressArray[MovingDataCounter / 2 + 1];

      if (RightHalf->AddressArray[0] != nullptr)
      {
         RightHalf->AddressArray[0]->ParentAddress = RightHalf;
      }   

      address->AddressArray[MovingDataCounter / 2 + 1] = nullptr;

      //move all right data and address from current node to new one
      for (int i = MovingDataCounter / 2 + 1; i <= MovingDataCounter - 1; i++)
      {
         //move current data element to new node
         RightHalf->DataArray[i - (MovingDataCounter / 2 + 1)] = address->DataArray[i];
         address->DataArray[i] = NULL;

         //move current+1 address element to new node
         RightHalf->AddressArray[i - (MovingDataCounter / 2)] = address->AddressArray[i + 1];

         if (RightHalf->AddressArray[i - (MovingDataCounter / 2)] != nullptr)
         {
            RightHalf->AddressArray[i - (MovingDataCounter / 2)]->ParentAddress = RightHalf;
         }        

         address->AddressArray[i + 1] = nullptr;

         RightHalf->DataCounter++;
         address->DataCounter--;
      }

      //erase middle data in current node
      address->DataArray[MovingDataCounter / 2] = NULL;
      address->DataCounter--;
      
      //move middle data up to new root
      //write new data
      root->DataArray[0] = DataToMoveUp;
      root->DataCounter++;

      //left root child is curent node
      root->AddressArray[0] = address;

      //right root child is new node
      root->AddressArray[1] = RightHalf;

      //set parent of right half
      RightHalf->ParentAddress = root;
      address->ParentAddress = root;

      //write new data to either old or new node
      if (NewData > DataToMoveUp)
      {
         //write new data to node with right half
         //FindAppropriatePlace(NewData, RightHalf);

         InsertData(NewData, RightHalf);

         //if moving data goes to new node -> return its address
         return RightHalf;
      }
      else
      {
         //write new data to node with left half (curent node)
         //FindAppropriatePlace(NewData, address);

         InsertData(NewData, address);

         //if moving data goes to old node -> return its address
         return address;
      }
   }

   //if we need to split node which is not root
   else
   {
      //create new empty node
      Node *RightHalf = new Node(NULL,t);      
      RightHalf->DataCounter = 0;

      //if current splitting node is not a leaf
      if (address->leaf != true)
      {
         //new node is not a leaf too
         RightHalf->leaf = false;
      }

      //save current date counter to new variable
      int MovingDataCounter = address->DataCounter;

      //save middle data that we need to move up to new variable
      int DataToMoveUp = address->DataArray[MovingDataCounter / 2];

      //mvoe first right address to new node
      RightHalf->AddressArray[0] = address->AddressArray[MovingDataCounter / 2 + 1];

      if (RightHalf->AddressArray[0] != nullptr)
      {
         RightHalf->AddressArray[0]->ParentAddress = RightHalf;
      }

      address->AddressArray[MovingDataCounter / 2 + 1] = nullptr;

      //move all right data from current node to new one
      for (int i = (MovingDataCounter / 2 + 1); i <= (MovingDataCounter - 1); i++)
      {
         //move current data element to new node
         RightHalf->DataArray[i - (MovingDataCounter / 2 + 1)] = address->DataArray[i];
         address->DataArray[i] = NULL;

         //move current+1 address element to new node
         RightHalf->AddressArray[i - (MovingDataCounter / 2)] = address->AddressArray[i + 1];

         if (RightHalf->AddressArray[i - (MovingDataCounter / 2)] != nullptr)
         {
            RightHalf->AddressArray[i - (MovingDataCounter / 2)]->ParentAddress = RightHalf;
         }

         address->AddressArray[i + 1] = nullptr;

         RightHalf->DataCounter++;
         address->DataCounter--;
      }

      //erase middle data in current node
      address->DataArray[MovingDataCounter / 2] = NULL;
      address->DataCounter--;

      //write new data to either old or new node
      if (NewData > DataToMoveUp)
      {
         //write new data to node with right half
         //FindAppropriatePlace(NewData, RightHalf);

         InsertData(NewData, RightHalf);
      }
      else
      {
         //write new data to node with left half (curent node)
         //FindAppropriatePlace(NewData, address);

         InsertData(NewData, address);
      }

      //move middle data up to parent
      //check if parent has empty space
      if (address->ParentAddress->DataCounter < (t - 1))
      {
         //all elements check
         for (int i = 0; i < (address->ParentAddress->DataCounter); i++)
         {
            //if new data less than parent current element
            if (DataToMoveUp < address->ParentAddress->DataArray[i])
            {
               //move existing elements forward to set free appropriate place for new data
               MoveElementsForward(address->ParentAddress, i);

               //write new data
               address->ParentAddress->DataArray[i] = DataToMoveUp;
               address->ParentAddress->DataCounter++;

               //set new child (right half) of parent node
               address->ParentAddress->AddressArray[i+1] = RightHalf;

               //set parent of right half
               RightHalf->ParentAddress = address->ParentAddress;

               //splitting has finished -> exit
               return nullptr;
            }            
         }         

         //if data to move up is more than all existing parent data
         //write data to move up to parent node
         address->ParentAddress->DataArray[address->ParentAddress->DataCounter] = DataToMoveUp;         
         address->ParentAddress->DataCounter++;

         //set new child (right half) of parent node
         address->ParentAddress->AddressArray[address->ParentAddress->DataCounter] = RightHalf;

         //set parent of right half
         RightHalf->ParentAddress = address->ParentAddress;

         //splitting has finished -> exit
         return nullptr;
      }
      //if parent has no empty space
      else
      {
         //split parent node and add data to move up from current node   
         //return address, where moving data was moved
        Node *MovedDataToNode = SplitNode(DataToMoveUp, address->ParentAddress);

        //if parent was splitted -> here we need to have parent node adderess
        if (MovedDataToNode != nullptr)
        {
           RightHalf->ParentAddress = MovedDataToNode;

           int index = FindDataInNode(DataToMoveUp, MovedDataToNode);

           MovedDataToNode->AddressArray[index+1] = RightHalf;
        }
      }            
   }
}

void Tree::InsertData(int NewData, Node  *address)
{
   //all elements check
   for (int i = 0; i < address->DataCounter; i++)
   {
      //if new data less than right half current element
      if (NewData < address->DataArray[i])
      {
         //move existing elements forward to set free appropriate place for new data
         MoveElementsForward(address, i);

         //write new data
         address->DataArray[i] = NewData;
         address->DataCounter++;

         return;
      }
   }

   //if new data up is more than all existing right half data
   //write data to move up to right half
   address->DataArray[address->DataCounter] = NewData;
   address->DataCounter++;

   return;
}

bool Tree::DeleteData(int DataToDelete, Node *address)
{
   //find data to delete and return address of its node
   Node *NodeAddress = FindData(DataToDelete, address);

   //if data is not found
   if (NodeAddress == nullptr)
   {
      return 0;
   }
   //if data to delete is found
   else// if(NodeAddress->leaf == true)
   {
      //find place of deleting data
      int PlaceToDelete = FindDataInNode(DataToDelete, NodeAddress);

      //delete data
      NodeAddress->DataArray[PlaceToDelete] = NULL;
      NodeAddress->DataCounter--;

      //move data backwards
      MoveElementsBackward(NodeAddress, PlaceToDelete);

      //if node has no data left
      if (NodeAddress->DataCounter == 0)
      {
         int ChildAddressIndex = 0;
         
         //find place in address array of node with deleted element in parent node
         for (int i = 0; i <= NodeAddress->ParentAddress->DataCounter; i++)
         {
            //if address is equal
            if (NodeAddress == NodeAddress->ParentAddress->AddressArray[i])
            {
               //write its index
               ChildAddressIndex = i;

               //break from for cycle
               break;
            }
         }

         Node *LeftNode = nullptr;
         Node *RightNode = nullptr;
         Node *ParentNode = NodeAddress->ParentAddress;

         //if node with deleting data is first child of its parent
         if (ChildAddressIndex == 0)
         {
            RightNode = NodeAddress->ParentAddress->AddressArray[ChildAddressIndex + 1];
         }
         //or if node with deleting data is last child of its parent
         else if (ChildAddressIndex == ParentNode->DataCounter + 1)
         {
            LeftNode = NodeAddress->ParentAddress->AddressArray[ChildAddressIndex - 1];
         }
         else
         {
            LeftNode = NodeAddress->ParentAddress->AddressArray[ChildAddressIndex - 1];
            RightNode = NodeAddress->ParentAddress->AddressArray[ChildAddressIndex + 1];
         }

         //look left
         //if there is left node and it has more than 1 element -> move data from parent node down
         //and move last element of left node up to parent
         if (LeftNode != nullptr && NodeAddress->ParentAddress->AddressArray[ChildAddressIndex - 1]->DataCounter > 1)
         {   
            //move parent left data down
            NodeAddress->DataArray[0] = ParentNode->DataArray[ChildAddressIndex - 1];
            NodeAddress->DataCounter++;

            //move biggest data from left node up
            ParentNode->DataArray[ChildAddressIndex - 1] = LeftNode->DataArray[LeftNode->DataCounter - 1];
            LeftNode->DataArray[LeftNode->DataCounter - 1] = NULL;
            LeftNode->DataCounter--;
         }
         //or look right
         //if there is right node and it has more than 1 element -> move data from parent node down
         //and move last element of left node up to parent
         else if(RightNode != nullptr && NodeAddress->ParentAddress->AddressArray[ChildAddressIndex + 1]->DataCounter > 1)
         {
            //move parent right data down
            NodeAddress->DataArray[0] = ParentNode->DataArray[ChildAddressIndex];
            NodeAddress->DataCounter++;

            //move smallest data from right node up
            ParentNode->DataArray[ChildAddressIndex] = RightNode->DataArray[0];
            RightNode->DataArray[0] = NULL;
            RightNode->DataCounter--;

            //move elements of right node backward
            MoveElementsBackward(RightNode, 0);
         }
         //if left and right node has 1 element
         else
         {              

            //look up
            //if parent has nore than 1 element
            if (ParentNode->DataCounter > 1)
            {
               //if left node exists               
               if (LeftNode != nullptr)
               {
                  //move left parent data of child address index to the right border of left node
                  LeftNode->DataArray[LeftNode->DataCounter] = ParentNode->DataArray[ChildAddressIndex - 1];
                  LeftNode->DataCounter++;
                  ParentNode->DataCounter--;

                  MoveElementsBackward(ParentNode, ChildAddressIndex - 1);

                  DeleteNode(NodeAddress);
               }
               //if left node does not exists
               else if (RightNode != nullptr)
               {
                  MoveElementsForward(RightNode, 0);

                  //move first parents data element down to right node
                  RightNode->DataArray[0] = ParentNode->DataArray[0];
                  RightNode->DataCounter++;
                  ParentNode->DataArray[0] = NULL;
                  ParentNode->DataCounter--;

                  MoveElementsBackward(ParentNode, 0);

                  DeleteNode(NodeAddress);
               }
            }            
         }
      }      
   }

   //mission complete
   return 1;
}

Node *Tree::FindData(int GoalData, Node *address)
{   
   //search for goal data
   int DataPlace = FindDataInNode(GoalData, address);
   Node *ResultNode;

   //if data is not found
   if (DataPlace == (t + 1))
   {
      //if address is root and a leaf
      if (address == root && address->leaf == true)
      {
         //return nullptr (nothing found)
         return nullptr;
      }
      else
      {
         //compare all elements and find next appropriate node
         //all elements check
         for (int i = 0; i < (address->DataCounter); i++)
         {
            //if goal data less than current element
            if (GoalData < address->DataArray[i])
            {
               //if child address exists
               if (address->AddressArray[address->DataCounter] != nullptr)
               {
                  //search deep
                  ResultNode = FindData(GoalData, address->AddressArray[i]);

                  if (ResultNode != nullptr)
                  {
                     return ResultNode;
                  }
               }
               else
               {
                  //return nullptr (nothing found)
                  return nullptr;
               }
            }
         }

         //goal data is more than existing data of current node
         //if child address exists
         if (address->AddressArray[address->DataCounter] != nullptr)
         {
            //move to right child
            ResultNode = FindData(GoalData, address->AddressArray[address->DataCounter]);

            if (ResultNode != nullptr)
            {
               return ResultNode;
            }
         }
         else
         {
            //return nullptr (nothing found)
            return nullptr;
         }         
      }      
   }
   //if data is found
   else
   {
      return address;
   }
}

void Tree::DeleteNode(Node *address)
{
   //if we need to delete root
   if (address == root)
   {
      delete root;
   }
   //if we need to delete node
   else
   {
      delete address;
   }
}

void Tree::PrintTree(Node *address)
{
   for (int i = 0; i < (t - 1); i++)
   {
      cout << address->DataArray[i] << ", ";
   }

   cout << endl;

   for (int j = 0; j < t; j++)
   {
      if (address->AddressArray[j] != nullptr)
      {
         PrintTree(address->AddressArray[j]);
      }      
   }

}

int Tree::FindDataInNode(int GoalData, Node* address)
{
   //all elements check
   for (int i = 0; i < (address->DataCounter); i++)
   {
      //if data equals current data element
      if (GoalData == address->DataArray[i])
      {
         return i;
      }
   }

   //if data is not found
   return (t + 1);
}

int main()
{
   Tree MyTree(4);

   MyTree.AddData(8);
   MyTree.AddData(13);
   MyTree.AddData(5);

   MyTree.AddData(0);
   MyTree.AddData(16);
   MyTree.AddData(7);
   MyTree.AddData(23);
   MyTree.AddData(48);
   MyTree.AddData(15);

   MyTree.AddData(1);
   MyTree.AddData(2);

   cout << "Add data" << endl;

   MyTree.PrintTree(MyTree.root);

   MyTree.DeleteData(0, MyTree.root);
   MyTree.DeleteData(7, MyTree.root);
   MyTree.DeleteData(15, MyTree.root);
   MyTree.DeleteData(48, MyTree.root);
   MyTree.DeleteData(13, MyTree.root);
   MyTree.DeleteData(1, MyTree.root);
   MyTree.DeleteData(23, MyTree.root);

   cout << "Delete data" << endl;

   MyTree.PrintTree(MyTree.root);

   return 0;
}

