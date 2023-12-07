#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/* Structure for a singly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head);
void insert(listint_t **head, int data);
void print_list(listint_t *head);

#endif /* LISTS_H */
