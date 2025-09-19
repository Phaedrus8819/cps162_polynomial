#include "Polynomial.h"
#include <iostream>

using namespace std;

// Function to display the polynomial
void Polynomial::display() const{
            ListNode *nodePtr; // To move through the list

            // Position nodePtr at the head of the list
            nodePtr = head;

            // While nodePtr points to a node, traverse
            // the list
            while (nodePtr)
            {
                // Display the value in this node
                cout << nodePtr -> value.coeff << "x^" << nodePtr -> value.exp;

                // Move to the next node
                nodePtr = nodePtr -> next;

                if(nodePtr) //if there is another term, print a plus sign
                    if(nodePtr->value.coeff >= 0) //only print plus sign if the next coeff is positive
                        cout << " + ";
            }
            cout << endl; //end with a new line
        }

void Polynomial::multPoly(const Polynomial &a, int x, int y)
{
    ListNode *nodePtr = a.head;
    
    while (nodePtr)
    {
        int coefficient = nodePtr->value.coeff * x;
        int exponent = nodePtr->value.exp + y;

        cout << coefficient << "x^" << exponent;

        nodePtr = nodePtr->next;
        if(nodePtr) //if there is another term, print a plus sign
                    if(nodePtr->value.coeff * x >= 0) //only print plus sign if the next coeff is positive
                        cout << "+";
    }
    cout << endl;
}

// Add a term to the polynomial
void Polynomial::insertTerm(Term &term){
            ListNode *newNode; //a new node
            ListNode *nodePtr; //to traverse the list
            ListNode *previousNode = nullptr; //to point to the previous node

            //Allocate a new node and store the term
            newNode = new ListNode;
            newNode->value = term;

            // If there are no nodes in the list
            // make newNode the first node

            if(!head)
            {
                head=newNode;
                newNode->next = nullptr;
            }
            else //Otherwise, insert newNode
            {
                //Position nodePtr at the head of the list
                nodePtr = head;

                // Initialize previousNode to nullptr
                previousNode = nullptr;

                //Skip all nodes whose value is less than term.exp
                while(nodePtr != nullptr && nodePtr->value.exp > term.exp)
                {
                    previousNode = nodePtr; //keep track of the previous node
                    nodePtr = nodePtr->next; //move to the next node
                }

                //If the new node is to be the first in the list
                if(previousNode == nullptr)
                {
                    head = newNode; //make newNode the first node
                    newNode->next = nodePtr; //newNode points to the former first node
                }
                else //Otherwise, insert newNode between previousNode and nodePtr
                {
                    previousNode->next = newNode; //previousNode points to newNode
                    newNode->next = nodePtr; //newNode points to nodePtr
                }
            }
        }

// Add the two polynomials together
void Polynomial::printSum(const Polynomial &a, const Polynomial &b)
{
    ListNode *p = a.head;
    ListNode *q = b.head;

    while (p||q)
    {
        if (!q )
        {
            if (p->value.coeff >= 0 && p != a.head)
                cout << "+";
            cout << p -> value.coeff << "x^" << p -> value.exp; 
            p=p->next;
        } else if (!p)
        {
            if (q->value.coeff >= 0 && q != a.head)
                cout << "+";
            cout << q -> value.coeff << "x^" << q -> value.exp; 
            q=q->next;
        } else if (p->value.exp > q->value.exp)
        {
            if (p->value.coeff >= 0 && p != a.head)
                cout << "+";
            cout << p -> value.coeff << "x^" << p -> value.exp; 
            p=p->next;
        } else if (q->value.exp > p->value.exp)
        {
            if (q->value.coeff >= 0 && q != a.head)
                cout << "+";
            cout << q -> value.coeff << "x^" << q -> value.exp; 
            q=q->next;
        } else {
            int c = p->value.coeff + q->value.coeff;
            if (c >= 0 && p != a.head && q != b.head)
                cout << "+";
            cout << c << "x^" << p->value.exp;
            p=p->next;
            q=q->next;
        }
    }
    cout << endl;
}

// Subtract the two polynomials together
void Polynomial::printDiff(const Polynomial &a, const Polynomial &b)
{
    ListNode *p = a.head;
    ListNode *q = b.head;

    while (p||q)
    {
        if (!q )
        {
            if (p->value.coeff >= 0 && p != a.head)
                cout << "+";
            cout << p -> value.coeff << "x^" << p -> value.exp; 
            p=p->next;
        } else if (!p)
        {
            if (q->value.coeff >= 0 && q != a.head)
                cout << "+";
            cout << q -> value.coeff << "x^" << q -> value.exp; 
            q=q->next;
        } else if (p->value.exp > q->value.exp)
        {
            if (p->value.coeff >= 0 && p != a.head)
                cout << "+";
            cout << p -> value.coeff << "x^" << p -> value.exp; 
            p=p->next;
        } else if (q->value.exp > p->value.exp)
        {
            if (q->value.coeff >= 0 && q != a.head)
                cout << "+";
            cout << q -> value.coeff << "x^" << q -> value.exp; 
            q=q->next;
        } else {
            int c = p->value.coeff - q->value.coeff;
            if (c >= 0 && p != a.head && q != b.head)
                cout << "+";
            cout << c << "x^" << p->value.exp;
            p=p->next;
            q=q->next;
        }
    }
    cout << endl;
}

// Destructor to free the linked list
Polynomial::~Polynomial()
{
    ListNode *nodePtr;   // To traverse the list
    ListNode *nextNode;  // To point to the next node

    // Position nodePtr at the head of the list
    nodePtr = head;

    // Traverse the list deleting each node
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next; // Save pointer to the next node
        delete nodePtr;           // Delete the current node
        nodePtr = nextNode;       // Position nodePtr at the next node
    }
}