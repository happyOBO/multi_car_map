#include "car.h"

const double PI = 3.14159;

void Car::Newcolor()
{
    srand((unsigned int)time(0));
    for(int i = 0;i<3;i++)
    {
        car_color[i] = (float)((rand() + 20000 + int(init_car_x +init_car_z ))%256)/256;
    }
}

Car::Car(GLfloat x, GLfloat z)
    : init_car_x(x), init_car_z(z) , car_velocity(0.0), car_rotate(90.0)
{
    car_x = init_car_x;
    car_z = init_car_z;
    Newcolor();
}

Car::Car()
{

}

void Car::SetCarInfo(GLfloat x, GLfloat z, GLfloat angle)
{
    init_car_x = x;
    init_car_z = z;
    car_velocity = 0.0;
    car_rotate = angle;
    car_x = init_car_x;
    car_z = init_car_z;
    Newcolor();
}

void Car::Draw_Car(bool stp)
{

    if(!stp)
    {
        Friction();
        car_x += 0.2*car_velocity*cos(-PI/180 *car_rotate);
        car_z += 0.2*car_velocity*sin(-PI/180 *car_rotate);
    }
    glPushMatrix();
        glTranslatef(car_x ,0.0,car_z);
        glRotatef(car_rotate ,0.0,1.0,0.0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        glColor3f(car_color[0], car_color[1], car_color[2]);
        glPushMatrix();
            glTranslatef(-75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-75.0,-25.0,-25.0);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glutSolidCube(100);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(75.0,-25.0,-25.0);
            glutSolidCube(50);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(75.0,-25.0,25.0);
            glutSolidCube(50);
        glPopMatrix();
    glPopMatrix();
}


pair <GLfloat, GLfloat> Car::Return_loc()
{
    return make_pair(car_x,car_z);
}

GLfloat Car::Return_angle()
{

    return car_rotate;
}

void Car::Control_velocity(bool is_accel)
{

    if(is_accel && car_velocity < 50.0)
    {
        car_velocity += 0.1;
    }
    else if(!is_accel && -50.0 < car_velocity )
    {
            car_velocity -= 0.1;
    }
}

void Car::move_car(GLfloat add_x, GLfloat add_z)
{
    car_x -= 3*add_x;
    car_z -= 3*add_z;
}


void Car::Friction()
{

    if(car_velocity > 0)
        car_velocity -= 0.05;
    else if(car_velocity < 0)
        car_velocity += 0.05;
}
void Car::Rotate(bool is_right)
{
    if(is_right)
    {

        car_rotate -= 6.0;
    }
    else
        car_rotate += 6.0;

//    cout<<car_rotate<<endl;
    if(car_rotate>= 360.0 || car_rotate <= -360.0)
        car_rotate = 0.0;
}


void Car::AutoMove()
{
    if( -8000 < car_z && car_z <8000 && -20000 < car_x && car_x <20000)
    {
        Control_velocity(true);
    }
    else
    {
        Newcolor();
        car_x = init_car_x;
        car_z = init_car_z;
        car_velocity = 0.0;
    }

}
