#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef int ElementType; 
typedef struct Node *PtrToNode;
typedef PtrToNode	List;
typedef PtrToNode	Position;

/** 
 * return true if L empty 
 **/
bool list_is_empty(List L);

/* return true if p is the last position in list L */
bool list_is_last(Position p, List L);

/* Create a list form head */
void list_create_form_head(List L, ElementType array[], int n);

/* Create a list form head */
void list_create_form_tail(List L, ElementType array[], int n);

/* Find the element */
Position list_find_elment(List L, ElementType value);

/* Find a value of previous */
Position list_find_previous(List L, ElementType value);

/* Delete a exist element in List */
void list_delete_element(List L, ElementType value);

/* Insert  a element to the list L*/
void list_insert(List L, Position p, ElementType value);

/* Clear the list of L */
void list_clear(List L);

/* Get the head list of L */
Position list_header(List L);

/* Get the first element position*/
Position list_first(List L);

/* */
Position list_advace(List L);

ElementType list_etrieve(Position p);

/*list abs*/
struct Node{
    ElementType	element; 
	PtrToNode	next;
};

#endif	//:ifndef _LIST_H_ ///:~
