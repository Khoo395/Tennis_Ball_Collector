#include <stdio.h>
#include <stdbool.h>

#pragma config(Sensor, in1, sharp_front_top, sensorAnalog)
#pragma config(Sensor, in2, sharp_front_bottom_l, sensorAnalog)
#pragma config(Sensor, in3, sharp_front_bottom_r, sensorAnalog)
#pragma config(Motor, port1, left_driver, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, right_driver, tmotorVex393_HBridge, openLoop)

bool starting_procedure() {
    //parameters for starting
    float sp_time = 0; //how long should the robot move forward when starting
    float sp_speed = 50;        //max speed in competition (50 for testing only)

    float starting_sp_time = 0;
    float sp_time_elapsed = 0;

    //Declare variables
    float boundary_starting_time = 0;
    float boundary_ending_time = 0;
    float boundary_time = 0;
    float total_boundary_time = 0;
    float opponent_starting_time = 0;
    float opponent_ending_time = 0;A
    float opponent_time = 0;
    float total_opponent_time = 0;
    float current_time = 0;

    while (true) {
        motor[left_driver] = sp_speed;
        motor[right_driver] = sp_speed;
        if (SensorValue(sharp_front_top) < positive_detection_value) {
            if (SensorValue(sharp_front_bottom_l) > positive_detection_value ||
                SensorValue(sharp_front_bottom_r) > positive_detection_value) {
                return BALL_FOUND;
            }
        }

//        if scan_boundaries()
//        {
//            boundary_starting_time = nSysTime;
//            avoid_boundaries()
//            boundary_ending_time = nSysTime;
//            boundary_time = boundary_starting_time - boundary_ending_time;
//            total_boundary_time += boundary_time;
//            boundary_time = 0;
//        }
//
//        scan_opponents()

        current_time = nSysTime;
        sp_time_elapsed = starting_sp_time - current_time - total_boundary_time - total_opponent_time;
        if (sp_time_elapsed > sp_time) {
            motor[left_driver] = 0;
            motor[right_driver] = 0;
            break;
        }
    }
    return BALL_NOT_FOUND;
}

}
