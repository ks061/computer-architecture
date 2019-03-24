/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - snode.h
 * notes: This file defines the struct
 * 	  snode and specifies 
 * 	  headers for the snode create/destroy
 * 	  methods to be defined in snode.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _snode_H_
#define _snode_H_

struct snode 
{
	char* str;
	struct snode* next;
} snode;

struct snode *snode_create(char *s);

void snode_destroy(struct snode *n);

#endif
