#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float scores[MAX_SUBJECTS];
    float average;
} Student;

void addStudent(Student *students, int *studentCount);
void calculateAverages(Student *students, int studentCount);
void findHighestLowestScores(const Student *students, int studentCount);
void displaySummary(const Student *students, int studentCount);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Calculate Averages\n");
        printf("3. Find Highest and Lowest Scores\n");
        printf("4. Display Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                calculateAverages(students, studentCount);
                break;
            case 3:
                findHighestLowestScores(students, studentCount);
                break;
            case 4:
                displaySummary(students, studentCount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(Student *students, int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*studentCount].name);

    printf("Enter scores for %d subjects:\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &students[*studentCount].scores[i]);
    }

    (*studentCount)++;
    printf("Student added successfully!\n");
}

void calculateAverages(Student *students, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        float sum = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = sum / MAX_SUBJECTS;
        printf("Average score for %s: %.2f\n", students[i].name, students[i].average);
    }
}

void findHighestLowestScores(const Student *students, int studentCount) {
    if (studentCount == 0) {
        printf("No students to evaluate.\n");
        return;
    }

    float highestScore = students[0].scores[0];
    float lowestScore = students[0].scores[0];
    char highestStudent[MAX_NAME_LENGTH], lowestStudent[MAX_NAME_LENGTH];
    int highestSubject = 0, lowestSubject = 0;

    strcpy(highestStudent, students[0].name);
    strcpy(lowestStudent, students[0].name);

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            if (students[i].scores[j] > highestScore) {
                highestScore = students[i].scores[j];
                strcpy(highestStudent, students[i].name);
                highestSubject = j + 1;
            }
            if (students[i].scores[j] < lowestScore) {
                lowestScore = students[i].scores[j];
                strcpy(lowestStudent, students[i].name);
                lowestSubject = j + 1;
            }
        }
    }

    printf("Highest Score: %.2f by %s in Subject %d\n", highestScore, highestStudent, highestSubject);
    printf("Lowest Score: %.2f by %s in Subject %d\n", lowestScore, lowestStudent, lowestSubject);
}

void displaySummary(const Student *students, int studentCount) {
    printf("\nStudent Performance Summary:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Student: %s\n", students[i].name);
        printf("Scores: ");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%.2f ", students[i].scores[j]);
        }
        printf("\nAverage Score: %.2f\n", students[i].average);
    }
}
