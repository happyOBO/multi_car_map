
#include "car.h"
#include "basic_setting.h"
#include "map.h"
#include "user_car.h"
#include "traffic_sign.h"
using namespace std;


const double PI = 3.14159;
Car car_arr[10];
TrafficSign tf_arr[10];
GLfloat timer1 = 600.0;
GLfloat timer2 = 800.0;
GLfloat tf_idx[10][5] = {{750.0,-1600.0,270.0, 0.0, timer1} , {750.0, -3200.0,0.0,1.0, timer1 }, {-750.0,-3200.0, 90.0, 0.0,timer1} ,
{-750.0,-1600.0, 180.0, 1.0, timer1} , {750.0,3200.0,270.0, 1.0, timer2} , {750.0,1600.0,0.0,0.0,timer2}, {-750.0, 1600.0, 90.0, 1.0, timer2} ,
{-750.0, 3200.0, 180.0, 0.0, timer2}};
GLfloat start_point[2] = {300.0,3500.0};
GLfloat end_point[2] = {5000.0, -2200.0};
UserCar MyCar(start_point[0],start_point[1],90.0);
int score = 1000;
int car_counts = 9;

int point_of_view = 0; // 0 : map , 1 : 3 point , 2 : 1 point

void Draw_Wallpaper()
{

}

void DrawPoint()
{
    glPushMatrix();
        glColor3f(0.35, 0.79,0.99);
        glTranslatef(start_point[0],0.0,start_point[1]);
        glutSolidCube(100);
    glPopMatrix();

    glPushMatrix();
//        glColor3f();
        glTranslatef(end_point[0],0.0,end_point[1]);
        glutSolidCube(100);
    glPopMatrix();
}

