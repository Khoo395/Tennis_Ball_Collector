void avoid_boundaries(BoundarySide line_sensor_number)
{
    if (line_sensor_number == FRONT_LEFT)
    {
        writeDebugStreamLine("%s", "front left line sensor activated");
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move backward
            control_motor(-60, -60);
        }
        clearTimer(T2);
        while (time1(T2) < 1200)
        {
            // rotate CW
            control_motor(60, -60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor_number == BACK_LEFT)
    {
        writeDebugStreamLine("%s", "back left line sensor activated");
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move forward
            control_motor(60, 60);
        }
        clearTimer(T2);
        while (time1(T2) < 1200)
        {
            // rotate CCW
            control_motor(-60, 60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor_number == FRONT_RIGHT)
    {
        writeDebugStreamLine("%s", "front right line sensor activated");
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move backward
            control_motor(-60, -60);
        }
        clearTimer(T2);
        while (time1(T2) < 1200)
        {
            // rotate CCW
            control_motor(-60, 60);
        }
        stop_motor();
        return;
    }
    else if (line_sensor_number == BACK_RIGHT)
    {
        writeDebugStreamLine("%s", "back right line sensor activated");
        clearTimer(T2);
        while (time1(T2) < 1000)
        {
            // move forward
            control_motor(60, 60);
        }
        clearTimer(T2);
        while (time1(T2) < 1200)
        {
            // rotate CW
            control_motor(60, -60);
        }
        stop_motor();
        return;
    }
}
