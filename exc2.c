#include <stdio.h>

int exc2(void) {
    float income[12];
    float tax[12];
    float tax_rate = 0;
    float income_lim = 0;
    float tax_rate_over = 0;
    float total_income = 0;
    float low_part = 0;
    float high_part = 0;
    int n = 0;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);
    printf("Enter income limit: ");
    scanf("%f", &income_lim);
    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &tax_rate_over);

    for (n = 0; n < 12; n++) {
        printf("Enter income for month %d: ", n + 1);
        scanf("%f", &income[n]);

        low_part = income_lim - total_income;
        if (low_part < 0) {
            low_part = 0;
        }
        if (low_part > income[n]) {
            low_part = income[n];
        }
        high_part = income[n] - low_part;

        tax[n] = low_part * tax_rate * 0.01 + high_part * tax_rate_over * 0.01;
        total_income = total_income + income[n];
    }

    printf("month     income      tax\n");
    for (n = 0; n < 12; n++) {
        printf("%5d%11.2f%9.2f\n", n + 1, income[n], tax[n]);
    }

    return 0;
}

int main(void) {
    exc2();
}
