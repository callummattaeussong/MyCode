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
            string name;
    };

    node* root;
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const {return root == NULL;}
    void inorder(node*);
    int insert(string, int, int, BinarySearchTree);
    node* findmax(node*);
    node* findmin(node*);
    node* successor(node*);
    node* predecessor(node*);
    node* search(node*, int);
    node* deletenode(BinarySearchTree, node*);

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

int BinarySearchTree :: insert(string name, int key, int duration, BinarySearchTree T)
{
    node* z = new node();
    z->key = duration;
    z->name = name;
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
    


    if(root->left==NULL && root->right==NULL)
    {
       return 1;
    }
    else if(z->key == findmin(root)->key)
    {
        cout<<"min";
        node* s =successor(z);
        if((s->key)-(z->key) < key)
        {
            deletenode(T,z);
            return 0;
        }
    }
    else if(z->key== findmax(root)->key)
    {
        cout<<"max";
        node* p =predecessor(z);
        if((z->key)-(p->key) < key)
        {
            deletenode(T,z);
            return 0;
        }
        
    }
    else
    {
        node* s =successor(z);
        node* p =predecessor(z);
         if (((z->key)-(p->key)) < key || ((s->key)-(z->key)) < key)
         {
            deletenode(T,z);
            return 0;
         }
         
         
    }
    return 1;

}

void BinarySearchTree :: inorder(node* x)
{
    if(x!= NULL)
    {
        if(x->left) inorder(x->left);
        cout<<" "<<x->name<<"\t "<<x->key<<endl;
        if(x->right) inorder(x->right);
    }
} 

BinarySearchTree :: node* BinarySearchTree :: findmax(node* x)
{   node* temp = x;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

BinarySearchTree :: node* BinarySearchTree :: findmin(node* x)
{   node* temp = x;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

BinarySearchTree :: node* BinarySearchTree :: predecessor(node* x)
{
    
    if(x->left != NULL)
    {
        return findmax(x->left);
    }
    else
    {
        node* y = x->parent;
        while(y!= NULL && x == y->left)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }   
    
}

BinarySearchTree :: node* BinarySearchTree :: successor(node* x)
{
      
    if(x->right != NULL)
    {
        return findmin(x->right);   
    }
    else
    {
        node* y = x->parent;
        while(y!= NULL && x==y->right )
        {
            x = y;
            y = y->parent;
        }
        return y;
    }
    
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

int main()
{
    BinarySearchTree bst;
    
    bst.root= NULL;
    int choice, exit = 0, key, duration,flag;
    string name;
    cout<<"Airport Runway Simulator"<<endl<<"________________________________"<<endl;
    cout<<"Please enter the key time gap: ";
    cin>> key;
    while(exit ==0)
    {
        cout<<"1. Request Landing\n2. Withdraw Landing\n3.List Landing Times and Flight Numbers.\n4. Exit."<<endl;
        cout<<"Please choose an option above: "<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1: {
                cout<<"Request Landing \n";
                cout<<"Please enter the Flight Number : ";
                cin>>name;
                cout<<"Please enter the duration of the plane : ";
                cin>>duration;
                if(duration >= key)
                {
                    flag = bst.insert(name, key, duration, bst);
                }
                else
                {
                    flag = 0;
                }
                
                if(flag == 1)
                {
                    cout<<"Flight "<<name<<" has been queued."<<endl;
                }
                else if(flag ==0)
                {
                    cout<<"Flight "<<name<<" has been rejected."<<endl;
                }
                break;
            }
            case 2:{
                cout<<"Which duration of flight is to be withdrawn? \n";
                cin>>duration;
                cout<<endl;
                BinarySearchTree :: node* temp = bst.search(bst.root, duration);
                temp = (bst.deletenode(bst, temp));
                cout<<"Flight "<<temp->name<<"was withdrawn.\n";
                break;
            }
            case 3:{
                cout<<"landing times:\n";
                bst.inorder(bst.root);
                cout<<endl;
                break;
            }
            case 4:{
                exit = 1;
                break;
            }
            default: cout<<"That is not a valid input please try again"<<endl;
        }
    }
}