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
    strcpy(p->name, name);
    p->age = age;
    p->father = NULL;
    p->mother = NULL;
    return p;
}

int main(void) {
    Person *me = create_person("Chitra", 20);
    printf("%s is %d\n", me->name, me->age);
    free(me);
    return 0;
}
