/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include <string>
using namespace std;


int main(int argc, char* argv[])
{

  // CODIO EXAMPLE
  // Tests push_back() on empty list & populated node
  // Tests push_front() on populated node
  // Tests getValAtLoc(), front(), and back()
  cout << "INITIALIZING LIST WITH 8 7 9" << endl;
  ULListStr list;
  list.push_back("7");
  list.push_front("8");
  list.push_back("9");
  cout << "All elements: " << list.get(0) << " " << list.get(1) << " " << list.get(2) << endl; // should print 8 7 9
  cout << "Front of the list: " << list.front() << endl; // should print 8
  cout << "Back of the list: " << list.back() << endl; // should print 9
  cout << "Current size of linked list: " << list.size() << endl; // should be 3
  cout << endl;


  // EMPTYING LL
  // Tests pop_front() on populated node
  // Tests pop_back() on populated node
  cout << "POPPED FRONT " << endl;
  list.pop_front(); // removing 8 --> new front = 7
  cout << "All elements: " << list.get(0) << " " << list.get(1) << endl; // should print 7 9
  cout << "Current front: " << list.front() << endl; // should be 7
  cout << "Current back: " << list.back() << endl; // should be 9
  cout << "Current size of linked list: " << list.size() << endl; // should be 2
  cout << endl;

  cout << "POPPED BACK" << endl;
  list.pop_back(); // removing 9 --> new back and front = 7
  cout << "All elements: " << list.get(0) << endl; // should print 7 
  cout << "Current front: " << list.front() << endl; // should be 7
  cout << "Current back: " << list.back() << endl; // should be 7
  cout << "Current size of linked list: " << list.size() << endl; // should be 1
  cout << "The list is empty: " << boolalpha << list.empty() << endl; // should be false
  cout << endl;
  
  cout << "POPPED FRONT -> EMPTY LIST" << endl;
  list.pop_front();
  cout << "The list is empty: " << boolalpha << list.empty() << endl; // should be true
  cout << endl;

  // ADDING TO LINKED LIST -> FILLING ENTIRELY
  // Tests push_front() on empty list & populated node
  cout << "PUSHED FRONT 10 ELEMENTS TO FILL NODE" << endl;
  for (int i = 0; i < 10; i++)
  {
    string input = to_string(i);
    list.push_front(input);
    cout << "Added " << input << " to list" << endl;
  }

  cout << "Current size of linked list: " << list.size() << endl; // should be 10
  cout << "All elements: " << list.get(0) << " " << list.get(1) << " " 
  << list.get(2) << " " << list.get(3) << " " << list.get(4) << " " << 
  list.get(5) << " " << list.get(6) << " " << list.get(7) << " " << list.get(8) <<
  " " << list.get(9) << endl; // should print 9 8 7 6 5 4 3 2 1 0
  cout << endl;

  // POPULATING FULL NODE
  // Tests push_front() and push_back() on full node
  list.push_back("-1");
  list.push_front("10");

  cout << "Current size of linked list: " << list.size() << endl; // should be 12
  cout << "All elements: " << list.get(0) << " " << list.get(1) << " " 
  << list.get(2) << " " << list.get(3) << " " << list.get(4) << " " << 
  list.get(5) << " " << list.get(6) << " " << list.get(7) << " " << list.get(8) <<
  " " << list.get(9) << " " << list.get(10) << " " << list.get(11) << endl; // should print 10 9 8 7 6 5 4 3 2 1 0 -1

  cout << "Current front: " << list.front() << endl; // should be 10
  cout << "Current back: " << list.back() << endl; // should be -1

  // TESTING REMAINING FUNCTIONS
  cout << "CHANGED VALUE 8 AT LOC 2 FROM 8 TO 88" << endl;
  list.set(2, "88");
  cout << "Value at loc 2: " << list.get(2) << endl; // should be 88
  cout << "All elements: " << list.get(0) << " " << list.get(1) << " " 
  << list.get(2) << " " << list.get(3) << " " << list.get(4) << " " << 
  list.get(5) << " " << list.get(6) << " " << list.get(7) << " " << list.get(8) <<
  " " << list.get(9) << " " << list.get(10) << " " << list.get(11) << endl; // should print 10 9 88 7 6 5 4 3 2 1 0 -1
  cout << endl;

  cout << "CLEARED THE LINK LIST" << endl;
  list.clear();
  cout << "The list is empty: " << boolalpha << list.empty() << endl; // should be true
  
}
