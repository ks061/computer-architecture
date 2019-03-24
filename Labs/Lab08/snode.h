#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _snode_H_
#define _snode_H_

struct snode {
	char* str;
	struct snode* next;
} snode;

struct snode *snode_create(char *s);

void snode_destroy(struct snode *n);

#endif
