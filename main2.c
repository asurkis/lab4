#include "higher_order.h"
#include "linked_list.h"
#include <stdio.h>

static void _print_space(int x) { printf("%d ", x); }
static void _print_newline(int x) { printf("%d\n", x); }
static int _square(int x) { return x * x; }
static int _cube(int x) { return x * x * x; }
static int _mul2(int x) { return 2 * x; }
static int _min(int x, int y) { return x < y ? x : y; }
static int _max(int x, int y) { return x > y ? x : y; }
static int _abs(int x) { return x < 0 ? -x : x; }

int main() {
  struct Node dummy = {NULL, 0};
  struct Node *list = &dummy;
  struct Node *tmp;

  for (;;) {
    int value;
    if (scanf("%d", &value) == EOF)
      break;
    list_add_front(&list->next, value);
  }
  list = dummy.next;

  puts("Whitespace separated");
  foreach(_print_space, list);

  puts("\nNewline separated");
  foreach(_print_newline, list);

  puts("Squares");
  tmp = map(_square, list);
  foreach(_print_space, tmp);
  list_free(tmp);
  puts("\n");

  puts("Cubes");
  tmp = map(_cube, list);
  foreach(_print_space, tmp);
  list_free(tmp);
  puts("\n");

  printf("Min is %d\n", foldl(list->value, _min, list));
  printf("Max is %d\n", foldl(list->value, _max, list));

  puts("Absolute values");
  map_mut(_abs, list);
  foreach(_print_space, list);
  puts("\n");

  puts("Iteration");
  tmp = iterate(1, _mul2, 10);
  foreach(_print_space, tmp);
  list_free(tmp);
  puts("\n");



  list_free(list);
  return 0;
}
