bool moving_forward()
{
    clearTimer(T3);
    control_motor(100, 100);
    while (time1(T3) < 2500)
    {
        // scan ball
        if (scan_ball() == BALL_FOUND)
        {
            stop_motor();
            return BALL_FOUND;
        }

        // scan boundaries
        line_sensor_status = scan_boundary();
        if (scan_boundary() != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
        }
    }
    stop_motor();
    return BALL_NOT_FOUND;
}