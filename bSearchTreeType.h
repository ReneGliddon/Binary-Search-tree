#ifndef BSEARCHTREETYPE_H
#define BSEARCHTREETYPE_H
#include "binaryTreeType.h"
#include <cassert>

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
    public:
        bool search(const elemType& searchItem) const;
        //Function to determine if searchItem is in the binary search tree.
        //Postcondition: Returns true if searchItem is found in the binary search tree; otherwise, returns false.
        void insert(const elemType& insertItem);
        //Function to insert insertItem in the binary search tree.
        //Postcondition: If no node in the binary search tree has the same info as insertItem, a node with the info insertItem
        // is created and inserted in the binary search tree.
        void deleteNode(const elemType& deleteItem);
        //Function to delete deleteItem from the binary search tree.
        //Postcondition: If a node with the same info as deleteItem
        // is found, it is deleted from the binary search tree.
        //void nonRecursiveInTraversal() const;
        //void binaryTreeType<elemType>::nonRecursiveInTraversal() const
        binaryTreeNode<elemType>* max();
        void printInRange(int high, int low);
        void recPIR(binaryTreeNode<elemType>* current, int low, int high);
    private:
        void deleteFromTree(binaryTreeNode<elemType>* &p);
            //Function to delete the node to which p points is deleted from the binary search tree.
            //Postcondition: The node to which p points is deleted from the binary search tree.
};

template<class Type>
void bSearchTreeType<Type>::printInRange(int high, int low)
{
    binaryTreeNode<Type> *current;
    current = this->root;
    recPIR(current, low, high);


}

template <class Type>
void bSearchTreeType<Type>::recPIR(binaryTreeNode<Type> *current, int low, int high)
{
    cout<<endl<<"current is "<<current->info;
     if((current->llink!=NULL)||((current->info>low)&&(current->info<high)))
        {
            //cout<<endl<<"In the first if";
            recPIR(current->llink, low, high);
            cout<<endl<<current->info;
        }
    cout<<endl<<"between ifs";
     if((current->rlink!=NULL)||((current->info<high)&&(current->info>low)))
        {
            cout<<endl<<"in the second if";
            recPIR(current->rlink, low, high);
            cout<<endl<<current->info;
        }
}

template<class Type>
binaryTreeNode<Type>* bSearchTreeType<Type>::max()
{
    binaryTreeNode<Type> *current;
    current = this->root;

    while(current->rlink!=NULL)
    {
        current=current->rlink;
    }
    return current;
}
template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
    binaryTreeNode<elemType> *current;
    bool found = false;

    if (this->root == NULL)
        cerr << "Cannot search the empty tree." << endl;
    else
    {
        current = this->root;
        while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }//end while
    }//end else
    return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *newNode; //pointer to create the node
    newNode = new binaryTreeNode<elemType>;

    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (this->root == NULL)
        this->root = newNode;
    else
    {
        current = this->root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed."<< insertItem << endl;
                return;
            }
            else if (current->info > insertItem)
                    current = current->llink;
            else
                current = current->rlink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p)
{
    binaryTreeNode<elemType> *current;//pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *temp; //pointer to delete the node

    if (p == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if(p->llink == NULL && p->rlink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if(p->llink == NULL)
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if(p->rlink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;
        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while

        p->info = current->info;
        if (trailCurrent == NULL) //current did not move;
        //current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
            delete current;
    }//end else
}//end deleteFromTree

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == NULL)
        cout << "Cannot delete from the empty tree." << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;
        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }//end while
        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }//end else if
    }//end else
}//end deleteNode

/*template <class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal() const
{
    stackType<binaryTreeNode<elemType>* > stack;
    binaryTreeNode<elemType> *current;
    current = root;
    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            cout << current->info << " ";
            current = current->rlink;
        }
        cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePreTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack;
    binaryTreeNode<elemType> *current;
    current = root;
    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            cout << current->info << " ";
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            current = current->rlink;
        }
        cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePostOrderTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack1;
    stackType<binaryTreeNode<elemType>*> stack2;
    binaryTreeNode<elemType> *current;
    current = root;
    int v = 0;

    if(current==NULL)
    {
        cout<<"Empty tree"<<endl;
    }
    else
    {
        stack1.push(current);
        stack2.push(1);
        current=current->llink;
        while(stack1.!isEmptyStack())
        {
            if(current!=NULL && v == 0)
            {
                stack1.push(current);
                stack2.push(1);
                current = current->llink;
            }
            else
            {
                current = stack1.pop();
                v = stack2.pop();
                if(v==1)
                {
                    stack1.push(current);
                    stack2.push(2);
                    current = current->rlink;
                    v = 0;
                }
                else
                    cout<<current->info<<endl;
            }
        }
    }
}//end nonRecursivePostOrderTraversal*/
#endif // BSEARCHTREETYPE_H
