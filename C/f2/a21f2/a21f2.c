#include <stdio.h>
#include "simpio.h"

int main() {
    float epidoma;
    int misthos, paidia;

    printf("Dwse vasiko mistho: ");
    misthos = GetInteger();

    printf("Dwse arithmo paidion: ");
    paidia = GetInteger();

    switch (paidia) {

        case 0:
            break;
        case 1:
            epidoma = 0.04 * misthos;
            break;
        case 2:
            epidoma = 0.09 * misthos;
            break;
        case 3:
            epidoma = 0.15 * misthos;
            break;
        default:
            epidoma = (0.15 * misthos) + (paidia - 3) * 0.04 * misthos;
    }

    printf("Epidoma: %g", epidoma);

    return 0;
}
