//
// Created by vidwalk on 12/04/19.
//
#include "carClass.h"
#include <stdio.h>


struct car{
    int hp;
    int seats;
    bool started;
};

carP carCreate(int hp, int seats)
{
    carP self = malloc(sizeof(struct car));
    self->hp = hp;
    self->seats = seats;
    self->started = false;
    return self;
}

void carDestroy(carP self)
{
    free(self);
}

void carStart(carP self)
{
    self->started = true;
}

void carTurnOff(carP self)
{
    self->started = false;
}

void carTune(carP self, int hp)
{
    self->hp = hp;
}

int carHp(carP self){
    return self->hp;
}

int carSeats(carP self)
{
    return self->seats;
}

bool carStarted(carP self)
{
    return self->started;
}