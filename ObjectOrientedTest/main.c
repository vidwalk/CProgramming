#include <stdio.h>
#include "carClass.h"

int main() {
    carP myCar = carCreate(200, 4);
    printf("the horse power of my carp %d, the nr of seats of my car %d\n", carHp(myCar), carSeats(myCar));
    printf(carStarted(myCar)? "Is the start started? true\n" : "Is the start started? false\n");
    carStart(myCar);
    printf(carStarted(myCar)? "Is the start started? true\n" : "Is the start started? false\n");
    carTune(myCar, 250);
    printf("the horse power of my carp %d\n", carHp(myCar));
    carTurnOff(myCar);
    printf(carStarted(myCar)? "Is the start started? true\n" : "Is the start started? false\n");
    carDestroy(myCar);
    return 0;
}