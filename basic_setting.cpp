#include "basic_setting.h"

//dx[0] = 0.0;
//dx[1] = - 1000.0;
//dz[2] = 100.0;

void Draw_line()
{
    //x axis : red, y axis : green, z axis : blue
    //glMatrixMode(GL_MODELVIEW);
    GLfloat line_width = 20.0;
    GLfloat line_height = 50.0;
//    glColor3f(0.88,0.88,0.99);
//    glPushMatrix();
//        for(int i = 0; i< 200; i++)
//        {
//            int tmp = i %100;
//            if(i < 100) tmp = -i;
//            glPushMatrix();
//                glTranslatef(200.0 * tmp, 0.0,0.0);
//                glBegin(GL_POLYGON);
//                    glVertex3f(-line_height ,0.0, -line_width);
//                    glVertex3f(-line_height ,0.0, +line_width);
//                    glVertex3f(line_height ,0.0, line_width);
//                    glVertex3f( line_height ,0.0, -line_width);
//                glEnd();
//            glPopMatrix();
//        }
//        for(int i = 0; i< 200; i++)
//        {
//            int tmp = i %100;
//            if(i < 100) tmp = -i;
//            glPushMatrix();
//                glRotatef(90.0,0.0,1.0,0.0);
//                glTranslatef(200.0 * tmp, 0.0,0.0);
//                glBegin(GL_POLYGON);
//                    glVertex3f(-line_height ,0.0, -line_width);
//                    glVertex3f(-line_height ,0.0, +line_width);
//                    glVertex3f(line_height ,0.0, line_width);
//                    glVertex3f( line_height ,0.0, -line_width);
//                glEnd();
//            glPopMatrix();
//        }
//    glPopMatrix();
}


pair<GLfloat, GLfloat> Return_point_d(int point_of_view)
{

    return make_pair(dx[point_of_view], dz[point_of_view]);
}
