/* Kartikeya Sharma
 * March 5, 2019 at 1 PM
 * lab 08 - slist.c
 * notes: This file automates the creation of,
 * 	  deallocation of, and usage of linked
 * 	  lists.
 */

#include "snode.h"
#include "slist.h"

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create() 
{
	struct slist* list;
	list = (struct slist*) malloc(sizeof(struct slist));
	list->front = NULL;
	list->back = NULL;
	return list;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, char *str) 
{
	struct snode* node_to_add;
	node_to_add = snode_create(str);
	if (l->front == NULL) {
		l->front = node_to_add;
		l->back = node_to_add;
	} else {
		l->back->next = node_to_add;
		l->back = node_to_add;
	}
	return node_to_add;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str)
{
	struct snode* node_to_add;
	node_to_add = snode_create(str);
	if (l->front == NULL) {
		l->front = node_to_add;
		l->back = node_to_add;
	} else {
		node_to_add->next = l->front;
		l->front = node_to_add;
	}
	return node_to_add;
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str)
{
	struct snode* cur_node = l->front;
	while (cur_node != NULL) {
		if (strcmp(cur_node->str, str) == 0) {
			return cur_node;
		}	
		cur_node = cur_node->next;
	}
	return NULL;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l)
{
	struct snode* cur_node = l->front;
	struct snode* temp_node;
	while (cur_node != NULL) {
		temp_node = cur_node->next;
		snode_destroy(cur_node);
		cur_node = temp_node;
	}
	free(l);
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l) 
{
	struct snode* node = l->front;
	while(node != NULL) {
		printf("%s\n", node->str);
		node = node->next;
	}	
}

/**
 * Returns the number of elements in the list (nodes).
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l) 
{
	struct snode* node = l->front;
	int length = 0;
	while(node != NULL) {
		length++;
		node = node->next;
	}	
	return(uint32_t)length;
}
