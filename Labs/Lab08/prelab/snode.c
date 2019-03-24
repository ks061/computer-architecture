/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - snode.c
 * notes: This file holds methods to
 *        create snodes.
 */

#include "snode.h"

struct snode *snode_create(char *s, int length) 
{
	struct snode* node;
	node = (struct snode*)malloc(sizeof(struct snode));
        
	strcpy(node->str, s);
        node->length = length;
        node->str[length] = 0;
        node->next = NULL;
        return node;
}
