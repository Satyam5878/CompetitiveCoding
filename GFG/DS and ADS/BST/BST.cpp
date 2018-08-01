#include<iostream>

using namespace std;

class Node{
    public:
        int info;
        Node* leftChild;
        Node* rightChild;
        Node(int info);  
};

// Constructor
Node::Node(int item){
     info = item;
     leftChild = rightChild = NULL;
};

// Binary Search Tree;
class BST{
    public:
        Node* root;
        BST();
        Node* search();   //done
        void insertNode(int item); //done
        Node* insertNode_rec(Node* root,int item);  //done
        void deleteNode(int item);  //done
        Node*  deleteNode_rec(Node* root,int item);
        Node* getMin();    //done
        Node* getMin(Node* root);
        Node* getMax();    //done
        int nextLarger();
        int nextSmaller();
        void printArray();    //done
        void inorder(Node *root); //done
};


// All recursive function:
BST::BST(){
    root = NULL;
}
void BST::insertNode(int item){
    root = insertNode_rec(root,item);
};
Node* BST::insertNode_rec(Node* root,int item){
    if(root == NULL){
        return new Node(item);
    }
    if(item < root->info){
        root->leftChild = insertNode_rec(root->leftChild,item);
    }
    else if(item > root->info){
        root->rightChild = insertNode_rec(root->rightChild,item);
    }
    else{
        return root;
    }
}

void BST::printArray(){
    inorder(root);
};
void BST::inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->leftChild);
    cout<<root->info<<" ";
    inorder(root->rightChild);
}

Node* BST::getMin(){
    if(root == NULL){
        return root;
    };
    Node *ptr = root;
    while(ptr->leftChild != NULL){
        ptr = ptr->leftChild;
    }
    return ptr;
};
Node* BST::getMin(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node *ptr = root;
    while(ptr->leftChild != NULL){
        ptr = ptr->leftChild;
    }
    return ptr;
}
Node* BST::getMax(){
    if(root == NULL){
        return root;
    }
    Node* ptr = root;
    while(ptr->rightChild != NULL){
        ptr = ptr->rightChild;
    }
    return ptr;
}
void BST::deleteNode(int item){
    root = deleteNode_rec(root,item);
};
Node* BST::deleteNode_rec(Node* root,int item){
    if(root == NULL){
        return root;
    }
    if(item < root->info){
        root->leftChild = deleteNode_rec(root->leftChild,item);
    }
    else if(item > root->info){
        root->rightChild = deleteNode_rec(root->rightChild,item);
    }
    else{
        if(root->leftChild == NULL && root->rightChild == NULL){
            delete root;
           root = NULL;
        }
        else if(root->leftChild == NULL){
            Node* tmp = root->rightChild;
            delete root;
            root = tmp;
        }
        else if(root->rightChild == NULL){
            Node* tmp = root->leftChild;
            delete root;
            root = tmp;
        }
        else{
            Node* min = getMin(root->rightChild);
            root->info = min->info;
            root->rightChild = deleteNode_rec(root->rightChild,min->info);
        }
        return root;
    }

}


int main(){
    int arr[] = {10,50,30,20,25,28,70,5,6};
    BST bst;
    for(int i=0;i<9;++i){
        bst.insertNode(arr[i]);
    }
    bst.printArray();
    cout<<endl<<bst.root->info<<endl;
    cout<<"Minimum : "<<bst.getMin()->info<<endl;
    cout<<"Maximum : "<<bst.getMax()->info<<endl;
    cout<<" Delete :";
    bst.deleteNode(10);
    bst.printArray();
};



