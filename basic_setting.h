#ifndef BASIC_SETTING_H_INCLUDED
#define BASIC_SETTING_H_INCLUDED

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

void Draw_line();

static GLfloat dx[3] = {0.0 , -800.0, 100.0};
static GLfloat dz[3] = {0.0, -200.0, 0.0};

pair<GLfloat, GLfloat> Return_point_d(int point_of_view);
#endif // BASIC_SETTING_H_INCLUDED
