//
//		          Programming Assignment #3
//
//				Matthew Erikson
//
// Adapted from pervious assignments
// CPSC4050 - 4/1/20
//
/***************************************************************************/

/* Include needed files */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
using namespace std;

#define WIDTH 800
#define HEIGHT 600

float view_angle_1 = 0;
float view_angle_2 = 0;
float view_angle_3 = 0;

float translate_x = 0;
float translate_y = 0;
float translate_z = 0;

float scale_x = 1;
float scale_y = 1;
float scale_z = 1;

int ortho = 1;
int cube = 1;

int parabola = 1;

int vertexX = 0;
int vertexY = 0;
int pointX = 0;
int pointY = 0;
int checker[1];

int arm_rotate_1 = 0;
int arm_rotate_2 = 0;
int arm_rotate_3 = 0;

int i_num = 0;
int j_num = 0;

void drawPixel(int x, int y);
void drawParabola();

/***************************************************************************/

void initWindow()
/* Clear the image area, and set up the coordinate system */
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
        glOrtho(0,WIDTH,0,HEIGHT,-1.0,1.0);
    	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1);
    	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	
}

void display(void)   // Create The Display Function
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen
	
	if(parabola){ glPushMatrix(); glPushMatrix();
		glMatrixMode(GL_PROJECTION); 
		glLoadIdentity(); //glPopMatrix();
		//glGetIntegerv(GL_MATRIX_MODE, checker); 
		
	}else{  glPushMatrix();
		glMatrixMode(GL_MODELVIEW); 
		glLoadIdentity(); 
		//glGetIntegerv(GL_MATRIX_MODE,checker); 
	}	


	
	//set translations and scale
	glTranslatef(translate_x, translate_y, translate_z);
	glScalef(scale_x, scale_y, scale_z);

	//set orthogonal or perspective
	if(ortho) glOrtho(1, 1, 1, 1, 1, 1);
	else glFrustum(-1, 1, -1, 1, 1.5, 150);

	if(!ortho) gluLookAt(0, 2, -3, 0, 0, 0, 0, 1, 0);

	//set rotations
	glRotatef(view_angle_1, 1, 0, 0);
	glRotatef(view_angle_2, 0, 1, 0);
	glRotatef(view_angle_3, 0, 0, 1);

	//set perspective
	glRotatef(-5, 1, 0, 0);
	glRotatef(50, 0, 1, 0);
	glRotatef(-7, 0, 0, 1);	
	



	
	if(parabola){
	//create the parabola
		drawParabola();
	}else{
	//create the robot
		glColor3f(0.0, 1.0, 1.0);

		//rotate view
		//glRotatef(-20, 0, 0, 1);
		//glRotatef(20, 0, 1, 0);

		//make head of robot
		glPushMatrix();
		glTranslatef(0, .5, 0);
		glutSolidSphere(.25, 10, 10);
		glPopMatrix();


		//make eyes of robot
		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.5, -.1);
		glutSolidSphere(.04, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glTranslatef(0.2, 0.5, 0.1);
		glutSolidSphere(.04, 10, 10);
		glPopMatrix();


		//make body of robot
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(0, 0, 0);
		glutSolidCube(.5);
		glPopMatrix();

		//make arms of robot
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, .25);
		glRotatef(arm_rotate_1, 1, 0, 0);
		glRotatef(arm_rotate_2, 0, 1, 0);
		glRotatef(arm_rotate_3, 0, 0, 1);
		GLUquadricObj * quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.1, 0.1, .5, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, 0, -.75);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.1, 0.1, .5, 32, 32);
		glPopMatrix();

		//make legs of robot
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.25, .125);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.08, 0.08, .5, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glTranslatef(0, -.25, -.125);
		glRotatef(90, 1, 0, 0);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.08, 0.08, .5, 32, 32);
		glPopMatrix();
			

 
	}
	
	glPopMatrix();
	glutSwapBuffers();                                      // Draw Frame Buffer
}


void input_param ()
{
	cout << "Please enter x coordinate for vertex of parabola:" << endl;
	cin >> vertexX;
	cout << "Please enter y coordinate for vertex of parabola:" << endl;
	cin >> vertexY;
	cout << "Please enter x coordinate for the point on the parabola:" << endl;
	cin >> pointX;
	cout << "Please enter y coordinate for the point on the parabola:" << endl;
	cin >> pointY;
	//cout << "Please enter number of i indices:" << endl;
	//cin >> i_num;
	cout << "Please enter number of j indices:" << endl;
	cin >> j_num;

	cout << "drawing parabola with parameters "<< vertexX << ", " <<
	vertexY << ", " << pointX << ", " << pointY << endl;
	//cout << "i indices:" << i_num << endl;
	cout << "j indices:" << j_num << endl;
}

