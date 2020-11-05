#include "map.h"



void DrawGround()
{
    GLfloat ground_size = 15000.0;
    GLfloat road_size = 250.0;
    GLfloat bangbang_station = 2400.0;
    GLfloat line_width = 20.0;
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(0.74,0.73,0.99);
        glVertex3f(- ground_size ,0.0, -ground_size);
        glVertex3f(- ground_size ,0.0, +ground_size);
        glVertex3f( ground_size ,0.0, ground_size);
        glVertex3f( ground_size ,0.0, -ground_size);
    glEnd();


    glColor3f(0.64,0.63,0.89);
    // bangbang street
    glBegin(GL_POLYGON);
        glVertex3f(- 2*road_size ,0.0, -ground_size);
        glVertex3f(- 2*road_size ,0.0, +ground_size);
        glVertex3f( 2*road_size ,0.0, ground_size);
        glVertex3f( 2* road_size ,0.0, -ground_size);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- ground_size ,0.0, -2*road_size + bangbang_station);
        glVertex3f(- ground_size ,0.0, +2*road_size + bangbang_station);
        glVertex3f( ground_size ,0.0, 2*road_size + bangbang_station);
        glVertex3f( ground_size ,0.0, -2*road_size + bangbang_station);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- ground_size ,0.0, -2*road_size - bangbang_station);
        glVertex3f(- ground_size ,0.0, +2*road_size - bangbang_station);
        glVertex3f( ground_size ,0.0, 2*road_size - bangbang_station);
        glVertex3f( ground_size ,0.0, -2*road_size - bangbang_station);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- ground_size ,0.0, -2*road_size - bangbang_station);
        glVertex3f(- ground_size ,0.0, +2*road_size - bangbang_station);
        glVertex3f( ground_size ,0.0, 2*road_size - bangbang_station);
        glVertex3f( ground_size ,0.0, -2*road_size - bangbang_station);
    glEnd();
    // mini st on left bangbang st

    glBegin(GL_POLYGON);
        glVertex3f(- road_size - bangbang_station,0.0, -ground_size);
        glVertex3f(- road_size - bangbang_station,0.0, +bangbang_station);
        glVertex3f( road_size - bangbang_station ,0.0,  + bangbang_station);
        glVertex3f( road_size - bangbang_station,0.0, -ground_size);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- road_size - bangbang_station,0.0, 2.8 * road_size);
        glVertex3f(- road_size - bangbang_station ,0.0,  + 0.0);
        glVertex3f( 1.4*road_size - 2*bangbang_station,0.0, - bangbang_station);
        glVertex3f(- 1.4 * road_size - 2*bangbang_station,0.0, - bangbang_station);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(- road_size + bangbang_station,0.0, -bangbang_station);
        glVertex3f(- road_size + bangbang_station ,0.0, bangbang_station);
        glVertex3f( road_size + bangbang_station,0.0,  bangbang_station);
        glVertex3f(road_size + bangbang_station,0.0, - bangbang_station);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex3f(0.0,0.0, -road_size);
        glVertex3f(0.0 ,0.0, road_size);
        glVertex3f( ground_size,0.0,  road_size);
        glVertex3f(ground_size,0.0, - road_size);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex3f(- road_size + bangbang_station,0.0, -bangbang_station);
        glVertex3f(- road_size + bangbang_station ,0.0, bangbang_station);
        glVertex3f( road_size + bangbang_station,0.0,  bangbang_station);
        glVertex3f(road_size + bangbang_station,0.0, - bangbang_station);
    glEnd();
    //Draw traffic line

    glBegin(GL_POLYGON);
        glColor3f(0.99,0.84,0.39);
        glVertex3f(-line_width ,0.0, -ground_size);
        glVertex3f(-line_width ,0.0, - bangbang_station - road_size *4);
        glVertex3f(line_width ,0.0, - bangbang_station - road_size *4);
        glVertex3f( line_width ,0.0, -ground_size);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.99,0.84,0.39);
        glVertex3f(-line_width ,0.0, - bangbang_station + road_size *4);
        glVertex3f(-line_width ,0.0, bangbang_station - road_size *4);
        glVertex3f(line_width ,0.0,  bangbang_station - road_size *4);
        glVertex3f( line_width ,0.0,  - bangbang_station + road_size *4);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.99,0.84,0.39);
        glVertex3f(-line_width ,0.0, ground_size);
        glVertex3f(-line_width ,0.0, bangbang_station + road_size *4);
        glVertex3f(line_width ,0.0, bangbang_station + road_size *4);
        glVertex3f( line_width ,0.0, ground_size);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0,0.0,- bangbang_station );
        glBegin(GL_POLYGON);
            glVertex3f( road_size * 4 ,0.0, -line_width);
            glVertex3f(road_size * 4 ,0.0, +line_width);
            glVertex3f(ground_size ,0.0, line_width);
            glVertex3f( ground_size ,0.0, -line_width);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(-ground_size ,0.0, -line_width);
            glVertex3f(-ground_size ,0.0, +line_width);
            glVertex3f(-road_size * 4 ,0.0, line_width);
            glVertex3f(-road_size * 4 ,0.0, -line_width);
        glEnd();
    glPopMatrix();


        glPushMatrix();
        glTranslatef(0.0,0.0,+ bangbang_station);
        glBegin(GL_POLYGON);
            glVertex3f( road_size * 4 ,0.0, -line_width);
            glVertex3f(road_size * 4 ,0.0, +line_width);
            glVertex3f(ground_size ,0.0, line_width);
            glVertex3f( ground_size ,0.0, -line_width);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(-ground_size ,0.0, -line_width);
            glVertex3f(-ground_size ,0.0, +line_width);
            glVertex3f(-road_size * 4 ,0.0, line_width);
            glVertex3f(-road_size * 4 ,0.0, -line_width);
        glEnd();
    glPopMatrix();

    glPopMatrix();
}



