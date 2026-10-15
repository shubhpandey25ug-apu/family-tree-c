#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name [50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person; 


Person* create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    strcpy(p -> name, name);
    p -> age = age;
    p -> father = NULL;
    p -> mother = NULL;
    return p;
}


void read_person_info(const char *role, char *name_out, int *age_out) {
    char line[100];

    printf("Enter name for %s: ", role);
    fgets(name_out, 50, stdin);
    name_out[strcspn(name_out, "\n")] = '\0';

    printf("Enter age for %s: ", role);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", age_out);
}

void link_parents(Person *child, Person *father, Person *mother) {
    child -> father = father;
    child -> mother = mother;
}

void print_family_relationships(const Person *me) {
   printf("=== FAMILY TREE RELATIONSHIPS ===\n");

   printf("1. YOURSELF:\n");
   printf("- Name: %s | Age: %d\n", me -> name, me -> age);

   printf("2. PARENTS:\n");
   printf("- Father: %s | Age: %d\n", me -> father -> name, me -> father -> age);
   printf("- Mother: %s | Age: %d\n", me -> mother -> name, me -> mother -> age);

   printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
   printf("- Grandfather: %s | Age: %d\n", me -> father -> father -> name, me -> father -> father -> age);
   printf("- Grandmother: %s | Age: %d\n", me -> father -> mother -> name, me -> father -> mother -> age);

   printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
   printf("- Grandfather: %s | Age: %d\n", me -> mother -> father -> name, me -> mother -> father -> age);
   printf("- Grandmother: %s | Age: %d\n", me -> mother -> mother -> name, me -> mother -> mother -> age);
}

void free_family_tree(Person *people[], int count) {
   for (int i = 0; i < count; i++) {
       free(people[i]);
   }
}

int main(void) {
    const char *roles[7] = {
        "Paternal Grandfather", "Paternal Grandmother",
        "Maternal Grandfather", "Maternal Grandmother",
        "Father", "Mother", "Yourself"
    };
    Person *people[7];

    for (int i = 0; i < 7; i++) {
        char name[50];
        int age;
        read_person_info(roles[i], name, &age);   
        people[i] = create_person(name, age);   
    }

link_parents(people[4], people[0], people[1]);
link_parents(people[5], people[2], people[3]);
link_parents(people[6], people[4], people[5]);

   print_family_relationships(people[6]);


   free_family_tree(people, 7);

    return 0;
}
