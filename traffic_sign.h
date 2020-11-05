#ifndef TRAFFIC_SIGN_H_INCLUDED
#define TRAFFIC_SIGN_H_INCLUDED

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
#include "basic_setting.h"

using namespace std;

class TrafficSign {
private :
    GLfloat sign_x;
    GLfloat sign_z;
    GLfloat angle;
    int sign;
    int term;
    int counts = 0;
public :
    TrafficSign(GLfloat x, GLfloat z, GLfloat ang ,GLfloat color, int t);
    TrafficSign();
    void SetTFinfo(GLfloat x, GLfloat z, GLfloat ang ,GLfloat color, int t);
    bool Return_sign();
    void DrawTrafficSign(int pv);
    void ChangeSign();

};
#endif // TRAFFIC_SIGN_H_INCLUDED