void DrawTree(int pv, GLfloat x, GLfloat z)
{
    pair<GLfloat, GLfloat> pair_D = Return_point_d(pv);
    GLfloat dxx = pair_D.first;
    GLfloat dzz = pair_D.second;
    glPushMatrix();
        glTranslatef(x +dxx / 5,0.0,z + dzz / 3);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        glRotatef(90.0 ,1.0,0.0,0.0);
        glColor3f(0.99,0.90,0.62);
        gluCylinder(quadratic,25.0,25.0,100.0,32,32);
        glTranslatef(0.0,0.0,-300.0);
        glColor3f(0.0,0.61,0.0);
        gluCylinder(quadratic,10.0,80.0,300.0,32,32);
//            glTranslatef(0.0,0.0,-100.0);
//            glColor3f(0.0,0.81,0.1);
//            gluCylinder(quadratic,40.0,50.0,100.0,32,32);
//            glTranslatef(0.0,0.0,-100.0);
//            glColor3f(0.68,1.0,0.72);
//            gluCylinder(quadratic,20.0,30.0,100.0,32,32);
    glPopMatrix();
}


void Draw_tree_on_st(int pv)
{
//    GLfloat line_width = 20.0;
//    GLfloat line_height = 50.0;
//    glColor3f(0.88,0.88,0.99);
    glPushMatrix();
        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(1000.0 * tmp, 0.0,-1900.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }
        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(-1000.0 * tmp, 0.0,-1900.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }

        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(1000.0 * tmp, 0.0,1700.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }
        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(-1000.0 * tmp, 0.0,1700.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }

        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(1000.0 * tmp, 0.0,-3100.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }
        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(-1000.0 * tmp, 0.0,-3100.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }

        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(1000.0 * tmp, 0.0,2900.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }
        for(int i = 1; i< 10; i++)
        {
            int tmp = i %100;
            glPushMatrix();
                glTranslatef(-1000.0 * tmp, 0.0,2900.0);
                DrawTree(pv,0.0,0.0);
            glPopMatrix();
        }
    glPopMatrix();
//        for(int i = 0; i< 50; i++)
//        {
//            int tmp = i %100;
//            if(i < 100) tmp = -i;
//            glPushMatrix();
//                glRotatef(90.0,0.0,1.0,0.0);
//                glTranslatef(200.0 * tmp, 0.0,0.0);
//                DrawTree(0.0,0.0);
//            glPopMatrix();
//        }
//    glPopMatrix();
}
