#include <stdio.h>

void convTemp(double t, char s) {
    if (s == 'C') {
        printf("F: %.2lf°F\nK: %.2lfK\n", (t * 9 / 5) + 32, t + 273.15);
    } else if (s == 'F') {
        printf("C: %.2lf°C\nK: %.2lfK\n", (t - 32) * 5 / 9, (t - 32) * 5 / 9 + 273.15);
    } else if (s == 'K') {
        printf("C: %.2lf°C\nF: %.2lf°F\n", t - 273.15, (t - 273.15) * 9 / 5 + 32);
    } else {
        printf("Err! Use C, F, or K.\n");
    }
}

int main() {
    double t;
    char s;

    printf("Temp & Scale (C/F/K): ");
    scanf("%lf %c", &t, &s);

    convTemp(t, s);
    return 0;
}
