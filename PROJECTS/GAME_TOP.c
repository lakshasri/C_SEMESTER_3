#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
    char n[50];
    int s;
    struct p *l, *r;
} p;

p* cp(char *n, int s) {
    p *np = (p*)malloc(sizeof(p));
    strcpy(np->n, n);
    np->s = s;
    np->l = np->r = NULL;
    return np;
}

p* ip(p *rt, char *n, int s) {
    if (!rt) return cp(n, s);
    if (s > rt->s) rt->r = ip(rt->r, n, s);
    else rt->l = ip(rt->l, n, s);
    return rt;
}

void dl(p *rt) {
    if (!rt) return;
    dl(rt->r);
    printf("%s - %d\n", rt->n, rt->s);
    dl(rt->l);
}

p* sp(p *rt, char *n) {
    if (!rt || strcmp(rt->n, n) == 0) return rt;
    if (strcmp(n, rt->n) > 0) return sp(rt->r, n);
    return sp(rt->l, n);
}

p* mvn(p *nd) {
    while (nd && nd->l) nd = nd->l;
    return nd;
}

p* dp(p *rt, char *n) {
    if (!rt) return NULL;
    if (strcmp(n, rt->n) > 0) rt->r = dp(rt->r, n);
    else if (strcmp(n, rt->n) < 0) rt->l = dp(rt->l, n);
    else {
        if (!rt->l) {
            p *t = rt->r;
            free(rt);
            return t;
        } else if (!rt->r) {
            p *t = rt->l;
            free(rt);
            return t;
        }
        p *t = mvn(rt->r);
        strcpy(rt->n, t->n);
        rt->s = t->s;
        rt->r = dp(rt->r, t->n);
    }
    return rt;
}

int main() {
    p *lb = NULL;
    int c, s;
    char n[50];

    while (1) {
        printf("\n1. Add Player  2. Display Leaderboard  3. Search Player  4. Remove Player  5. Exit\nChoice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", n);
                printf("Enter score: ");
                scanf("%d", &s);
                lb = ip(lb, n, s);
                break;
            case 2:
                printf("\nFortnite Leaderboard:\n");
                dl(lb);
                break;
            case 3:
                printf("Enter player name to search: ");
                scanf("%s", n);
                if (sp(lb, n)) printf("Player found: %s\n", n);
                else printf("Player not found!\n");
                break;
            case 4:
                printf("Enter player name to remove: ");
                scanf("%s", n);
                lb = dp(lb, n);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
