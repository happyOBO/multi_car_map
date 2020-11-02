#include "user_car.h"
const double PI = 3.14159;

void UserCar::Newcolor()
{
    srand((unsigned int)time(0));
    for(int i = 0;i<3;i++)
    {
        car_color[i] = (float)((rand() + 20000 + int(init_car_x +init_car_z ))%256)/256;
    }
}

UserCar::UserCar(GLfloat x, GLfloat z , GLfloat angle)
    : init_car_x(x), init_car_z(z) , car_velocity(0.0), car_rotate(angle)
{
    car_x = init_car_x;
    car_z = init_car_z;
    Newcolor();
}

UserCar::UserCar()
{

}

void UserCar::SetCarInfo(GLfloat x, GLfloat z, GLfloat angle)
{
    init_car_x = x;
    init_car_z = z;
    car_velocity = 0.0;
    car_rotate = angle;
    car_x = init_car_x;
    car_z = init_car_z;
    Newcolor();
}

void UserCar::Draw_Car()
{
    Friction();
    glPushMatrix();
        car_x += 0.2*car_velocity*cos(-PI/180 *car_rotate);
        car_z += 0.2*car_velocity*sin(-PI/180 *car_rotate);
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


pair <GLfloat, GLfloat> UserCar::Return_loc()
{
    return make_pair(car_x,car_z);
}

void UserCar::Control_velocity(bool is_accel)
{
    cout<<car_x<<" "<<car_z<<endl;
    if(is_accel && car_velocity < 50.0)
    {
        car_velocity += 1.0;
    }
    else if(!is_accel && -50.0 < car_velocity )
    {
            car_velocity -= 1.0;
    }
}

void UserCar::move_car(GLfloat add_x, GLfloat add_z)
{
    car_x -= 3*add_x;
    car_z -= 3*add_z;
}


void UserCar::Friction()
{

    if(car_velocity > 0)
        car_velocity -= 0.05;
    else if(car_velocity < 0)
        car_velocity += 0.05;
}
void UserCar::Rotate(bool is_right)
{
    if(is_right)
    {

        car_rotate -= 2.0;
    }
    else
        car_rotate += 2.0;

//    cout<<car_rotate<<endl;
    if(car_rotate>= 360.0 || car_rotate <= -360.0)
        car_rotate = 0.0;
}


void UserCar::AutoMove()
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

bool UserCar::is_Stop()
{
    if(car_velocity < 1 && -1 < car_velocity)
    {
        return true;
    }
    else return false;
}


GLfloat UserCar::Return_angle()
{

    int ang = int(car_rotate / 90) * 90;
    return float(car_rotate);
}
