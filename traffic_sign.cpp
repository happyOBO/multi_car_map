#include "traffic_sign.h"


GLfloat pallet[3] = {0.0,0.0,0.0};

TrafficSign::TrafficSign(GLfloat x, GLfloat z, GLfloat ang ,GLfloat color, int t)
:sign_x(x), sign_z(z), angle(ang), sign(color),term(t), counts(0)
{

}

TrafficSign::TrafficSign()
{
}

void TrafficSign::SetTFinfo(GLfloat x, GLfloat z, GLfloat ang ,GLfloat color, int t)
{
    sign_x = x;
    sign_z = z;
    angle = ang;
    sign = color;
    term = t;
    counts = 0;
}


void Set_color(int i)
{
    for(int j = 0; j<3; j++)
    {

        if(i == j) pallet[j] = 1.0;
        else pallet[j] =  0.0;
    }
}

bool TrafficSign::Return_sign()
{
    if(sign == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void TrafficSign::DrawTrafficSign(int pv)
{

    pair<GLfloat, GLfloat> pair_D = Return_point_d(pv);
    GLfloat dxx = pair_D.first;
    GLfloat dzz = pair_D.second;

    if(counts > term)
    {
        ChangeSign();
        counts = 0;
    }
    counts +=1;
    glPushMatrix();
        glTranslatef(sign_x + 100.0 +dxx ,0.0,sign_z - 600.0 + dzz);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        glPushMatrix();
//            glTranslatef(150.0,0.0,0.0);
            glColor3f(0.74,0.74,0.74);
            glRotatef(90.0 ,1.0,0.0,0.0);
            gluCylinder(quadratic,25.0,25.0,500.0,32,32);
        glPopMatrix();
        glPushMatrix();
            Set_color(sign);
            glColor3f(0.74,0.74,0.74);
            glRotatef(angle,0.0,1.0,0.0);
            gluCylinder(quadratic,25.0,25.0,400.0,32,32);
            glColor3f(pallet[0],pallet[1],pallet[2]);
            glTranslatef(0.0,0.0,50.0);
            gluCylinder(quadratic,50.0,50.0,700.0,32,32);
        glPopMatrix();

    glPopMatrix();
}
void TrafficSign::ChangeSign()
{
    if(sign == 0) sign = 1;
    else sign = 0;
}
