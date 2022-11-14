void avoid_opponent(){
    if (SensorValue(sharp_front_top) > 1100){
        while(SensorValue(sharp_front_top) > 900){
            control_motor(-127,-127);
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

    else if(SensorValue(sharp_short) > 1100){
        while(SensorValue(sharp_front_top) > 900){
            control_motor(127,127);
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
            control_motor(-60, -60);
        }  
        clearTimer(T1);
        while (time1(T1) < 600)
        {
            control_motor(60, -60);
        }
        stop_motor(); 
    }
}