#include <stdio.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
}Taxon;

Taxon* create_taxon(const char *name, int lifespan){     // First Function
    Taxon *new_taxon = malloc(sizeof(Taxon));
     new_taxon -> name = name;
     new_taxon -> lifespan = lifespan;
     new_taxon -> parent_group = NULL;
     return new_taxon
}

int main (){

    return 0;
}