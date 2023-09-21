#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

extern int push_val;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void frees_the_stack(stack_t *stck);
void push(char *ln, stack_t **stck, unsigned int tracker);
void help_push(stack_t **stck, unsigned int tracker);
void opcode_finder(char *opcode, stack_t **stck, int tracker);
void pall(stack_t **stck, unsigned int tracker);
int comm(char *tok, int count);
int check(char *s);
void pint(stack_t **stck, unsigned int tracker);
void pop(stack_t **stck, unsigned int tracker);
void swap(stack_t **stck, unsigned int tracker);
void add(stack_t **stck, unsigned int tracker);
void sub(stack_t **stck, unsigned int tracker);

#endif