#include "fighters.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void drawFighterA() //name: ????
	{
		//head
		glPushMatrix();
		glColor3f(0.0, 1.0, 1.0);
		glTranslatef(0, .125, 0);
		glutSolidSphere(.05, 10, 10);
		glPopMatrix();

		/*//eyes
		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(-0.05, 0.1, 0);
		glutSolidSphere(.02, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.1, 0);
		glutSolidSphere(.02, 10, 10);
		glPopMatrix();*/


		//body
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(0, 0, 0);
		glutSolidCube(.125);
		glPopMatrix();

		//arms 
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.08);
		GLUquadricObj * quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.025, 0.025, .08, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, -.15);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.025, 0.025, .08, 32, 32);
		glPopMatrix();

		//legs
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.05, .042);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.02, 0.02, .125, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.05, -.042);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.02, 0.02, .125, 32, 32);
		glPopMatrix();
}

void drawFighterB() //name: ????
	{
		//head
		glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);
		glTranslatef(0, .125, 0);
		glutSolidSphere(.05, 10, 10);
		glPopMatrix();

		/*//eyes
		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(-0.05, 0.1, 0);
		glutSolidSphere(.02, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.1, 0);
		glutSolidSphere(.02, 10, 10);
		glPopMatrix();*/


		//body
		glPushMatrix();
		glColor3f(0.25, 0.0, 0.25);
		glTranslatef(0, 0, 0);
		glutSolidCube(.125);
		glPopMatrix();

		//arms
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.08);
		GLUquadricObj * quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.025, 0.025, .08, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, -.15);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.025, 0.025, .08, 32, 32);
		glPopMatrix();

		//legs
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.05, .042);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.02, 0.02, .125, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.05, -.042);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.02, 0.02, .125, 32, 32);
		glPopMatrix();
}







