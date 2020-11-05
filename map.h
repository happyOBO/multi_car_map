#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include "basic_setting.h"
using namespace std;

void DrawGround();
void DrawTree(int pv, GLfloat x, GLfloat z);
void Draw_tree_on_st(int pv);

#endif // MAP_H_INCLUDED
