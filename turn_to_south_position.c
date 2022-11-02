#pragma config(Sensor, in1, sharp_front_top, sensorAnalog)
#pragma config(Sensor, in2, sharp_front_bottom_l, sensorAnalog)
#pragma config(Sensor, in3, sharp_front_bottom_r, sensorAnalog)
#pragma config(Sensor, in4, sharp_short, sensorAnalog)
#pragma config(Sensor, in5, dispense_limit_switch, sensorAnalog)
#pragma config(Sensor, in8, compass_power, sensorNone)
#pragma config(Sensor, dgtl1, compass1, sensorDigitalIn)
#pragma config(Sensor, dgtl2, compass2, sensorDigitalIn)
#pragma config(Sensor, dgtl3, compass3, sensorDigitalIn)
#pragma config(Sensor, dgtl4, compass4, sensorDigitalIn)
#pragma config(Sensor, dgtl5, front_r_line, sensorDigitalIn)
#pragma config(Sensor, dgtl7, front_l_line, sensorDigitalIn)
#pragma config(Sensor, dgtl8, ball_collection_limit, sensorDigitalIn)
#pragma config(Sensor, dgtl9, home_limit_r, sensorDigitalIn)
#pragma config(Sensor, dgtl10, home_limit_l, sensorDigitalIn)
#pragma config(Sensor, dgtl11, back_l_line, sensorDigitalIn)
#pragma config(Sensor, dgtl12, back_r_line, sensorDigitalIn)
#pragma config(Motor, port2, roller_driver, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor, port3, left_driver, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor, port8, right_driver, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port9, ball_dispense_driver, tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "sensor_output.h"
#include "motor_control.h"
#include "avoid_boundaries.c"
Orientation compass_status;

task main(){
while (1)
{
    compass_status = read_compass();
    if (compass_status != 4)
    {
        if (compass_status == 9){
            writeDebugStreamLine("%s", "sth wrong");
        }
        if (compass_status >= 5)
        {
            control_motor(-30, 30);
        }
        else if (compass_status <=3){
            control_motor(30, -30);
        }

    }
    else if (compass_status ==4){
        stop_motor();
    }
}
}
