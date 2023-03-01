#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/light_sensor.h>
#include <stdio.h>

#define TIME_STEP 64
#define MAX_ROT_SPEED 6.28

int main(int argc, char **argv) {
  
  wb_robot_init();

   WbDeviceTag left_wheel = wb_robot_get_device("left wheel motor");
   WbDeviceTag right_wheel = wb_robot_get_device("right wheel motor");
   WbDeviceTag left_sensor = wb_robot_get_device("ls4");
   WbDeviceTag right_sensor = wb_robot_get_device("ls3");
   WbDeviceTag left_sensor_wall = wb_robot_get_device("ls6");
   WbDeviceTag right_sensor_wall = wb_robot_get_device("ls1");
   wb_light_sensor_enable(left_sensor, 1);
   wb_light_sensor_enable(right_sensor, 1);
   wb_light_sensor_enable(left_sensor_wall, 1);
   wb_light_sensor_enable(right_sensor_wall, 1);
   wb_motor_set_position(left_wheel, INFINITY);
   wb_motor_set_position(right_wheel, INFINITY);
   wb_motor_set_velocity(left_wheel, 0.0);
   wb_motor_set_velocity(right_wheel, 0.0);
   
  while (wb_robot_step(TIME_STEP) != -1) {

    double left_value = wb_light_sensor_get_value(left_sensor);
    double right_value = wb_light_sensor_get_value(right_sensor);
    printf("prey left: %f \n", left_value);
    printf("prey right: %f \n", right_value);
    double left_value_wall = wb_light_sensor_get_value(left_sensor_wall);
    double right_value_wall = wb_light_sensor_get_value(right_sensor_wall);

    double left_speed = 0.4*(left_value*MAX_ROT_SPEED/2)+0.6*(left_value_wall*MAX_ROT_SPEED/2);
    double right_speed = 0.4*(right_value*MAX_ROT_SPEED/2)+0.6*(right_value_wall*MAX_ROT_SPEED/2);
    
    wb_motor_set_velocity(left_wheel, left_speed);
    wb_motor_set_velocity(right_wheel, right_speed);
    
  };
  
  wb_robot_cleanup();

  return 0;
}
