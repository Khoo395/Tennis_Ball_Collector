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
    writeDebugStreamLine("%s", "motor stopped");
    return;
}

void activate_roller(int roller_speed)
{
    motor(roller_driver) = roller_speed;
    writeDebugStreamLine("%s", "roller activated");
    return;
}

void stop_roller()
{
    motor(roller_driver) = 0;
    writeDebugStreamLine("%s", "roller stopped");
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
    writeDebugStreamLine("%s", "dispense gate opened");
    return;
}

void close_dispense_gate()
{
    while (1)
    {
        if (SensorValue(ball_collection_limit) == 1)
        {
            sleep(2000);
            while (1)
            {
                read_dispense_limit_switch();
                if (dispense_limit_status != 0)
                {
                    motor(ball_dispense_driver) = -30;
                }
                else
                {
                    motor(ball_dispense_driver) = 0;
                    return;
                }
            }
        }
        // if the ball is still in the car
        else if (SensorValue(ball_collection_limit) == 0)
        {
            sleep(1000);
        }
    }
    writeDebugStreamLine("%s", "dispense gate closed");
}

void turn_to_south_position()
{
    writeDebugStreamLine("%s", "turning to south position");
    while (1)
    {
        read_compass();
        for (int i = 0; i < 10; i++)
        {
            writeDebugStreamLine("%d", compass_status);
            if (compass_status != 4)
            {
                if (compass_status == 9)
                {
                    read_compass();
                }
                if (compass_status >= 5)
                {
                    control_motor(-45, 45);
                }
                else if (compass_status <= 3)
                {
                    control_motor(45, -45);
                }
            }
            else if (compass_status == 4)
            {
                stop_motor();
                writeDebugStreamLine("%s", "turned to south position");
                return;
            }
        }
    }
}