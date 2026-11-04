#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void read_taxon_info(const char *label, char *name_out, int *lifespan_out){         //Function 2
    printf("Enter the name of %c", *label);
    fgets(name_out, sizeof(name_out), stdin);
    name_out[strlen(name_out) - 1] = '\0';

    printf("Enter the lifespan: ");
    fgets(name_out, 50, stdin);
    lifespan_out[strlen(lifespan_out) - 1] = '\0';
}

int main (){

    return 0;
}