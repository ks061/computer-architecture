/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - snode.h
 * notes: This file defines the struct
 * 	  snode and specifies 
 * 	  headers for the snode create
 * 	  method to be defined in snode.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct snode 
{
	char str[101];
	int length;
	struct snode* next;
} snode;

struct snode *snode_create(char *s, int length);
