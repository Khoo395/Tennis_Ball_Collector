bool collect_ball()
{
    activate_roller(127);
    control_motor(80, 80);
    clearTimer(T1);
    while (time1(T1) < 7000)
    {
        if (is_ball_on_vehicle() == BALL_COLLECTED)
        {
            stop_roller();
            stop_motor();
            return BALL_COLLECTED;
        }

        // scan boundaries
        line_sensor_status = scan_boundary();
        if (scan_boundary() != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
        }
    }
    stop_roller();
    stop_motor();
    return BALL_NOT_COLLECTED;
}