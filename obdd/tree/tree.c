#include "tree.h"
#include <limits.h>


//TREE
struct tree* tree__empty() {
  struct tree* tr = malloc(sizeof(struct tree));
  tr->root = NULL;
  return tr;
}

int tree__is_empty(const struct tree* tr) {
  return tr->root == NULL;
}


//NODE
struct node* node__empty() {
  struct node* n = malloc(sizeof(struct node));
  n->eq_interval.upper_bound = INT_MAX;
  n->eq_interval.lower_bound = INT_MIN;
  n->rchild = NULL;
  n->lchild = NULL;
  return n;
}

int node__set_eq_interval(struct node* n, int lower_bound, int upper_bound) {
  n->eq_interval.upper_bound = upper_bound;
  n->eq_interval.lower_bound = lower_bound;
  return 1;
}

int node__add_rchild(struct node* parent, struct node* child) {
  parent->rchild = child;
  return 1;
}

int node__add_lchild(struct node* parent, struct node* child) {
  parent->lchild = child;
  return 1;
}


//FREE
int tree__free(struct tree* tr) {
  if (tr->root != NULL)
    node__free(tr->root);
  free(tr);
  return 1;
}

int node__free(struct node* n) {
  if (n->rchild != NULL)
    node__free(n->rchild);
  if (n->lchild != NULL)
    node__free(n->lchild);
  free(n);
  return 1;
}
