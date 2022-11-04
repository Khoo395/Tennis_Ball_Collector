void collect_ball()
{
    writeDebugStreamLine("%s", "collecting ball...");
    // activate roller
    activate_roller(127);

    // move forward
    // max speed will go out of boundaries

    clearTimer(T1);
    while (time1(T1) < 4000)
    {
        control_motor(80, 80);
        is_ball_on_vehicle();
        if (ball_collected == 1)
        {
            writeDebugStreamLine("%s", "ball collected");
            stop_roller();
            stop_motor();
            return;
        }

        // scan boundaries
        scan_boundary();
        if (line_sensor_status != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
        }
    }
    stop_roller();
    stop_motor();
    ball_found = 0;
    ball_collected = 0;
    writeDebugStreamLine("%s", "ball not collected");
    return;
}