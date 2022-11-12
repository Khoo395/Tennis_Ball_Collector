// parameters for starting
float sp_time = 4500; // how long should the robot move forward when starting
float sp_speed = 127; // max speed in competition

void starting_procedure()
{
    float starting_sp_time = nSysTime;
    float sp_time_elapsed = 0;
    float total_boundary_time = 0;
    float current_time = 0;

    // loop
    while (1)
    {
        writeDebugStreamLine("%s", "starting procedure...");
        // move forward
        control_motor(sp_speed, sp_speed - 45);
        scan_ball();
        if (ball_found == 1)
        {
            writeDebugStreamLine("%s", "ball found from starting procedure");
            stop_motor();
            return;
        }

        // Scan for boundaries
        scan_boundary();
        if (line_sensor_status != NO_BOUNDARY_DETECTED)
        {
            avoid_boundaries(line_sensor_status);
            total_boundary_time += 1500;
        }
        avoid_opponent(); 

        current_time = nSysTime;
        sp_time_elapsed = current_time - starting_sp_time - total_boundary_time;
        writeDebugStreamLine("%d", sp_time_elapsed);
        if (sp_time_elapsed > sp_time)
        {
            stop_motor();
            ball_found = 0;
            return;
        }
    }
}
