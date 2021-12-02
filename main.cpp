#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bSearchTreeType.h"
using namespace std;

void print(int& x);
void update(int& x);

int main()
{
    const int AMOUNT=6; //amount of random numbers that need to be generated
    const int MAX=100; //maximum value
    int value[AMOUNT]; //array to store the random numbers in
    srand(time(NULL)); //always seed your RNG before using it
    //generate random numbers:
    for (int i=0;i<AMOUNT;i++)
    {
        bool check; //variable to check or number is already used
        int n; //variable to store the number in
        do
        {
            n=rand()%MAX+1;
            //check or number is already used:
            check=true;
            for (int j=0;j<i;j++)
                if (n == value[j]) //if number is already used
                {
                    check=false; //set check to false
                    break; //no need to check the other elements of value[]
                }
        } while (!check); //loop until new, unique number is found
        value[i]=n; //store the generated number in the array
    }

    cout <<"Here are your values\n\n";
    for(int i=0; i<AMOUNT; i++)
        cout <<value[i]<< "\t";
        cout<<endl;

    bSearchTreeType<int> tree;

    for(int i=0; i<AMOUNT; i++)
        tree.insert(value[i]);
    /*int num;
    cout << "\n\nEnter numbers ending with -999"<< endl;
    cin >> num;
    while (num != -999)
    {
        tree.insert(num);
        cin >> num;
    }*/

    cout<<endl<<endl<<"In order: ";
    tree.inorderTraversal();

    cout<<endl<<endl<<"postorder: ";
    tree.postorderTraversal();

    cout<<endl<<endl<<"preorder: ";
    tree.preorderTraversal();

    tree.rightChildNum=0;

    int number = tree.numberOfRightChildren();

    cout<<endl<<"Number of right children is "<<tree.rightChildNum;
     cout<<endl<<"Number of right children is "<<number;

     cout<<endl<<"Let's count all the nodes.";
     int nodeNumber = tree.callNodeCount();
     cout<<endl<<"Number of nodes is "<<nodeNumber;


     cout<<endl<<"The largest node has the value: ";
     binaryTreeNode<int> *maximum = tree.max();

     cout<<maximum->info;

     cout<<endl<<"Let's print all values between 10 and 50.";
     tree.printInRange(10,50);
    return 0; }
    /*bSearchTreeType<int> treeRoot;
    int num;
    cout << "Line 10: Enter numbers ending with -999"
    << endl;
    cin >> num;
    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Line 17: Tree nodes in inorder: ";
    treeRoot.inorderTraversal(print);
    cout << endl << "Line 19: Tree Height: "
    << treeRoot.treeHeight()
    << endl << endl; //Line 19
    cout << "Line 20: ******* Update Nodes *******"
    << endl; //Line 20
    treeRoot.inorderTraversal(update); //Line 21
    cout << "Line 22: Tree nodes in inorder after "
    << "the update: " << endl << " "; //Line 22
    treeRoot.inorderTraversal(print); //Line 23
    cout << endl <<"Line 24: Tree Height: "
    << treeRoot.treeHeight() << endl; //Line 24
    return 0; //Line 25*/
//} //Line 26

void print(int& x) //Line 27
{ //Line 28
    cout << x << " "; //Line 29
} //Line 30

void update(int& x) //Line 31
{ //Line 32
    x = 2 * x; //Line 33
}
