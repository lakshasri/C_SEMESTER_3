#include <stdio.h>

#define SUB 3  

void inputMarks(int m[], int *s) {
    printf("Enter marks for %d subjects: ", SUB);
    for (int i = 0; i < SUB; i++) {
        scanf("%d", &m[i]);
        *s += m[i];  
    }
}

char getGrade(double a) {
    if (a >= 90) return 'A';
    else if (a >= 80) return 'B';
    else if (a >= 70) return 'C';
    else if (a >= 60) return 'D';
    else return 'F';
}

int main() {
    int marks[SUB], sum = 0;
    double avg;

    inputMarks(marks, &sum);
    avg = sum / (double)SUB;

    printf("\nAverage Marks: %.2lf\n", avg);
    printf("Grade: %c\n", getGrade(avg));

    return 0;
}
