void moving_forward()
{
    writeDebugStreamLine("%s", "moving forward");
    clearTimer(T3);
    // move forward
    control_motor(100, 100);
    while (time1(T3) < 2500)
    {
        // scan ball
        if (ball_found == 1)
        {
            stop_motor();
            writeDebugStreamLine("%s", "ball found in moving forward");
            return;
        }

        // scan boundaries
        scan_boundary();
        if (line_sensor_status != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
        }
    }
    stop_motor();
    ball_found = 0;
    return;
}