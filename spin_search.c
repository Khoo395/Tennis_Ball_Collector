#pragma config(Sensor, in1, sharp_front_top, sensorAnalog)
#pragma config(Sensor, in2, sharp_front_bottom_l, sensorAnalog)
#pragma config(Sensor, in3, sharp_front_bottom_r, sensorAnalog)
#pragma config(Motor, port1, left_driver, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor, port10, right_driver, tmotorVex393_HBridge, openLoop)

bool spin_search() {
    //parameters for searching
    float positive_detection_value = 400; //according to sharp sensor calibration
    float search_distance = 80; //??dunno needed onot?10cm to 80cm according to data sheet
    int searching_speed = 50;

    float rotate_time = 2000;  //test out how many milliseconds it takes to rotate 360 degrees
    float starting_search_time = nSysTime;
    float search_time_elapsed = 0;

    //Declare variables
    float boundary_starting_time=0;
    float boundary_ending_time = 0;
    float boundary_time = 0;
    float total_boundary_time = 0;
    float opponent_starting_time=0;
    float opponent_ending_time = 0;
    float opponent_time = 0;
    float total_opponent_time = 0;
    float current_time = 0;


    while (true) {
        motor[left_driver] = searching_speed;
        motor[right_driver] = -searching_speed;
        if (SensorValue(sharp_front_top) < positive_detection_value) { //no enemy
            if (SensorValue(sharp_front_bottom_l) > positive_detection_value || //ball in range of 80
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
        search_time_elapsed = starting_search_time - current_time -total_boundary_time-total_opponent_time;
        if (search_time_elapsed> rotate_time){
            motor[left_driver] = 0;
            motor[right_driver] = 0;
            break;
        }
    }
    return BALL_NOT_FOUND;
}