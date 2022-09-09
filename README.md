# USC CSCI 104: HW 1
## Part 1
- runtime complexity analysis
- recursive tracing
- recursive linked list sorting (evens/odds)

## Part 2
Implementation of an Unrolled Linked List
- linked list with arrays stored as elements, rather than a single integer
- run the program within the csci104 docker container for valgrind and gdb
- to compile:  g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test
- to test memory leakage: valgrind --tool=memcheck --leak-check=yes ./ulliststr_test
