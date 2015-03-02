#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef int ElementType; 
typedef struct Node *PtrToNode;
typedef PtrToNode	List;
typedef PtrToNode	Position;

/* Make a list empty */
List make_empty(List L);

/** 
 * return true if L empty 
 **/
bool is_empty(List L);

/* return true if p is the last position in list L */
bool is_last(Position p, List L);

/* Find the element */
Position find_elment(List L, ElementType value);

void delete_element(List L, ElementType value);

/**/
Position find_previous(List L, ElementType value);

/*Insert vlaue to the list L*/
void insert_list(List L, Position p, ElementType value);

void delete_list(List L);

Position header(List L);
Position first(List L);
Position advace(List L);

ElementType Retrieve(Position p);


/*list abs*/
struct Node{
    ElementType	element; 
	PtrToNode	next;
};

#endif	//:ifndef _LIST_H_ ///:~
