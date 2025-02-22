/*
 * Autonomus car project.c
 *
 * Created: 03/02/2025 17:26:15
 * Author : andre
 */ 
#include "main.h"

static uint16t flag_dist = 0;
static uint16t dist_straight = 0;
static uint16t dist_right = 0;
static uint16t dist_left = 0;
static uint16t max_dist = 0;
static uint8t MAX;  // Changed to char to store 'S', 'R', 'L'
static uint8t FLAG_1 = 0;
static uint8t FLAG_2 = 0;
static uint8t FLAG_3 = 0;

void check_180deg(void);
void noObstacleDirection(void);
void gotoNOobstacle(void);

int main(void)
{
	DC_Motor_Initialize();
	ULTRA_Initialize();
	LCD_Initialize();
	ServoMotor_Initialize();
	while (1)
	{
		while (!FLAG_1)
		{
			//check surrounding area of robot by using servo motor and ultrasonic 
			check_180deg();
		}
		FLAG_1 = 0;

		while (!FLAG_2)
		{
			// after checking distance in the three given direction go the direction with longest distance
			noObstacleDirection();
		}
		FLAG_2 = 0;
		while (!FLAG_3)
		{
			// if distance decreases to 10 or less stop motor and start checking surrounding agin 
			ULTRA_Distance(&flag_dist);
			if (flag_dist <= 10)
			{
				LCD_Clear_Screen();
				LCD_Write_String("STOP");
				DC_Brake(DC_MOTOR1);
				DC_Brake(DC_MOTOR2);
				FLAG_3 = 1;
				_delay_ms(1000);
			}
			else
			{
				gotoNOobstacle();
			}
		}
		FLAG_3 = 0;
	}
}
// Scan surroundings and determine best direction
void check_180deg(void)
{
	ULTRA_Initialize();
	ServoMotor_Rotate(Angle_0);
	_delay_ms(1500);  // Add a delay to ensure the servo motor has time to rotate
	ULTRA_Distance(&dist_straight);
	_delay_ms(500);  // Add an additional delay for sensor reading
	LCD_Clear_Screen();
	LCD_Write_String("Straight: ");
	LCD_Write_IntegerNumber(dist_straight);
	_delay_ms(1000);

	ServoMotor_Rotate(Angle_N90);
	_delay_ms(1000);  // Add a delay to ensure the servo motor has time to rotate
	ULTRA_Distance(&dist_right);
	_delay_ms(500);  // Add an additional delay for sensor reading
	LCD_Clear_Screen();
	LCD_Write_String("Right: ");
	LCD_Write_IntegerNumber(dist_right);
	_delay_ms(1000);

	ServoMotor_Rotate(Angle_P90);
	_delay_ms(1000);  // Add a delay to ensure the servo motor has time to rotate
	ULTRA_Distance(&dist_left);
	_delay_ms(500);  // Add an additional delay for sensor reading
	LCD_Clear_Screen();
	LCD_Write_String("Left: ");
	LCD_Write_IntegerNumber(dist_left);
	_delay_ms(1000);

	ServoMotor_Rotate(Angle_0);
	LCD_Clear_Screen();
	LCD_Write_String("Servo Reset");

	FLAG_1 = 1;
}

// Determine the best direction based on distance
void noObstacleDirection(void)
{
	if (dist_straight >= dist_right && dist_straight >= dist_left)
	{
		MAX = 'S';
		max_dist = dist_straight;
	}
	else if (dist_right >= dist_straight && dist_right >= dist_left)
	{
		MAX = 'R';
		max_dist = dist_right;
	}
	else if (dist_left >= dist_straight && dist_left >= dist_right)
	{
		MAX = 'L';
		max_dist = dist_left;
	}

	LCD_Clear_Screen();
	LCD_Write_String("Best Dir: ");
	LCD_Write_Character(MAX);
	LCD_Write_String(" ");
	LCD_Write_IntegerNumber(max_dist);
	_delay_ms(1000);
	FLAG_2 = 1;
}

// Move in the direction with the most space
void gotoNOobstacle(void)
{
	LCD_Clear_Screen();
	switch (MAX)
	{
		//Incase straight was the largest path move forward  
		case 'S':
		LCD_Write_String("Direction: STRAIGHT");
		DC_Rotate(DC_MOTOR1, DC_CW);
		DC_Rotate(DC_MOTOR2, DC_CW);
		break;
		//Incase Right was the largest path move forward  
		case 'R':
		LCD_Write_String("Direction: RIGHT");
		DC_Rotate(DC_MOTOR2, DC_CW);
		break;
        //Incase left was the largest path move forward  
		case 'L':
		LCD_Write_String("Direction: LEFT");
		DC_Rotate(DC_MOTOR1, DC_CW);
		break;
	}

	MAX = 0;
	dist_straight = 0;
	dist_right = 0;
	dist_left = 0;
	max_dist = 0;
}