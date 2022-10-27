#pragma config(Motor, port1, left_driver, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port2, roller_driver, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor, port3, ball_dispense_driver, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port10, right_driver, tmotorVex393_HBridge, openLoop)

void move_forward(){
    motor(left_driver) = 127; 
    motor(right_driver) = 127; 
}

void move_backward(){
    motor(left_driver) = -127; 
    motor(right_driver) = -127; 
}

void stop_motor(){
    motor(left_driver) = 0; 
    motor(right_driver) = 0; 
}

void activate_roller(){
    motor(motor_driver) = 127; 
}

void stop_roller(){
    motor(motor_driver) = 0; 
}

void open_dispense_gate(){
}

void close_dispense_gate(){
}