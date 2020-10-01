#include <iostream>
using namespace std;
class BinarySearchTree
{
    public:
    class node
    {
        public:
            node* left;
            node* right;
            node* parent;
            int key;
    };

    node* root;
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const {return root == NULL;}
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void insert(int);
    void findmax(node*);
    node* findmin(node*);
    node* successor(node*);
    node* search(node*, int);
    node* deletenode(BinarySearchTree, node*);
    void removemax(BinarySearchTree, node*);

};

BinarySearchTree :: node* BinarySearchTree :: search(node* root, int x)
{
    if(root == NULL || root->key == x)
    {
        return root;
    }
    if(root->key < x)
    {
        return search(root->right, x);
    }

    return search(root->left, x);
}

void BinarySearchTree :: insert(int d)
{
    node* z = new node();
    z->key = d;
    z->left = NULL;
    z->right = NULL;

    node* y = NULL;
    node* x = root;
    z->parent = NULL;

    while (x != NULL)
    {
        y =x;
        if(z->key < x-> key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NULL)
    {
        root = z;
    }
    else if(z->key < y->key)
    {
        y->left =z;
    }
    else
    {
        y->right = z;
    }    
}

void BinarySearchTree :: inorder(node* x)
{
    if(x!= NULL)
    {
        if(x->left) inorder(x->left);
        cout<<" "<<x->key<<" ";
        if(x->right) inorder(x->right);
    }
} 

void BinarySearchTree :: preorder(node* x)
{
    if(x!= NULL)
    {
        cout<<" "<<x->key<<" ";
        if(x->left)
        {
            preorder(x->left);
        }
        if(x->right) preorder(x->right);
    }
} 

void BinarySearchTree :: postorder(node* x)
{
    if(x!= NULL)
    {
        if(x->left) postorder(x->left);
        if(x->right) postorder(x->right);
        cout<<" "<<x->key<<" ";
    }
} 

void BinarySearchTree :: findmax(node* x)
{
    if(x->right == NULL)
    {
        cout<<"The maximum element is "<<x->key<<endl;
        return;
    }
    findmax(x->right);
}

BinarySearchTree :: node* BinarySearchTree :: findmin(node* x)
{   node* temp = x;
    if(x->left == NULL)
    {
        return temp;
    }
    findmin(x->left);
}



BinarySearchTree :: node* BinarySearchTree :: successor(node* root)
{
    node* y;    
    if(root->right != NULL)
    {
        return findmin(root->right);   
    }
    else
    {
        node* y = root->parent;
        while(y!= NULL && root==y->right )
        {
            root = y;
            y = y->parent;
        }
    }
    return y;
}

BinarySearchTree :: node* BinarySearchTree :: deletenode(BinarySearchTree T, node* z)
{
    node* x;
    node* y;
    if(z->left == NULL || z->right == NULL)
    {
        y=z;
    }
    else
    {
        y = successor(z);
    }
    if(y->left != NULL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }
    if(x!=NULL)
    {
        x->parent = y->parent;
    }
    if(y->parent == NULL)
    {
        root = x;
    }
    else 
    {
        if(y == (y->parent)->left)
        {
            (y->parent)->left = x;
        }
        else
        {
            (y->parent)->right = x;
        }
    }
    if(y!=z)
    {
        z->key = y->key;
    }
    return y;
}

void BinarySearchTree :: removemax(BinarySearchTree T, node* x)
{
    if(x->right == NULL)
    {
        cout<<"Element "<<x->key<<" was removed."<<endl;
        deletenode(T, x);
        return;
    }
    removemax(T, x->right);
}

int main()
{
    BinarySearchTree bst;
    
    bst.root= NULL;
    int choice, exit = 0, key;
    while(exit ==0)
    {
        cout<<"Binary Search Tree Example"<<endl<<"________________________________"<<endl;
        cout<<"1. Insert a node\n2. Pre-Order Traversal\n3. Post-Order Traversal"<<endl;
        cout<<"4. In-Order Traversal"<<endl<<"5. Find Max\n6. Remove Max\n7. Successor\n8. Delete"<<endl;
        cout<<"9. Exit\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: {
                cout<<"Please enter a value to insert: ";
                cin>>key;
                bst.insert(key);
                cout<<key<<" has been inserted."<<endl;
                break;}
            case 2: {
                cout<<"Pre-Order Traversal : ";
                bst.preorder(bst.root);
                cout<<endl;
                break;}
            case 3:{
                cout<<"Post-Order Traversal : ";
                bst.postorder(bst.root);
                cout<<endl;
                break;}
            case 4:{
                cout<<"In-Order Traversal : ";
                bst.inorder(bst.root);
                cout<<endl;
                break;}
            case 5:{
                bst.findmax(bst.root);
                break;}
            case 6:{
                bst.removemax(bst, bst.root);
                break;}
            case 7:{
                cout<<"Please enter the value you wish to find the successor for"<<endl;
                cin>>key;
                BinarySearchTree :: node* temp = bst.search(bst.root, key);
                cout<<bst.successor(temp)->key<<" is the successor."<<endl;
                break;}
            case 8:{
                cout<<"Enter a number you would like to delete."<<endl;
                cin>>key;
                BinarySearchTree :: node* temp = bst.search(bst.root, key);
                bst.deletenode(bst, temp);
                cout<<key<<" has been deleted.\n";
                break;}
            case 9:{
                exit = 1;}
            default: cout<<"That is not a valid input please try again"<<endl;

        }
    }
}