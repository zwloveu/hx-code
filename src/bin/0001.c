// clang-format -i 0001.c
// clang --std=c17 -g 0001.c -o c_0001 && ./c_0001

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
  printf("%d", b.a);

  Author 鲁迅 = {"鲁迅", NULL};
  Book *周树人的书籍啊 = malloc(3 * sizeof(Book));
  strcpy(周树人的书籍啊[0].title, "朝花夕拾");
  strcpy((*(周树人的书籍啊 + 1)).title, "呐喊");
  strcpy((周树人的书籍啊 + 2)->title, "彷徨");
  周树人的书籍啊[0].author = &鲁迅;
  周树人的书籍啊[1].author = &鲁迅;
  周树人的书籍啊[2].author = &鲁迅;
  鲁迅.books = 周树人的书籍啊;
  Book *ptr = 鲁迅.books;
  for (int i = 0; i < 3; i++) {
    printf("书籍： <<%s>>的作者是: %s\n", ptr->title, ptr->author->name);
    ptr++;
  }
  free(周树人的书籍啊);
  周树人的书籍啊 = NULL;

  SampleStruct a = {0};
  printf("%d", a.pages);

  return 0;
}

void hello() { printf("hello world\n"); }
