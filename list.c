#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

/**
 * @param head Pointer to the first node of the linked list.
 * @return The size (number of nodes) of the linked list. If the list is empty (NULL), returns 0.
 */
int ll_size(struct ll_node *head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

/**
 * TODO: Describe what the function does
 * @param head Pointer to the first node of the linked list.
 * @param value The value to search for in the linked list.
 * @return A pointer to the node containing the specified value, or NULL if not found.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

/**
 * @param head Pointer to the first node of the linked list.
 * @return An array containing all the data from the linked list nodes.
 */
int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0) {
        return NULL;
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    struct ll_node *current = head;
    for (int i = 0; i < size; i++) {
        array[i] = current->data;
        current = current->next;
    }

    return array;
}

/**
 * Creates a new linked list node.
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created linked list node.
 */

struct ll_node *ll_create(int data) {
    struct ll_node *new_node = malloc(sizeof(struct ll_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * Destroys the linked list and frees all allocated memory.
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *current = head;
    while (current != NULL) {
        struct ll_node *next = current->next;
        free(current);
        current = next;
    }
}



/**
 * appends a new node with the given data to the end of the linked list.
 * @param head Pointer to the first node of the linked list.
 * @param data The data to be stored in the new node.
 */
void ll_append(struct ll_node *head, int data) {
    struct ll_node *new_node = ll_create(data);
        if (new_node == NULL) {
            return;
        }
        struct ll_node *tail = ll_tail(head);
        if (tail != NULL) {
            tail->next = new_node;
        }    
}

/**
 * Creates a linked list from an array
 * @param data An array of integers to create the linked list from.
 * @param len The length of the array.
 * @return The head of the newly created linked list.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (len <= 0) {
        return NULL;
    }

    struct ll_node *head = ll_create(data[0]);
    if (head == NULL) {
        return NULL;
    }

    struct ll_node *current = head;
    for (int i = 1; i < len; i++) {
        struct ll_node *new_node = ll_create(data[i]);
        if (new_node == NULL) {
            ll_destroy(head);
            return NULL;
        }
        current->next = new_node;
        current = new_node;
    }

    return head;

}

/**
 * Removes the first occurrence of a node with the specified value from the linked list.
 * @param head Pointer to the first node of the linked list.
 * @param value The value of the node to be removed.
 * @return The head of the modified linked list.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == value) {
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }

    struct ll_node *current = head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            struct ll_node *node_to_remove = current->next;
            current->next = current->next->next;
            free(node_to_remove);
            return head;
        }
        current = current->next;
    }

    return head;
}

