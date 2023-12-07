#include <stdio.h>
#include "lists.h"

int is_palindrome(listint_t **head) {
    // Empty list is considered a palindrome
    if (*head == NULL) {
        return 1;
    }

    listint_t* slow = *head;
    listint_t* fast = *head;
    listint_t* prev = NULL;
    listint_t* temp = NULL;

    // Find the middle of the linked list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Handle odd length list
    if (fast != NULL) {
        slow = slow->next;
    }

    // Compare the first half with the reversed second half
    while (prev != NULL && slow != NULL) {
        if (prev->n != slow->n) {
            return 0; // Not a palindrome
        }
        prev = prev->next;
        slow = slow->next;
    }

    return 1; // Palindrome
}

// Utility function to insert a node at the beginning of a linked list
void insert(listint_t** head, int data) {
    listint_t* new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = data;
    new_node->next = *head;
    *head = new_node;
}

// Utility function to print a linked list
void print_list(listint_t* head) {
    listint_t* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a sample linked list
    listint_t* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Linked List: ");
    print_list(head);

    int result = is_palindrome(&head);
    if (result == 1) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}
