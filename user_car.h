#ifndef USER_CAR_H_INCLUDED
#define USER_CAR_H_INCLUDED
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

class UserCar {
private :
    GLfloat init_car_x;
    GLfloat init_car_z;
    GLfloat car_x;
    GLfloat car_z;
    GLfloat car_velocity;
    GLfloat car_rotate;
    GLfloat car_color[3];
public :
    UserCar();
    UserCar(GLfloat x, GLfloat z , GLfloat angle);
    pair <GLfloat, GLfloat> Return_loc();
    void SetCarInfo(GLfloat x, GLfloat z, GLfloat angle);
    bool is_Stop();
    void Draw_Car();
    void Control_velocity(bool is_accel);
    void move_car(GLfloat add_x, GLfloat add_z);
    void Rotate(bool is_right);
    void Friction();
    void AutoMove();
    void Newcolor();
    GLfloat Return_angle();
};


#endif // USER_CAR_H_INCLUDED
