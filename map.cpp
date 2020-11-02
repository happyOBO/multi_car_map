#include "map.h"



void DrawGround()
{
    GLfloat ground_size = 10000.0;
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
