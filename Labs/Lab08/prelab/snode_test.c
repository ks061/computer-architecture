/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - snode_test.c
 * compile with: make snode_test
 * notes: This file tests the creation 
 *        of a linked list with a collection
 *        of nodes, which are created using
 *        struts in C.
 */

#include "snode.h"
 
// global variables (data segment)
 
struct snode *n1, *n2, *n3, *p;
 
//------------ MY MAIN FUNCTION --------------------
 
int main(int argc, char *argv[]) 
{
  // create snodes
  n1 = snode_create("hello", 5);
  n2 = snode_create("there", 5);
  n3 = snode_create("prof", 4);
 
  printf("snode_test running...\n");
 
  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;
 
  // p points to node n1 initially
  p = n1;
 
  while (p != NULL) {
    // Complete this line to print the current node's string and   
    // the stored length (do not use strlen!)
    printf("str: %s - length: %d\n", p->str, p->length);
 
    p = p->next;
  }
 
  return 0;
}
