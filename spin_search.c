bool spin_search()
{
    int compass_status = read_compass();
    int goal_compass_status = compass_status + 2;
    if (goal_compass_status == 6)
    {
        goal_compass_status = 1;
    }
    if (goal_compass_status == 7)
    {
        goal_compass_status = 2;
    }
    // Rotate CCW
    control_motor(-60, 60);
    while (1)
    {
        // Scan for ball
        bool ball_found = scan_ball();
        if (ball_found == true)
        {
            writeDebugStreamLine("%s", "ball found...");
            return ball_found;
        }
        else
        {
            // Scan for boundaries
            BoundarySide line_sensor_status = scan_boundary();
            if (line_sensor_status != NO_BOUNDARY_DETECTED)
            {
                avoid_boundaries(line_sensor_status);
            }

            // adding turning degree
            if (read_compass() == goal_compass_status)
            {
                stop_motor();
                return BALL_NOT_FOUND;
            }
        }
    }
    //
    //        scan_opponents()
}
