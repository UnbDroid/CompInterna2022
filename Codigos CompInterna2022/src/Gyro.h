#ifndef GYRO_H
#define GYRO_H
#include <Wire.h>
#include <Arduino.h>


class Gyro
{
    public:

    Gyro();

    ~Gyro();

    long requestData(int valorEixo);

    long filter(int count);

    private:

    Gyro *gyroscope;

};


#endif