void Idlefunc()
{

    pair<GLfloat,GLfloat> Myloc = MyCar.Return_loc();
    GLfloat My_x_location = Myloc.first;
    GLfloat My_z_location = Myloc.second;
    GLfloat My_ang = MyCar.Return_angle();
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        if(point_of_view == 1)
        {
            gluLookAt(My_x_location + 50, 30.0, My_z_location + 50, My_x_location, 0.0, My_z_location, 0.0, 1.0, 0.0 );
        }
//        else if(point_of_view == 2)
//        {
//            gluLookAt(My_x_location+ 50*cos(-PI/180 *My_ang)  , 0.0, My_z_location + 50*sin(-PI/180 *My_ang), My_x_location + 100*cos(-PI/180 *My_ang), 0.0, My_z_location + 100*sin(-PI/180 *My_ang), 0.0, 0.0, 1.0 );
//        }
        else if(point_of_view == 0)
        {
//            gluLookAt(100, 4500.0, 500,0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
//            glScalef(0.7,1.0,0.7);

            glRotatef(40.0,1.0,0.0,0.0);
            glRotatef(10.0,0.0,1.0,0.0);
        }
        DrawGround();
        Draw_line();
        DrawPoint();

        MyCar.Draw_Car();
        if((-100 < (My_x_location - end_point[0]) && (My_x_location - end_point[0]) < 100 && -100 <(My_z_location - end_point[1]) && (My_z_location - end_point[1]) < 100))
        {
            cout<<score<<" / 1000"<<endl;
            exit(1);
        }

        for(int j = 0; j<8; j++)
        {
            if( ((tf_idx[j][2] - My_ang ) == 180.0 || (tf_idx[j][2] - My_ang ) == -180.0) && tf_arr[j].Return_sign())
            {
                // calc term , stop sign
                if (( !(-750 < My_x_location && My_x_location < 750 && -3200 < My_z_location && My_z_location < -1600) && !(-750 < My_x_location && My_x_location < 750 && 1600 <My_z_location && My_z_location < 3200)))
                {
                    if( -1000 <= (tf_idx[j][0] - My_x_location) && (tf_idx[j][0] - My_x_location) <= 1000 && -1000 <= (tf_idx[j][1] - My_z_location) && (tf_idx[j][1] - My_z_location) <= 1000)
                        if(!MyCar.is_Stop()) score -= 1;
//                        cout<<score<<endl;

                }

            }

        }


        for(int i = 0; i < car_counts; i++)
        {
            pair<GLfloat,GLfloat> loc = car_arr[i].Return_loc();
            GLfloat x_location = loc.first;
            GLfloat z_location = loc.second;
            GLfloat ang = car_arr[i].Return_angle();

            // check score

            if((-50 < (x_location - My_x_location) && (x_location - My_x_location) < 50 && -50 <(z_location - My_z_location) && (z_location - My_z_location) < 50))
            {
                score -= 1;
            }

            bool stp = false;
            for(int j = 0; j<8; j++)
            {
                if( ((tf_idx[j][2] - ang ) == 180.0 || (tf_idx[j][2] - ang ) == -180.0) && tf_arr[j].Return_sign())
                {
                    // calc term , stop sign
                    if (( !(-750 < x_location && x_location < 750 && -3200 < z_location && z_location < -1600) && !(-750 < x_location && x_location < 750 && 1600 <z_location && z_location < 3200)))
                    {
                        if( -1000 <= (tf_idx[j][0] - x_location) && (tf_idx[j][0] - x_location) <= 1000 && -1000 <= (tf_idx[j][1] - z_location) && (tf_idx[j][1] - z_location) <= 1000)
                            stp =true;
                    }

                }

            }
            car_arr[i].Draw_Car(stp);
            car_arr[i].AutoMove();

        }
        for(int i = 0; i<8; i++)
        {
            tf_arr[i].DrawTrafficSign(point_of_view);
        }
        Draw_tree_on_st(point_of_view);


    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int p, int k) {
 switch (key) {
 case 'd':
         MyCar.Rotate(true);
//         MyCar.Control_velocity(true);
//        MyCar.move_car(0.0,1.0);
    break;
 case 'a':
         MyCar.Rotate(false);
//         MyCar.Control_velocity(true);
//        MyCar.move_car(0.0,-1.0);
    break;
 case 'w':
         MyCar.Control_velocity(true);
////        MyCar.move_car(1.0,0.0);
    break;
 case 's':
         MyCar.Control_velocity(false);
//        MyCar.move_car(-1.0,0.0);
     break;
 case 'p':
        if(point_of_view == 1)
        {
            point_of_view = 0;
        }
        else
            point_of_view += 1;
     break;
 case 32 :

    break;
 default:
     break;

 }
 glutPostRedisplay();
}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car Simulation");

    car_arr[0].SetCarInfo(-200.0,-7500.0,270.0);
    car_arr[1].SetCarInfo(-400.0,-5000.0,170.0);

    car_arr[6].SetCarInfo(-200.0,-4500.0,270.0);
    car_arr[7].SetCarInfo(-400.0,-6010.0,270.0);

    car_arr[2].SetCarInfo(-4500.0,-2100.0,0.0);
    car_arr[3].SetCarInfo(-7500.0,-2300.0,0.0);

    car_arr[4].SetCarInfo(7500.0,-2800.0,180.0);
    car_arr[5].SetCarInfo(4400.0,-2600.0,180.0);

    car_arr[6].SetCarInfo(5550.0,2200.0,180.0);
    car_arr[7].SetCarInfo(4500.0,2000.0,180.0);

    car_arr[8].SetCarInfo(-4050.0,2700.0,0.0);

    for (int i = 0; i<8 ; i++)
    {
        tf_arr[i].SetTFinfo(tf_idx[i][0],tf_idx[i][1],int(tf_idx[i][2]),tf_idx[i][3],int(tf_idx[i][4]));
    }
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5000.0,5000.0,-3000.0,3000.0,-5000.0,5000.0);
    glutDisplayFunc(Draw_Wallpaper);
    glutIdleFunc(Idlefunc);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
