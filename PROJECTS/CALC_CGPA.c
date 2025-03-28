#include <stdio.h>

#define SUB 5  // Number of subjects per semester
#define SEM 4  // Total number of semesters

void inputMarks(int isa1[], int isa2[], int esa[], int credits[]) {
    printf("Enter marks (ISA1, ISA2, ESA) and credits for %d subjects:\n", SUB);
    for (int i = 0; i < SUB; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("ISA1 (out of 40): ");
        scanf("%d", &isa1[i]);
        printf("ISA2 (out of 40): ");
        scanf("%d", &isa2[i]);
        printf("ESA (out of 100): ");
        scanf("%d", &esa[i]);
        printf("Credits: ");
        scanf("%d", &credits[i]);
    }
}

double calculateSGPA(int isa1[], int isa2[], int esa[], int credits[]) {
    double totalPoints = 0, totalCredits = 0;

    for (int i = 0; i < SUB; i++) {
        double isa_weighted = ((isa1[i] + isa2[i]) / 80.0) * 50.0;
        double esa_weighted = (esa[i] / 100.0) * 50.0;
        double totalMarks = isa_weighted + esa_weighted;

        int gradePoint;
        if (totalMarks >= 90) gradePoint = 10;
        else if (totalMarks >= 80) gradePoint = 9;
        else if (totalMarks >= 70) gradePoint = 8;
        else if (totalMarks >= 60) gradePoint = 7;
        else if (totalMarks >= 50) gradePoint = 6;
        else if (totalMarks >= 40) gradePoint = 5;
        else gradePoint = 0; // Fail case

        totalPoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    return totalCredits > 0 ? totalPoints / totalCredits : 0;
}

double calculateCGPA(double sgpa[], int semCount) {
    double sum = 0;
    for (int i = 0; i < semCount; i++) {
        sum += sgpa[i];
    }
    return sum / semCount;
}

int main() {
    int isa1[SUB], isa2[SUB], esa[SUB], credits[SUB];
    double sgpa[SEM];

    for (int i = 0; i < SEM; i++) {
        printf("\n---- Semester %d ----\n", i + 1);
        inputMarks(isa1, isa2, esa, credits);
        sgpa[i] = calculateSGPA(isa1, isa2, esa, credits);
        printf("SGPA for Semester %d: %.2lf\n", i + 1, sgpa[i]);
    }

    double cgpa = calculateCGPA(sgpa, SEM);
    printf("\nFinal CGPA after %d semesters: %.2lf\n", SEM, cgpa);

    return 0;
}
