#include <motor_control.h>
#include <sensor_output.h>

int dispense_ball(){
    clearTimer(T1); 
    int success = 0; 
    while(time1(T1) < 3000){
        if(is_gate_closed()){
            open_gate(); 
        }
        if(!is_ball_on_vehicle()){
            success = 1; 
            break; 
        }
    }
    if(is_gate_open()){
            close_gate(); 
        }

    return success; 
}