#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
};

void insertStudent(struct Student students[MAX_STUDENTS], int *numStudents) {
    if (*numStudents < MAX_STUDENTS) {
        printf("Enter Roll Number: ");
        scanf("%d", &students[*numStudents].rollNumber);

        printf("Enter Name: ");
        scanf("%s", students[*numStudents].name);

        printf("Enter Marks: ");
        scanf("%f", &students[*numStudents].marks);

        (*numStudents)++;
        printf("Student inserted successfully.\n");
    } else {
        printf("Cannot insert. Maximum number of students reached.\n");
    }
}

void deleteStudent(struct Student students[MAX_STUDENTS], int *numStudents, int rollNumber) {
    int index = -1;
    for (int i = 0; i < *numStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *numStudents - 1; ++i) {
            students[i] = students[i + 1];
        }
        (*numStudents)--;
        printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
    } else {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

int linearSearch(struct Student students[MAX_STUDENTS], int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

void displayMatrix(int matrix[3][3]) {
    printf("Matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(int matrix1[3][3], int matrix2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixMultiplication(int matrix1[3][3], int matrix2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int matrix1[3][3], matrix2[3][3], resultMatrix[3][3];

    // Inserting students
    insertStudent(students, &numStudents);
    insertStudent(students, &numStudents);
    insertStudent(students, &numStudents);

    // Deleting a student
    int rollToDelete;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollToDelete);
    deleteStudent(students, &numStudents, rollToDelete);

    // Linear search
    int rollToSearch;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollToSearch);
    int searchIndex = linearSearch(students, numStudents, rollToSearch);
    if (searchIndex != -1) {
        printf("Student found at index %d.\n", searchIndex);
    } else {
        printf("Student not found.\n");
    }

    // Matrix operations
    printf("Enter elements of Matrix 1 (3x3):\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2 (3x3):\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Displaying matrices
    printf("Matrix 1:\n");
    displayMatrix(matrix1);
    printf("Matrix 2:\n");
    displayMatrix(matrix2);

    // Matrix addition
    matrixAddition(matrix1, matrix2, resultMatrix);
    printf("Matrix Addition Result:\n");
    displayMatrix(resultMatrix);

    // Matrix multiplication
    matrixMultiplication(matrix1, matrix2, resultMatrix);
    printf("Matrix Multiplication Result:\n");
    displayMatrix(resultMatrix);

    return 0;
}
