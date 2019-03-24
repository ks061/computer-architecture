#include "snode.h"

struct snode *snode_create(char *s, int length) {
	struct snode* node;
	node = (struct snode*)malloc(sizeof(struct snode));
        
	strcpy(node->str, s);
        node->length = length;
        node->str[length] = 0;
        node->next = NULL;
        return node;
}
