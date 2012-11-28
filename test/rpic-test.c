#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rpic-lib.h"

int main(int argc, char *argv[])
{
	/// Device test
		
	printf("### Device Test - Start ###\n");
	
	int dev = rpi_car_dev_open();
	
    if (dev < 0) {
		printf("Device open failed, rval = %d\n", dev);
		exit(1);
    }
    else {
		printf("Device open succeeded.\n");
	}

    char* version = rpi_car_dev_version();
	
    if (version != NULL) {
		printf("Device firmware version: %s\n", version);
	}
    else {
		printf("Device get version failed.\n");
		exit(2);
    }
		
	printf("### Device Test - Stop ###\n");
		
	/// Servo management
		
	printf("### Servo Test - Start ###\n");
	
	rpi_car_stop();
	usleep(10000000);
	rpi_car_forward();
	usleep(10000000);
	rpi_car_backward();
	usleep(10000000);
	rpi_car_left();
	usleep(10000000);
	rpi_car_forward();
	usleep(10000000);
	rpi_car_backward();
	usleep(10000000);
	rpi_car_stop();
	
	printf("### Servo Test - Stop ###\n");

	/// End
	
	rpi_car_dev_close(dev);
	
	return 0;
}

