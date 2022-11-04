void spin_search()
{
    // update compass status & set goal compass status
    // +2 is used because of the shaking compass
    read_compass();
    goal_compass_status = compass_status + 2;
    if (goal_compass_status == 6)
    {
        goal_compass_status = 1;
    }
    if (goal_compass_status == 7)
    {
        goal_compass_status = 2;
    }

    // // Rotate CCW
    // if (spin_CCW == 1)
    // {
    //     // Rotate CW
    //     control_motor(60, -60);
    //     spin_CCW = 0;
    // }
    // else if (spin_CCW == 0)
    // {
    //     // Rotate CCW
    //     control_motor(-60, 60);
    //     spin_CCW = 1;
    // }
    control_motor(60, -60);
    while (1)
    {
        // Scan for ball
        scan_ball();
        if (ball_found == 1)
        {
            writeDebugStreamLine("%s", "ball found... from spin search");
            return;
        }
        else
        {
            // Scan for boundaries
            scan_boundary();
            if (line_sensor_status != NO_BOUNDARY_DETECTED)
            {
                avoid_boundaries(line_sensor_status);
            }

            // turning for 360
            read_compass();
            if (compass_status == goal_compass_status)
            {
                stop_motor();
                ball_found = 0;
                return;
            }
        }
    }
    //
    //        scan_opponents()
}
