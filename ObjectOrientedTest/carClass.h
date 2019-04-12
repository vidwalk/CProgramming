//
// Created by vidwalk on 12/04/19.
//

#pragma once

#include <stdbool.h>
#include <stdlib.h>
typedef struct car * carP;

carP carCreate(int hp, int seats);
void carStart(carP self);
void carDestroy(carP self);
void carStart(carP self);
void carTurnOff(carP self);
void carTune(carP self, int hp);
int carHp(carP self);
int carSeats(carP self);
bool carStarted(carP self);

