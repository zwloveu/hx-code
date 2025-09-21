// clang-format -i 0001.c
// clang --std=c17 -g 0001.c -o c_0001 && ./c_0001

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct Author;//forward declaration
typedef struct Book {
  char title[50];
  struct Author *author;
} Book;
typedef struct Author {
  char name[20];
  Book *books;
} Author;

void hello();

#ifdef __cplusplus
}
#endif

int main(void) {
  hello();

  Author 鲁迅;
  strcpy(鲁迅.name, "鲁迅");
  Book 呐喊;
  strcpy(呐喊.title, "呐喊");
  呐喊.author = &鲁迅;
  鲁迅.books = &呐喊;
  printf("作者: %s, 拥有书籍: <<%s>>\n", 鲁迅.name, 鲁迅.books->title);
  printf("书籍: <<%s>>的作者是: %s\n", 呐喊.title, 呐喊.author->name);

  return 0;
}

void hello() { printf("hello world\n"); }
