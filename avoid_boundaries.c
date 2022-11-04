void avoid_boundaries(BoundarySide line_sensor)
{
    if (line_sensor == FRONT_LEFT)
    {
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move backward
            control_motor(-60, -60);
        }
        clearTimer(T2);
        while (time1(T2) < 500)
        {
            // rotate CW
            control_motor(60, -60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor == BACK_LEFT)
    {
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move forward
            control_motor(60, 60);
        }
        clearTimer(T2);
        while (time1(T2) < 500)
        {
            // rotate CCW
            control_motor(-60, 60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor == FRONT_RIGHT)
    {
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move backward
            control_motor(-60, -60);
        }
        clearTimer(T2);
        while (time1(T2) < 500)
        {
            // rotate CCW
            control_motor(-60, 60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor == BACK_RIGHT)
    {
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move forward
            control_motor(60, 60);
        }
        clearTimer(T2);
        while (time1(T2) < 500)
        {
            // rotate CW
            control_motor(60, -60);
        }
        stop_motor();
        return;
    }
}
