// vbcg.c
// This file is based on given.c and solves the vbc subject.
// All changes and logic are commented for clarity.

#include <stdio.h>
// ----
#include <stdlib.h>
// ----
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    } type;
    int val;
    struct node *l;
    struct node *r;
} node;

node *new_node(node n) {
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

void destroy_tree(node *n) {
    if (!n)
        return;
    if (n->type != VAL) {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected(char c) {
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c) {
    if (**s == c) {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c) {
    if (accept(s, c))
        return 1;
    unexpected(**s);
    return 0;
}

node *parse_expr(char **s);
node *parse_term(char **s);
node *parse_factor(char **s);

node *parse_factor(char **s) {
    if (accept(s, '(')) {
        node *n = parse_expr(s);
        if (!expect(s, ')')) {
            destroy_tree(n);
            return NULL;
        }
        return n;
    }
    if (isdigit(**s)) {
        node tmp;
        tmp.type = VAL;
        tmp.val = **s - '0';
        tmp.l = tmp.r = NULL;
        (*s)++;
        return new_node(tmp);
    }
    unexpected(**s);
    return NULL;
}

node *parse_term(char **s) {
    node *left = parse_factor(s);
    if (!left)
        return NULL;
    while (accept(s, '*')) {
        node tmp;
        tmp.type = MULTI;
        tmp.l = left;
        tmp.r = parse_factor(s);
        if (!tmp.r) {
            destroy_tree(tmp.l);
            return NULL;
        }
        left = new_node(tmp);
    }
    return left;
}

node *parse_expr(char **s) {
    node *left = parse_term(s);
    if (!left)
        return NULL;
    while (accept(s, '+')) {
        node tmp;
        tmp.type = ADD;
        tmp.l = left;
        tmp.r = parse_term(s);
        if (!tmp.r) {
            destroy_tree(tmp.l);
            return NULL;
        }
        left = new_node(tmp);
    }
    return left;
}

int eval_tree(node *tree) {
    switch (tree->type) {
        case ADD:
            return eval_tree(tree->l) + eval_tree(tree->r);
        case MULTI:
            return eval_tree(tree->l) * eval_tree(tree->r);
        case VAL:
            return tree->val;
    }
    return 0; // Should not reach here
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    char *s = argv[1];
    node *tree = parse_expr(&s);
    if (!tree || *s) {
        if (!tree)
            ; // error already printed
        else
            unexpected(*s);
        if (tree)
            destroy_tree(tree);
        return 1;
    }
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}

// ----
