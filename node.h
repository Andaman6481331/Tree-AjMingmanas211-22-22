#ifndef node_h
#define node_h

class TreeNode {   
                                        
   TreeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   TreeNode *rightPtr; // pointer to right subtree
public:
        TreeNode(int); 
        ~TreeNode();
        void set_left(TreeNode* t);
        void set_right(TreeNode* t);
        int get_value();
        TreeNode* move_right(){ return rightPtr; }
        TreeNode* move_left(){ return leftPtr; }

       

}; // end structure treeNode 
        

typedef TreeNode * TreeNodePtr; 
// synonym for TreeNode*

void TreeNode::set_left(TreeNode* left){
  this->leftPtr = left;
}

void TreeNode::set_right(TreeNode* right){
  this->rightPtr = right;
}

TreeNode::TreeNode(int x){
   data =x;
   leftPtr=NULL;
   rightPtr=NULL;
  
}
TreeNode::~TreeNode(){
  cout<<"Deleting "<< data<<endl;
  
}

int TreeNode::get_value(){
  return data;
}



