// clang-format -i 0001.c
// clang --std=c17 -g 0001.c -o c_0001 && ./c_0001

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct Author; // forward declaration
typedef struct Book {
  char title[50];
  struct Author *author;
} Book;
typedef struct Author {
  char name[20];
  Book *books;
} Author;

void hello();

typedef struct SampleStruct {
  char name[256];
  int year;
  int pages;
  bool hardcover;
} SampleStruct;

typedef struct Test {
  int a;
  int b;
} Test;

#ifdef __cplusplus
}
#endif

int main(void) {
  hello();

  Test b = {0};
  printf("%d\n", b.a);

  Author lx = {"鲁迅", NULL};
  Book *books = malloc(3 * sizeof(Book));
  Book *ptr = books;
  strcpy(ptr->title, "朝花夕拾");
  strcpy((*(ptr + 1)).title, "呐喊");
  strcpy((ptr + 2)->title, "彷徨");
  for (int i = 0; i < 3; i++) {
    ptr->author = &lx;
    ptr++;
  }
  ptr = books;
  for (int i = 0; i < 3; i++) {
    printf("书籍： <<%s>>的作者是: %s\n", ptr->title, ptr->author->name);
    ptr++;
  }
  free(books);
  books = NULL;

  SampleStruct a = {0};
  printf("%d\n", a.pages);

  return 0;
}

void hello() { printf("hello world\n"); }
