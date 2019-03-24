/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - snode.c
 * notes: This file holds methods to
 *        create and destroy snodes.
 */

#include "snode.h"

struct snode *snode_create(char *s) 
{
	struct snode* node;
	node = (struct snode*)malloc(sizeof(struct snode));
	int length = strlen(s); 
	node->str = (char*) malloc((length+1)*sizeof(char));       
 
	strcpy(node->str, s);
        
	node->next = NULL;
        
	return node;
}

void snode_destroy(struct snode *n) 
{
	free(n->str);
	free(n);
}
