
#include "car.h"
#include "basic_setting.h"
#include "map.h"
using namespace std;

Car car_arr[10];
int car_counts = 9;
void Draw_Wallpaper()
{

}
void Idlefunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glRotatef(40.0,1.0,0.0,0.0);
        glRotatef(10.0,0.0,1.0,0.0);
        DrawGround();
        Draw_line();
        for(int i = 0; i < car_counts; i++)
        {
            car_arr[i].Draw_Car();
            car_arr[i].AutoMove();

        }
    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car Simulation");

    car_arr[0].SetCarInfo(200.0,7500.0,90.0);
    car_arr[1].SetCarInfo(400.0,5000.0,90.0);

    car_arr[6].SetCarInfo(-200.0,-4500.0,270.0);
    car_arr[7].SetCarInfo(-400.0,-6010.0,270.0);

    car_arr[2].SetCarInfo(-4500.0,-2100.0,0.0);
    car_arr[3].SetCarInfo(-13500.0,-2300.0,0.0);

    car_arr[4].SetCarInfo(15500.0,-2800.0,180.0);
    car_arr[5].SetCarInfo(4400.0,-2600.0,180.0);

    car_arr[6].SetCarInfo(15500.0,2200.0,180.0);
    car_arr[7].SetCarInfo(4500.0,2200.0,180.0);
    car_arr[8].SetCarInfo(10500.0,2000.0,180.0);

    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5000.0,5000.0,-3000.0,3000.0,-5000.0,5000.0);
    glutDisplayFunc(Draw_Wallpaper);
    glutIdleFunc(Idlefunc);
    glutMainLoop();
    return 0;
}
