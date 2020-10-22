#include "linked_list.h"
#include <stdlib.h>

struct Node *list_create(int value) {
  struct Node *node = malloc(sizeof(struct Node));
  if (node) {
    node->next = NULL;
    node->value = value;
  }
  return node;
}

int list_add_front(struct Node **head, int value) {
  struct Node *new_head = list_create(value);
  if (new_head) {
    new_head->next = *head;
    *head = new_head;
    return 1;
  }
  return 0;
}

int list_add_back(struct Node **head, int value) {
  struct Node *iter = *head;
  if (!iter)
    return list_add_front(head, value);
  while (iter->next)
    iter = iter->next;
  return list_add_front(&iter->next, value);
}

int list_get(struct Node *head, unsigned index) {
  struct Node *node = list_node_at(head, index);
  return node ? node->value : 0;
}

void list_free(struct Node *head) {
  struct Node *iter = head;
  while (iter) {
    struct Node *prev = iter;
    iter = iter->next;
    free(prev);
  }
}

unsigned list_length(struct Node *head) {
  unsigned result = 0;
  struct Node *iter;
  for (iter = head; iter; iter = iter->next)
    result++;
  return result;
}

struct Node *list_node_at(struct Node *head, unsigned index) {
  struct Node *iter;
  for (iter = head; iter && index; iter = iter->next)
    index--;
  return iter;
}

int list_sum(struct Node *head) {
  int result = 0;
  struct Node *iter;
  for (iter = head; iter; iter = iter->next)
    result += iter->value;
  return result;
}
