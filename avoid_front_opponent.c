void avoid_front_opponent(){
    if (SensorValue(sharp_front_top) > 1100){
        while(SensorValue(sharp_front_top) > 900){
            control_motor(-127,-127);
            scan_boundary();
            if (line_sensor_status != NO_BOUNDARY_DETECTED){
                avoid_boundaries(line_sensor_status);
                return; 
            }
        }
        stop_motor();
        clearTimer(T1);
        while (time1(T1) < 600)
        {
            control_motor(-60, 60);
        }
        clearTimer(T1);
        while (time1(T1) < 1000)
        {
            control_motor(60, 60);
        }  
        clearTimer(T1);
        while (time1(T1) < 600)
        {
            control_motor(60, -60);
        }
        stop_motor();
    }
}