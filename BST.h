#ifndef bst_h
#define bst_h

#include "node.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 0);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr,int);
  int get_h(TreeNodePtr);
};

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  
  new_node = new TreeNode(value);
  if (new_node) {
    /*First Node*/
    if (!rootPtr) {// if(size==0)
      rootPtr=new_node;
    }
    else{
      t=rootPtr;
      while(!inserted){
        if(value<= t->get_value()){
          if(t->move_left()){
            t =t->move_left();
          }
          else{
            t->set_left(new_node);
            inserted=1;
          }
        }else{
          if(t->move_right()){
            t =t->move_right();
          }else{
            t->set_right(new_node);
            inserted =1
          }
        }
      }
      
    }
    ++size;
  }
}
BST::BST() {
  rootPtr = nullptr;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    kill(rootPtr);
}

void BST::inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function

void BST::printTree(TreeNodePtr treePtr,int l) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    if(treePtr->move_right()){
      printTree(treePtr->move_right() , indent + 4);
    }
    if(indent){
      cout << setw(indent) << " ";
    }
    if(treePtr->move_right()){
      cout << " /\n" << setw(indent) << " ";
    }
    cout << treePtr->get_value() << "\n";

    if(treePtr->move_left()){
      cout << setw(indent) << " " <<" \\\n";
      printTree(treePtr->move_left(), indent + 4);
    }
  }                                 // end if
} // end function


void BST::postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    inOrder(treePtr->move_right());
    cout << setw(3) << treePtr->get_value(); // print the value
    
    
  }                                          // end if
} // end function

void BST::kill(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
  }
    }                                          // end if
} // end function
void BST::preOrder(TreeNodePtr treePtr) {
  if(treePtr){
  // TreeNodePtr treePtr=rootPtr;
    cout << setw(3) << treePtr->get_value();
    inOrder(treePtr->move_left()); 
    inOrder(treePtr->move_right());
    
  }                                          // end if
} // end function


void BST::print_all(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  default:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr,0);
    cout << endl;
  }
}

//Inorder = left root right
//Preorder = root left right
//Postorder = left right root

int BST::get_h(TreeNodePtr treePtr){
  if(!treePtr){
    return 0;
  }else{
    return 1 + max(get_h(treePtr->move_left()),get_h(treePtr->move_right()))
  }
}