// int sharp_short_threshold = 1100;

bool back_to_origin()
{
    while (1)
    {
        turn_to_south_position();
        control_motor(-127, -82);
        // scan boundaries
        line_sensor_status = scan_boundary();
        if (scan_boundary() != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
            clearTimer(T2);
            while (time1(T2) < 1000)
            {
                // move backward
                control_motor(-127, -82);
            }
        }

        if (SensorValue(home_limit_r) == 0 || SensorValue(home_limit_l) == 0)
        {
            stop_motor();
            while (SensorValue(home_limit_r) != 0)
            {
                motor[right_driver] = -40;
            }
            motor[right_driver] = 0;
            while (SensorValue(home_limit_l) != 0)
            {
                motor[left_driver] = -40;
            }
            motor[left_driver] = 0;
            return true;
        }
    }
}
