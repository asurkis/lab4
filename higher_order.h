#ifndef _HIGHER_ORDER_H_
#define _HIGHER_ORDER_H_

struct Node;

void foreach(void (*func)(int), struct Node *head);
struct Node *map(int (*func)(int), struct Node *head);
void map_mut(int (*func)(int), struct Node *head);
int foldl(int acc, int (*func)(int, int), struct Node *head);
struct Node *iterate(int acc, int (*func)(int), unsigned repeats);

void save(struct Node *head, char const *filename);
void load(struct Node **head, char const *filename);
void serialize(struct Node *head, char const *filename);
void deserialize(struct Node **head, char const *filename);

#endif
