#include <iostream>
#include "split.h"
using namespace std;

int main (int argc, char* argv[])
{

    // Initializing linked list 1-5
    Node* n1 = new Node(1, nullptr);
    Node* n2 = new Node(2, nullptr);
    Node* n3 = new Node(3,nullptr);
    Node* n4 = new Node(4,nullptr);
    Node* n5 = new Node(5,nullptr);
    
    // // All odds
    // Node* n1 = new Node(3, nullptr);
    // Node* n2 = new Node(5, nullptr);
    // Node* n3 = new Node(7, nullptr);
    // Node* n4 = new Node(7, nullptr);
    // Node* n5 = new Node(9, nullptr);

    // // All evens
    // Node* n1 = new Node(0, nullptr);
    // Node* n2 = new Node(2, nullptr);
    // Node* n3 = new Node(4,nullptr);
    // Node* n4 = new Node(6,nullptr);
    // Node* n5 = new Node(8,nullptr);

    // // Empty LL
    // Node* n1 = nullptr;

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    Node* evens = nullptr;
    Node* odds = nullptr;

    split(n1, odds, evens);

    // Printing out both linked lists
    cout << "Odds Linked List:" << endl;
    while (odds != NULL)
    {
        cout << odds -> value << " ";
        odds = odds -> next;
    }
    cout << endl;

    cout << "Evens Linked List:" << endl;
    while (evens != NULL)
    {
        cout << evens -> value << " ";
        evens = evens -> next;
    }

    // Deleting the nodes
    delete n5;
    delete n4;
    delete n3;
    delete n2;
    delete n1;
  
}