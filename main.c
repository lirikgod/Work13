#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"
#define PI 3.1415
#define multi(a) ({ \
typeof(a) _a = a;   \
(_a * _a) + (_a * _a);})

int main() {
    int a = 5;
    printf("%d\t", a);
    printf("%d\t", multi(a++) * 2);
    printf("%d\t", a);
//    double area = 2 * PI;
//    printf("%f\n", area);
//    setlocale(LC_ALL, "RUS");
//    List* StudentList = InitList();
//    StudentList->append(StudentList, InitStudent(23, "Ksenia", "Tfgd", "???", "ghgjf4", 4, 5, 5));
//    StudentList->append(StudentList, InitStudent(14, "Vaho", "Tfgd", "???", "ghgjf4", 4, 4, 3));
//    StudentList->append(StudentList, InitStudent(17, "Timur", "Tfgd", "???", "ghgjf4", 4, 3, 3));
//    StudentList->append(StudentList, InitStudent(13, "Tim", "Ted", "M", "ISP-test", 5, 5, 5));
//    StudentList->printEtwo(StudentList);
//
//    StudentList->free(StudentList);
    return 0;
}
