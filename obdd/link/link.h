#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>


struct lelement {
  void* pt;
  struct lelement* next;
};

struct link {
  struct lelement* head; //cellule sentinelle dans le cas d'une structure chaînée vide
};


static struct lelement sentinel = {NULL, &sentinel};
#define END_MARK ((struct lelement*) &sentinel)


struct link* lnk__empty();

struct lelement* llm__empty();

struct lelement* llm__create(void*, struct lelement*);

struct lelement* lnk__first(struct link*);

int llm__is_end_mark(struct lelement*);

int lnk__add_head(struct link*, struct lelement*);

struct lelement* lnk__remove_head(struct link*);

struct lelement* llm__next(struct lelement*);

int lnk__add_after(struct lelement* lel, struct lelement* after);

struct lelement* lnk__remove_after(struct lelement*);

int lnk__add_tail(struct link*, struct lelement*);

struct lelement* lnk__remove_tail(struct link*);

int lnk__size(struct link*);

//FREE
int lnk__free(struct link*);

int llm__free(struct lelement*);

#endif /* end of include guard: LINK_H */
