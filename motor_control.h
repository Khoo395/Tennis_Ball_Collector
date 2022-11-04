void control_motor(int left_speed, int right_speed)
{
    motor(left_driver) = left_speed;
    motor(right_driver) = right_speed;
    return;
}

void stop_motor()
{
    motor(left_driver) = 0;
    motor(right_driver) = 0;
    return;
}

void activate_roller(int roller_speed)
{
    motor(roller_driver) = roller_speed;
    return;
}

void stop_roller()
{
    motor(roller_driver) = 0;
    return;
}

void open_dispense_gate()
{
    clearTimer(T2);
    while (time1(T2) < 550)
    {
        motor(ball_dispense_driver) = 40;
    }
    motor(ball_dispense_driver) = 0;
    return;
}

void close_dispense_gate()
{
    if (SensorValue(ball_collection_limit) == 1)
    {
        sleep(2000);
        while (1)
        {
            dispense_limit_status = read_dispense_limit_switch();
            if (dispense_limit_status != 0)
            {
                motor(ball_dispense_driver) = -30;
            }
            else
            {
                motor(ball_dispense_driver) = 0;
                break;
            }
        }
    }
    return;
}

void turn_to_south_position()
{
    while (1)
    {
        compass_status = read_compass();
        if (compass_status != 4)
        {
            if (compass_status == 9)
            {
                writeDebugStreamLine("%s", "sth wrong");
            }
            if (compass_status >= 5)
            {
                control_motor(-50, 50);
            }
            else if (compass_status <= 3)
            {
                control_motor(50, -50);
            }
        }
        else if (compass_status == 4)
        {
            stop_motor();
            return;
        }
    }
}