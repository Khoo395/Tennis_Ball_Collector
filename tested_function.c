// tested
// scan_ball
while (1)
{
	writeDebugStreamLine("sharp bottom left %d", read_sharp_front_bottom_l());
	writeDebugStreamLine("sharp bottom right %d", read_sharp_front_bottom_r());
	writeDebugStreamLine("sharp top %d", read_sharp_front_top());
	if (read_sharp_front_bottom_l() < BOTTOM_DIST_THRES || read_sharp_front_bottom_r() < BOTTOM_DIST_THRES)
	{
		if (read_sharp_front_top() > TOP_DIST_THRES)
		{
			writeDebugStreamLine("%d", BALL_FOUND);
		}
		else
		{
			writeDebugStreamLine("%d", BALL_NOT_FOUND);
		}
	}
	else
	{
		writeDebugStreamLine("%d", BALL_NOT_FOUND);
	}
	sleep(2000);
}

// motor speed
while (1)
{
	motor(left_driver) = 127;
	motor(right_driver) = 123;
	motor(ball_dispense_driver) = -127;

	motor(left_driver) = 50;
	motor(right_driver) = -50;
	while (1)
	{
		writeDebugStreamLine("sharp bottom left %d", read_sharp_front_bottom_l());
		writeDebugStreamLine("sharp bottom right %d", read_sharp_front_bottom_r());
		writeDebugStreamLine("sharp top %d", read_sharp_front_top());
		if (read_sharp_front_bottom_l() < BOTTOM_DIST_THRES || read_sharp_front_bottom_r() < BOTTOM_DIST_THRES)
		{
			if (read_sharp_front_top() > TOP_DIST_THRES)
			{
				writeDebugStreamLine("%d", BALL_FOUND);
				motor(left_driver) = 0;
				motor(right_driver) = 0;
				break;
			}
			else
			{
				writeDebugStreamLine("%d", BALL_NOT_FOUND);
			}
		}
		else
		{
			writeDebugStreamLine("%d", BALL_NOT_FOUND);
		}
	}
}

// in progress
motor(left_driver) = 127;
motor(right_driver) = 123;
motor(ball_dispense_driver) = -127;

while (1)
{
	if (read_sharp_front_bottom_l() < BOTTOM_DIST_THRES || read_sharp_front_bottom_r() < BOTTOM_DIST_THRES)
	{
		if (read_sharp_front_top() > TOP_DIST_THRES)
		{
			writeDebugStreamLine("%d", BALL_FOUND);
			motor(left_driver) = 0;
			motor(right_driver) = 0;
			break;
		}
		else
		{
			writeDebugStreamLine("%d", BALL_NOT_FOUND);
		}
	}
	else
	{
		writeDebugStreamLine("%d", BALL_NOT_FOUND);
	}
}