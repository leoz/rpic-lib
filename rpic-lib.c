/******************************************************************************
 *  Copyright (C) 2012 - 2013, Leonid Zolotarev
 *
 *  Licensed under the terms of the BSD license, see file COPYING
 *  for details.
 *
 *  Raspberry Pi Car Library
 *
 *  Source file for the rpic-lib
 *
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "rpic-lib.h"

#if defined(linux)

#if defined(__ia64__) || defined(__i386__) || defined(__x86_64__)

#define SERVO_0 1
#define SERVO_1 2
#define SERVO_2 3
#define SERVO_3 4

#define AVRSLAVE_ADDR 0

#define rj_setservo(a,b)
#define rj_open(a,b) 0
#define rj_getversion() "VOID"

#elif defined(__arm__)


#include "juice/juice-dev.h"
#include "juice/juice.h"

#else
#error Architecture is not supported
#endif

#else
#error OS is not supported
#endif

void rpi_car_forward()
{
    printf("### RPi Car Forward ###\n");
    rj_setservo(SERVO_0, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_1, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_2, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_3, RPI_CAR_VAL_BACKWARD);
}

void rpi_car_backward()
{
    printf("### RPi Car Backward ###\n");
    rj_setservo(SERVO_0, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_1, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_2, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_3, RPI_CAR_VAL_FORWARD);
}

void rpi_car_stop()
{
    printf("### RPi Car Stop ###\n");
    rj_setservo(SERVO_0, RPI_CAR_VAL_STOP);
    rj_setservo(SERVO_1, RPI_CAR_VAL_STOP);
    rj_setservo(SERVO_2, RPI_CAR_VAL_STOP);
    rj_setservo(SERVO_3, RPI_CAR_VAL_STOP);
}

void rpi_car_left()
{
    printf("### RPi Car Left Turn ###\n");
    rj_setservo(SERVO_0, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_1, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_2, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_3, RPI_CAR_VAL_BACKWARD);
}

void rpi_car_right()
{
    printf("### RPi Car Right Turn ###\n");
    rj_setservo(SERVO_0, RPI_CAR_VAL_FORWARD);
    rj_setservo(SERVO_1, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_2, RPI_CAR_VAL_BACKWARD);
    rj_setservo(SERVO_3, RPI_CAR_VAL_FORWARD);
}


void rpi_car_deccelerate()
{
    printf("### RPi Car Deccelerate ###\n");
}

void rpi_car_accelerate()
{
    printf("### RPi Car Accelerate ###\n");
}

#define RPI_CAR_DEV_NAME "/dev/i2c-1"

int rpi_car_dev_open()
{
    int dev = -1;
    dev = rj_open(RPI_CAR_DEV_NAME, AVRSLAVE_ADDR);
    return dev;
}

void rpi_car_dev_close(int dev)
{
    close (dev);
}

char* rpi_car_dev_version()
{
    char* ver = NULL;
    ver = rj_getversion();
    return ver;
}


