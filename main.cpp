//
//		       Final 4050 Programming Project
//
//		Rebecca Edson, Collin Lloyd, Matthew Erikson
//
// Adapted from previous assignments
// CPSC4050 - 4/27/20
//
/***************************************************************************/

/* Include needed files */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fighters.h"
#include "string.h"

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
using namespace std;

#define WIDTH 800
#define HEIGHT 600

int firstFighter = 0;
int secondFighter = 0;

float firstFighterPosition = -2;
float secondFighterPosition = 2;

float firstFighterHealth = 1;
float secondFighterHealth = 1;

int firstWins = 0;
int secondWins = 0;


struct timespec tim; 
struct timespec tim2;


float view_angle_1 = 0; //16
float view_angle_2 = 75; //20
float view_angle_3 = 0;

float translate_x = 0;
float translate_y = 0;
float translate_z = 0;

float scale_x = 1;
float scale_y = 1;
float scale_z = 1;


int cube = 1;

int test1 = 1;
int test2 = 1;
int test3 = 1;
int test4 = 1;
int test5 = 1;
int test6 = 1;

//code for ability movement
float f1_xability = 0;
float f2_xability = 0;
bool abilitypressed = false;
bool abilitypressed2 = false;
bool abhaspress = false;
bool achaspress = false;
/***************************************************************************/
//battleground
void drawBattleground();
void drawHealthbars();
void writeControls();
void f1Ability(int);
void f2Ability(int);


void fighterFunction(int fighter){
	switch(fighter) {
		case 1:
			drawFighterA();
			break;
		case 2:
			drawFighterB();
			break;
		default:
			break;
	}
}

void initWindow()
/* Clear the image area, and set up the coordinate system */
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
        //glOrtho(0,WIDTH,0,HEIGHT,-150,150);

    	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1);
    	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glutSetKeyRepeat(0);
}

void display(void)   // Create The Display Function
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//set translations and scale
	glTranslatef(translate_x, translate_y, translate_z);
	glScalef(scale_x, scale_y, scale_z);

	glOrtho(1, 1, 1, 1, 1, 1);
	glEnable(GL_DEPTH_CLAMP);
	glEnable(GL_DEPTH_TEST);

	//draw controls
	writeControls();	

	//draw battleground
	drawBattleground();

	//set rotations
	glRotatef(view_angle_1, 1, 0, 0);
	glRotatef(view_angle_2, 0, 1, 0);
	glRotatef(view_angle_3, 0, 0, 1);


	//draw first fighter
	glPushMatrix();
	glTranslatef(firstFighterPosition, 0, 0);
	//glRotatef(130, 0, 1, 0);
	fighterFunction(firstFighter);
	if (abilitypressed) {
		glPushMatrix();
		glColor3f(1, 0.0, 0.0);
		glTranslatef(f1_xability, 0, 0.09);
		glutSolidCube(.05);
		glPopMatrix();

		if (f1_xability > (secondFighterPosition - firstFighterPosition)){
			secondFighterHealth -= 0.10;
			abilitypressed = false;
			abhaspress = false;
			
		}

		if (!abhaspress) {
			glutTimerFunc(0, f1Ability, 0);
		}
	} else {
		f1_xability = 0;
	}
	glPopMatrix();


	//draw second fighter
	glPushMatrix();
	glTranslatef(secondFighterPosition, 0, 0);
	glRotatef(210, 0, 1, 0);
	fighterFunction(secondFighter);
	if (abilitypressed2) {
		glPushMatrix();
		glColor3f(0, 1.0, 1.0);
		glTranslatef(f2_xability, 0, 0.09);
		glRotatef(-90, 0, 1, 0);
		glutSolidTeapot(.05);
		glPopMatrix();

		if (f2_xability < (firstFighterPosition - secondFighterPosition)){
			firstFighterHealth -= 0.10;
			abilitypressed2 = false;
			achaspress = false;
			
		}

		if (!achaspress) {
			glutTimerFunc(0, f2Ability, 0);
		}
	} else {
		f2_xability = 0;
	}

	
	glPopMatrix();
	glPopMatrix();
	//draw healthbars
	drawHealthbars();
	
	if(firstWins){
		cout << "FIRST FIGHTER WINS!" << endl;
		cout << "Window closing in 8 seconds." << endl;
		nanosleep(&tim, &tim2);
		exit(1);
	}

	if(secondWins){
		cout << "SECOND FIGHTER WINS!" << endl;
		cout << "Window closing in 8 seconds." << endl;
		nanosleep(&tim, &tim2);
		exit(1);
	}


	//0 hp
	tim.tv_sec = 8; 

	if (firstFighterHealth <= 0.1){
	glPushMatrix();
	glColor3f(0, 0, 0);
	//glutSolidCube(2);
	//glColor3f(1, 0, 0); 
	glTranslatef(0, 0, -1);
	
	glutSolidCube(2);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 0, -2);

	glRotatef(75, 0, 1, 0);
	fighterFunction(secondFighter);
	glPopMatrix();

	glPushMatrix();

	for(int i = 0; i < 5; i++){
		glPushMatrix();
		glColor3f(1, 1, 0);
		glTranslatef(0.0,0.0,-3);
		glRotatef((i * 72), 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(0.06, 0.40, 0); 
		glVertex3f(0.40, 0.06, 0); 
		glVertex3f(0.15, 0.15, 0); 
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(0.13, 0.80, 0); 
		glVertex3f(0.80, 0.13, 0); 
		glVertex3f(0.30, 0.30, 0); 
		glEnd();
	
		glBegin(GL_POLYGON);
		glVertex3f(0.19, 1.2, 0); 
		glVertex3f(1.2, 0.19, 0); 
		glVertex3f(0.50, 0.50, 0); 
		glEnd();


		glPopMatrix();
	}
	

	glPopMatrix();
	secondWins = 1;
	}


	
	if (secondFighterHealth <= 0.1){
	glPushMatrix();
	glColor3f(0, 0, 0);
	//glutSolidCube(2);
	//glColor3f(1, 0, 0); 
	glTranslatef(0, 0, -1);
	
	glutSolidCube(2);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 0, -2);

	glRotatef(75, 0, 1, 0);
	fighterFunction(firstFighter);
	glPopMatrix();

	glPushMatrix();

	for(int i = 0; i < 5; i++){
		glPushMatrix();
		glColor3f(1, 1, 0);
		glTranslatef(0.0,0.0,-3);
		glRotatef((i * 72), 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(0.06, 0.40, 0); 
		glVertex3f(0.40, 0.06, 0); 
		glVertex3f(0.15, 0.15, 0); 
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(0.13, 0.80, 0); 
		glVertex3f(0.80, 0.13, 0); 
		glVertex3f(0.30, 0.30, 0); 
		glEnd();
	
		glBegin(GL_POLYGON);
		glVertex3f(0.19, 1.2, 0); 
		glVertex3f(1.2, 0.19, 0); 
		glVertex3f(0.50, 0.50, 0); 
		glEnd();


		glPopMatrix();
	}
	

	glPopMatrix();
	firstWins = 1;
	}
	
	


	glPopMatrix();
	glutSwapBuffers();                                      // Draw Frame Buffer
}

