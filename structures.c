#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// 1. Basic Structure
struct Employee {
    int id;
    char name[50];
};

// 2. Nested Structures
struct Address {
    char street[50];
    char city[50];
};

struct EmployeeWithAddress {
    int id;
    char name[50];
    struct Address address;  // Nested structure
};

// 3. Array of Structures
struct Student {
    int roll_no;
    char name[50];
};

void printStudent(struct Student s) {
    printf("Roll No: %d, Name: %s\n", s.roll_no, s.name);
}

// 4. Pointer to Structures
void printEmployeeDetails(struct Employee *emp) {
    printf("Employee ID: %d, Name: %s\n", emp->id, emp->name);
}

// 5. Passing Structures to Functions (by value)
void updateEmployee(struct Employee emp) {
    emp.id = 999;  // This change won't affect the original structure.
    printf("Updated Employee ID (by value): %d\n", emp.id);
}

// 6. Structure as Function Return
struct Employee createEmployee(int id, char *name) {
    struct Employee emp;
    emp.id = id;
    strcpy(emp.name, name);
    return emp;
}

// 7. Typedef with Structures
typedef struct {
    int x;
    int y;
} Point;

// 8. Bit Fields in Structures
struct BitField {
    unsigned int a : 4;  // 4 bits
    unsigned int b : 4;  // 4 bits
};

// 9. Dynamic Memory Allocation with Structures
struct DynamicEmployee {
    int id;
    char name[50];
};

struct DynamicEmployee* createDynamicEmployee(int id, char *name) {
    struct DynamicEmployee *emp = (struct DynamicEmployee*)malloc(sizeof(struct DynamicEmployee));
    emp->id = id;
    strcpy(emp->name, name);
    return emp;
}

// 10. Self-Referential Structures (Linked List Node)
struct Node {
    int data;
    struct Node *next;  // Pointer to the next node
};

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // 1. Basic Structure
    struct Employee emp1 = {101, "Alice"};
    printf("Employee ID: %d, Name: %s\n", emp1.id, emp1.name);

    // 2. Nested Structures
    struct EmployeeWithAddress emp2 = {102, "Bob", {"Baker Street", "London"}};
    printf("Employee ID: %d, Name: %s, Address: %s, %s\n", emp2.id, emp2.name, emp2.address.street, emp2.address.city);

    // 3. Array of Structures
    struct Student students[2] = {{1, "John"}, {2, "Jane"}};
    for (int i = 0; i < 2; i++) {
        printStudent(students[i]);
    }

    // 4. Pointer to Structures
    struct Employee *ptr = &emp1;
    printEmployeeDetails(ptr);

    // 5. Passing Structures to Functions (by value)
    updateEmployee(emp1);  // Note that the original structure is not modified

    // 6. Structure as Function Return
    struct Employee emp3 = createEmployee(103, "Charlie");
    printf("Returned Employee ID: %d, Name: %s\n", emp3.id, emp3.name);

    // 7. Typedef with Structures
    Point p1 = {10, 20};
    printf("Point: x = %d, y = %d\n", p1.x, p1.y);

    // 8. Bit Fields in Structures
    struct BitField bf = {3, 6};  // a will store 3, b will store 6
    printf("BitField: a = %d, b = %d\n", bf.a, bf.b);

    // 9. Dynamic Memory Allocation with Structures
    struct DynamicEmployee *emp4 = createDynamicEmployee(104, "David");
    printf("Dynamic Employee ID: %d, Name: %s\n", emp4->id, emp4->name);
    free(emp4);  // Don't forget to free allocated memory

    // 10. Self-Referential Structures (Linked List Node)
    struct Node n1 = {1, NULL};
    struct Node n2 = {2, NULL};
    struct Node n3 = {3, NULL};
    n1.next = &n2;
    n2.next = &n3;
    printList(&n1);

    return 0;
}
