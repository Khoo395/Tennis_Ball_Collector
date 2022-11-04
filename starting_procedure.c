

bool starting_procedure()
{
    // parameters for starting
    float sp_time = 1000; // how long should the robot move forward when starting
    float sp_speed = 127; // max speed in competition

    float starting_sp_time = nSysTime;
    float sp_time_elapsed = 0;

    // Declare variables
    float total_boundary_time = 0;
    float current_time = 0;

    // loop
    while (1)
    {
        control_motor(sp_speed, sp_speed - 45);
        ball_identified = scan_ball();
        if (ball_identified == BALL_FOUND)
        {
            stop_motor();
            return BALL_FOUND;
        }

        // Scan for boundaries
        line_sensor_status = scan_boundary();
        if (line_sensor_status != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
            total_boundary_time += 1500;
        }

        //        scan_opponents()

        current_time = nSysTime;
        sp_time_elapsed = current_time - starting_sp_time - total_boundary_time;
        if (sp_time_elapsed > sp_time)
        {
            stop_motor();
            return BALL_NOT_FOUND;
        }
    }
}
