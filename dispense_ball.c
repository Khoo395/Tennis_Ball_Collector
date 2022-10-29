#include <motor_control.h>
#include <sensor_output.h>

int dispense_ball(){
    clearTimer(T1); 
    int success = 0; 
    if(is_gate_closed()){
        open_gate(); 
    }
    while(time1(T1) < 3000){
        if(!is_ball_on_vehicle()){
            success = 1; 
            break; 
        }
    }
    close_gate(); 
    clearTimer(T1);
    while(time1(T1) < 2000){
        if(is_gate_closed()){
        stop_gate(); 
        }
    }
    return success; 
}