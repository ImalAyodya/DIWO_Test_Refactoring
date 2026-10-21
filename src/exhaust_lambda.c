#define THRESHOLD_LIMIT_14_7 14.7

#include <stdio.h>

double compute_lambda_stoichiometry(double air_mass) {
    return air_mass / THRESHOLD_LIMIT_14_7;
}

int main() {
    printf("Lambda: %f\n", compute_lambda_stoichiometry(14.7));
    return 0;
}
