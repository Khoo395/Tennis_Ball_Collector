#include "motor_control.h"
#include "sensor_output.h"

int  collect_ball(){
    activate_roller();
    move_forward();
    clearTimer(T1); 
    while(time1(T1) < 10000){
        if(is_ball_on_vehicle() == 1){
            stop_roller();
            move_stop();
            return 1; 
        }
        else if(scan_boundary()!= NO_BOUNDARY_DETECTED){
            // Do boundary Avoidance 
        }
    }
    stop_roller();
    move_stop();
    return 0; 
}