#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

List* InitList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->append = (void (*)(void *, void *)) Append;
    list->print = (void (*)(void *)) PrintList;
    list->free = (void (*)(void *)) FreeList;
    list->printE = (void (*)(void *)) PrintExcellentFemaleStudents;
    list->printEtwo = (void (*)(void *)) PrintExcellentStudentsWithoutTwos;
    return list;
}

void* Append(void* list, void* student) {
    List* l = (List*)list;
    Student* s = (Student*)student;
    Node* newNode = malloc(sizeof(Node));
    newNode->student = s;
    newNode->next = NULL;

    if (l->size == 0) {
        l->head = newNode;
        l->tail = l->head;
    }
    else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->size++;
    return NULL; // Возвращаем NULL, так как тип void*
}

void* PrintExcellentFemaleStudents(void* list) {
    List* l = (List*)list;
    Node* current = l->head;
    while (current != NULL) {
        if (strcmp(current->student->gender, "female") == 0 && current->student->physicGrade == 5 && current->student->chemistryGrade == 5) {
            printf("Name: %s %s\n", current->student->name, current->student->surname);
            printf("Group: %s\n", current->student->group);
            printf("Age: %d\n", current->student->age);
            printf("Math Grade: %d\n", current->student->mathGrade);
            printf("Physic Grade: %d\n", current->student->physicGrade);
            printf("Chemistry Grade: %d\n\n", current->student->chemistryGrade);
        }
        current = current->next;
    }
    return NULL; // Возвращаем NULL, так как тип void*
}


void* PrintExcellentStudentsWithoutTwos(void* list) {
    List* l = (List*)list;
    Node* current = l->head;
    while (current != NULL) {
        if (current->student->mathGrade != 2 &&
            current->student->physicGrade != 2 &&
            current->student->chemistryGrade != 2) {
            printf("Name: %s %s\n", current->student->name, current->student->surname);
            printf("Group: %s\n", current->student->group);
            printf("Age: %d\n", current->student->age);
            printf("Math Grade: %d\n", current->student->mathGrade);
            printf("Physic Grade: %d\n", current->student->physicGrade);
            printf("Chemistry Grade: %d\n\n", current->student->chemistryGrade);
        }
        current = current->next;
    }
}


void* PrintList(void* list) {
    List* l = (List*)list;
    Node* current = l->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
    return NULL; // Возвращаем NULL, так как тип void*
}


void* FreeList(void* list) {
    List* l = (List*)list;
    Node* current = l->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(l);
    return NULL; // Возвращаем NULL, так как тип void*
}

