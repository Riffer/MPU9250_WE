/********************************************************************
* This is a library for the 9-axis gyroscope, accelerometer and magnetometer MPU6050.
*
* You'll find an example which should enable you to use the library.
*
* You are free to use it, change it or build on it. In case you like
* it, it would be cool if you give it a star.
*
* If you find bugs, please inform me!
*
* Written by Wolfgang (Wolle) Ewald
*
* For further information visit my blog:
*
* https://wolles-elektronikkiste.de/MPU6050-9-achsen-sensormodul-teil-1  (German)
* https://wolles-elektronikkiste.de/en/MPU6050-9-axis-sensor-module-part-1  (English)
*
*********************************************************************/

#include "MPU6050_WE.h"


/* Others */
uint8_t constexpr MPU6050_WE::WHO_AM_I_CODE               ;


/************  Constructors ************/

MPU6050_WE::MPU6050_WE(int addr)
    : MPU6500_WE(addr)
{
    // intentionally empty
}

MPU6050_WE::MPU6050_WE()
    : MPU6500_WE()
{
    // intentionally empty
}

MPU6050_WE::MPU6050_WE(TwoWire *w, int addr)
    : MPU6500_WE(w, addr)
{
    // intentionally empty
}

MPU6050_WE::MPU6050_WE(TwoWire *w)
    : MPU6500_WE(w)
{
    // intentionally empty
}

/************ Basic Settings ************/

    bool MPU6050_WE::init()
{
    return MPU6500_WE::init(WHO_AM_I_CODE);
}