void drawBattleground()
{
	glPushMatrix();
	glColor3f(0.25, 0.0, 0.25);
	glTranslatef(0, -1.18, 0);
	glutSolidCube(2);
	glPopMatrix();
}

void drawHealthbars()
{
	//fighter 1
	glPushMatrix();
	glTranslatef(-0.95, 0.82, 0);
	glColor3f(0.0, 1.0, 1.0);
	glRectf(0, 0, 0.7, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(0, 0, (0.7*firstFighterHealth), 0.1);

	glPopMatrix();

	//fighter 2
	glPushMatrix();
	glTranslatef(0.25, 0.82, 0);
	glColor3f(0.0, 1.0, 1.0);
	glRectf(0, 0, 0.7, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(0, 0, (0.7*secondFighterHealth), 0.1);
	glPopMatrix();
}

void writeControls()
{
//
}


void input_param ()
{
	cout << "Please enter first fighter:" << endl;
	cout << "1 - Fighter A" << endl;
	cout << "2 - Fighter B" << endl;
	cin >> firstFighter;

	cout << "Please enter second fighter:" << endl;
	cout << "1 - Fighter A" << endl;
	cout << "2 - Fighter B" << endl;
	cin >> secondFighter;
}


/***************************************************************************/
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			//initialize all parameters
			//view_angle_1 = 0;
			//view_angle_2 = 0;
			//view_angle_3 = 0;
			//scale_x = 1;
			//scale_y = 1;
			//scale_z = 1;
			//translate_x = 0;
			//translate_y = 0;
			//translate_z = 0;
			break;
		case 'q':              // Move first fighter left
			firstFighterPosition-=0.07;

			break;
		case 'w':              // Move first fighter right
			firstFighterPosition+=0.07;

			break;
		case 'o':              // Move second fighter left
			secondFighterPosition-=0.07;

			break;
		case 'p':              // Move second fighter right
			secondFighterPosition+=0.07;

			break;
		case 'd':
			abilitypressed = true;

			break;
		case 'j':
			abilitypressed2 = true;
			break;
	     default:
			break;
	}
	glutPostRedisplay();
}

void f1Ability(int) {

		if (f1_xability >= 3) {
			abilitypressed = false;
			abhaspress = false;
		}
		else {
			abhaspress = true;
			f1_xability += 0.015;
		}

		glutPostRedisplay();
		glutTimerFunc(1000/60, f1Ability, 0);

		/*f1_xability += 0.015;
		if (f1_xability >= 3) {
			f1_xability = 0;
			abilitypressed = false;
			abhaspress = false;
		}

		if(!abhaspress) {
			f1_xability = 0;
		}*/

}

void f2Ability(int) {

		if (f2_xability <= -3) {
			abilitypressed2 = false;
			achaspress = false;
		}
		else {
			achaspress = true;
			f2_xability -= 0.015;
		}

		glutPostRedisplay();
		glutTimerFunc(1000/60, f2Ability, 0);
}


int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */

	{


		input_param();
		glutInit            ( &argc, argv );
		glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
		glutInitWindowSize  ( WIDTH,HEIGHT );
		glutCreateWindow    ( "Final Proj" );
		glutDisplayFunc     (display);
		glutIdleFunc	    (display);
		glutKeyboardFunc    ( keyboard);
		initWindow();				             //create_window

		glutMainLoop();                 // Initialize The Main Loop


	}
}
