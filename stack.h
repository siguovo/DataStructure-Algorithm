#ifndef __STACK_H__
#define __STACE_H__
#inclued <stdio.h>
#define STACK_TYPE int

/*push*/
void push(STACK_TYPE value);

/*pop*/
void pop(void);

/*top*/
STACK_TYPE top(void);

/*is_empty*/
int is_empty(void);

/*is_full*/
int is_full(void);


#endif /*__STACK_H__*/
~                         