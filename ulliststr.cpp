#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // If the LL is empty, create a new Node
  if (empty())
  {
    // LL of 1 node, head and tail point to same node
    Item* node = new Item();
    head_ = node;
    tail_ = node;

    // Prev and next of Item are NULL
    node -> prev = NULL;
    node -> next = NULL;

    // First and last elements are the same
    // Therefore, first points to index 0
    // Therefore, Last points to index 1
    node -> first = 0;
    node -> last = node -> first + 1;

    // Set value at first index in node to passed-in val
    node -> val[node -> first] = val;
  }

  // If there is space to push back within the node
  // Referencing values of tail since it is at the end of the node
  else if (tail_ -> last < ARRSIZE)
  {
    // Push last up one
    tail_ -> last = tail_ -> last + 1;

    // Add it to values at the end of the contiguous array
    tail_ -> val[(tail_ -> last) - 1] = val;
  }

  // If there the list isn't empty but there's no space
  // inside current node, create new node after current node
  // and update tail and next/prev
  else
  {
    // LL of 1 node, update tail
    Item* temp = tail_;
    Item* node = new Item();

    // temp's next (aka tail_'s next) is now the new node.
    // temp -> prev is already accurate
    temp -> next = node;

    // The node before the new node is temp (aka tail_)
    node -> prev = temp;

    // First and last elements are the same
    // Therefore, first points to index 0
    // Therefore, Last points to index 1
    node -> first = 0;
    node -> last = node -> first + 1;

    // Update the values of the node
    node -> val[node -> first] = val;

    // Finally, set tail to the new node
    tail_ = node;
  }

  // Update size regardless of if statement
  size_ = size_ + 1;
}

void ULListStr::push_front(const std::string& val)
{
  // If the LL is empty, create a new Node
  if (empty())
  {
    // LL of 1 node, head and tail point to same node
    Item* node = new Item();
    head_ = node;
    tail_ = node;

    // Prev and next of Item are NULL
    node -> prev = NULL;
    node -> next = NULL;

    // First and last elements are the same
    // Therefore, first points to index ARRSIZE-1
    // Therefore, last points to index + 1 aka ARRSIZE
    node -> first = ARRSIZE - 1;
    node -> last = node -> first + 1;

    // Set value at first index in node to passed-in val
    node -> val[node -> first] = val;
  }

  // If there is space to push front within the node
  // Referencing values of head since it is at the start of the node
  else if (head_ -> first > 0)
  {
    // Push first down one
    head_ -> first = head_ -> first - 1;

    // Add it to values at new first index
    head_ -> val[head_ -> first] = val;
  }

  // If there the list isn't empty but there's no space
  // inside current node, create new node before current
  // node and update head and next/prev
  else
  {
    // LL of 1 node, update tail
    Item* temp = head_;
    Item* node = new Item();

    // temp's prev (aka head_'s prev) is now the new node.
    // temp -> next is already accurate
    temp -> prev = node;

    // The node after the new node is temp (aka head_)
    node -> next = temp;

    // First and last elements are the same
    // Therefore, first points to index ARRSIZE-1
    // Therefore, Last points to ARRSIZE
    node -> first = ARRSIZE - 1;
    node -> last = node -> first + 1;

    // Update the values of the node
    node -> val[node -> first] = val;

    // Finally, set head to the new node
    head_ = node;
  }

  // Update size regardless of if statement
  size_ = size_ + 1;
}

void ULListStr::pop_back()
{
  // If list is empty, just return nothing
  if (empty())
  {
    return;
  }

  // If the list only have 1 element, need to set 
  // head and tail to NULL and delete the node
  if (size_ == 1)
  {
    delete tail_;
    head_ = NULL;
    tail_ = NULL;
  }

  // If the last pointer of the node tail_ points to
  // is at index 1, this means one one element
  // exists at index 0 thus removal empties the node
  else if (tail_ -> last == 1)
  {
    // Change tail to be one node prior
    tail_ = tail_ -> prev;

    // Delete the node after tail
    delete tail_ -> next;
    tail_ -> next = NULL;
  }

  // Otherwise, simply remove the element within node 
  // by decrementing last pointer
  else
  {
    tail_ -> last = (tail_ -> last) -1;
  }

  // Update size regardless of if statement
  size_ = size_ - 1;
  
}

void ULListStr::pop_front()
{
  // If list is empty, just return nothing
  if (empty())
  {
    return;
  }

  // If the list only have 1 element, need to set 
  // head and tail to NULL and delete the node
  if (size_ == 1)
  {
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }

  // If the first pointer of the node head_ points to
  // is at index ARRSIZE-1, this means one one element
  // exists at the end of the node's array thus removal empties the node
  else if (head_ -> first == ARRSIZE-1)
  {
    // Change head_ to be one node after
    head_ = head_ -> next;

    // Delete the node before head_
    delete head_ -> prev;
    head_ -> prev = NULL;
  }

  // Otherwise, simply remove the element within node 
  // by incrementing first pointer
  else
  {
    head_ -> first = (head_ -> first) + 1;
  }

  // Update size regardless of if statement
  size_ = size_ - 1;
  
}

// Returning the value located in the last element of tail's array
std::string const & ULListStr::back() const
{
  return tail_ -> val[tail_ -> last - 1];
}

// Returning the value located in the first element of head's array
std::string const & ULListStr::front() const
{
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // Ensuring loc is within bounds of array
  if (loc >= 0 && loc < size_)
  {
    // Tracking process of getting to loc
    size_t index = 0;
    Item* currNode = head_;
    size_t element = head_ -> first;
    while (index < loc)
    {
      element++;
      // If at the end of current node, move to next
      // and reset indexing of node
      if (element == currNode -> last)
      {
        currNode = currNode -> next;
        element = 0;
      }
      index++;
    }
    return &currNode -> val[element];
  }

  // Out of bounds 
  else
  {
    return NULL;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