void drawPixel(int x, int y)
{
        glColor3f (1.0, 1.0, 1.0);                 
        glBegin(GL_POINTS);
           glVertex3i( x, y, 0);
        glEnd();
		
}
void drawParabola(){
	
	//glPushMatrix();
	drawPixel(vertexX, vertexY);
	drawPixel(pointX, pointY);
	//int prev_block_x = 0;
	//int prev_block_y = 0;
	//int xxx = 0;
	//int yyy = 0;
	for(int i = 0; i < j_num; i++){
		
		
	glRotatef((360/j_num), 0, 1, 0); 
		
		
	

	int y = 0;
	int xx = 0;
	
	int a = pow((pointY-vertexY),2) / (pointX-vertexX);
	for (int x = 0; x < 800; x++){
	
		y = sqrt(a*(x));
		drawPixel(x + vertexX,y + vertexY);
		drawPixel(x + vertexX,-y + vertexY);
		xx = pow(x,2)/a;
		drawPixel(xx + vertexX,x + vertexY);
		drawPixel(xx + vertexX,-x + vertexY);


		/*if(((x % (800/i_num))== 0) || (x == 0)) { 
		if (x == 50){
			glVertex3f((x-(800/i_num)) + vertexX,sqrt(a*(x-1)) + vertexY, 0);
			glVertex3f(x + vertexX,y + vertexY, 0);	
			glEnd();
			xxx= x;
			yyy=y;
		}		
		
			
 	} */
	
		
	}/*glBegin(GL_POLYGON);
		glVertex3f(xxx + vertexX,yyy + vertexY, 0);	
		glVertex3f((xxx-(800/i_num)) + vertexX,sqrt(a*(xxx-1)) + vertexY, 0);*/
//glPopMatrix();
	}//glEnd();	
}

/***************************************************************************/
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			//initialize all parameters
			view_angle_1 = 0;
			view_angle_2 = 0;
			view_angle_3 = 0;
			ortho = 1;
			scale_x = 1;
			scale_y = 1;
			scale_z = 1;
			translate_x = 0;
			translate_y = 0;
			translate_z = 0;
			arm_rotate_1 = 0;
			arm_rotate_2 = 0;
			arm_rotate_3 = 0;
			break;
		case 'q':              // When q Is Pressed rotate
			view_angle_1--;

			break;
		case 'w':              // When w Is Pressed rotate
			view_angle_2++;

			break;
		case 'e':              // When e Is Pressed rotate
			view_angle_3++;

			break;
		case 'y': 		//toggle perspective
			if(ortho == 0) ortho = 1;
			else ortho = 0;
			break;
		case 'a':
			translate_x-=0.01;
			break;
		case 's':
			translate_x+=0.01;
			break;
		case 'd':
			translate_y+=0.01;
			break;
		case 'f':
			translate_y-=0.01;
			break;
		case 'g':
			translate_z+=0.01;
			break;
		case 'h':
			translate_z-=0.01;
			break;
		case 'z':
			scale_x+=0.05;
			break;
		case 'x':
			scale_y+=0.05;
			break;
		case 'c':
			scale_z+=0.05;
			break;
		case 'b':
			if (parabola) {parabola = 0; }
			else {parabola = 1; input_param(); }
			break;
		case 'u':
			arm_rotate_1+=1;
			break;
		case 'i':
			arm_rotate_2+=1;
			break;
		case 'j':
			arm_rotate_1-=1;
			break;
		case 'k':
			arm_rotate_2-=1;
			break;
		case 'l':
			scale_x+=0.05;
			scale_y+=0.05;
			scale_z+=0.05;
			break;
		case 'o':
			scale_x-=0.05;
			scale_y-=0.05;
			scale_z-=0.05;
			break;
			
			

	     default:
			break;
	}
	glutPostRedisplay();
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
		glutCreateWindow    ( "cg04" );
		glutDisplayFunc     (display);
		glutIdleFunc	    (display);
		glutKeyboardFunc    ( keyboard);
		initWindow();				             //create_window

		glutMainLoop();                 // Initialize The Main Loop


	}
}
