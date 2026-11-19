
#include <stdio.h>
#include <math.h>

int main(void)
{
    double P, Q, S, cosphi;
    int i;

    for (i = 1; i <= 3; i++)
    {
        printf("\nConsumatorul %d\n", i);

        printf("Puterea activa P [kW]: ");
        if (scanf("%lf", &P) != 1 || P < 0)
        {
            printf("Valoare invalida!\n");
            return 1;
        }

        printf("Puterea reactiva Q [kvar]: ");
        if (scanf("%lf", &Q) != 1)
        {
            printf("Valoare invalida!\n");
            return 1;
        }

        S = sqrt(P * P + Q * Q);

        if (S == 0)
        {
            printf("Puterea aparenta este zero. cos phi nu poate fi calculat.\n");
            continue;
        }

        cosphi = P / S;

        printf("S = %.2f kVA\n", S);
        printf("cos phi = %.2f\n", cosphi);

        if (cosphi >= 0.92)
        {
            printf("Fara penalizari\n");
        }
        else if (cosphi >= 0.65)
        {
            printf("Energie reactiva facturata\n");
        }
        else
        {
            printf("Compensare obligatorie\n");
        }
    }

    return 0;
}
