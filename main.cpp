#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
using namespace std;

float moveTank = 0.10f;
float cloudSpeed = -1.2f, cloudSpeed1 = 1.2f;
float tankPosition = -1.2f, tankPosition1 = -1.2f;
int score = 0, Total_Score = 0;
float scale1 = -0.6, scale2 = -0.6, scale3 = -0.6, scale4 = -0.6;
float transAirPlane1 = -0.80f, transAirPlane2 = -0.30f, transAirPlane3 = 0.20f, transAirPlane4 = 0.65f;
float positionOfPlane1 = 0.002f, positionOfPlane2 = 0.002f, positionOfPlane3 = 0.002f, positionOfPlane4 = 0.002f;
float transPoints1 = -3.0f, transPoints2 = -2.5f, transPoints3 = -1.7f, transPoints4 = -1.0f;
float PointsPos1 = -0.80f, PointsPos2 = -0.30f, PointsPos3 = 0.20f, PointsPos4 = 0.750f;
float transBomb1 = -1.1f, transBomb2 = -1.6f, transBomb3 = -2.30f, transBomb4 = -3.0f;
float BombPos1 = -0.80f, BombPos2 = -0.30f, BombPos3 = 0.20f, BombPos4 = 0.75f;
char gameMode = 'r';
int timer = 15;

void printS(char *string, float x, float y)
{
	glColor3f(1.0, 1.0, 1.0);
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void Menu()
{
	glPushMatrix();

	glColor3ub(59, 118, 41);

	glPushMatrix();
	glColor3f(0.000, 0.749,1.000);
	glTranslatef(0, 0.6, 0);
	glScalef(3, 0.9, 0);
	glutSolidCube(0.2);
	glPopMatrix();

	glColor3f(0, 0.3, 0.2);
	glPushMatrix();
	glTranslatef(0, 0.2, 0);
	glScalef(2, 0.9, 0);
	glutSolidCube(0.2);
	glPopMatrix();

	glColor3f(1.000, 0.271,0.000);
	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	glScalef(2, 0.8, 1);
	glutSolidCube(0.2);
	glPopMatrix();



	glPopMatrix();

	glColor3f(1, 0, 0);
	// printS("Surviving Game ", (-100/600.00), (240/400.00));
	printS("Surviving Game ", -0.167, 0.6);

	glColor3f(0, 0.8, 0.5);
	//printS("START GAME", (-100/600.00), (70/400.00));
	printS("START GAME", -0.167, .20);
	printS("QUIT", (-40.00 / 600.00), -0.20);

	glutSwapBuffers();

}



void ScoreMenu()
{

	glPushMatrix();

	glPushMatrix();
	glColor3f(1.000, 0.078,0.576);
	glTranslatef(0, 0.6, 0);
	glScalef(3, 0.9, 0);
	glutSolidCube(0.2);
	glPopMatrix();

	glColor3f(1.000, 0.271,0.000);
	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	glScalef(2, 0.8, 1);
	glutSolidCube(0.2);
	glPopMatrix();

	glPopMatrix();

	glColor3f(1, 0, 0);
	stringstream ss;
    ss << Total_Score;
    string str = ss.str();
	string point = " Total Score  : " + str;
	int n = point.length();
    char char_array[n+1];
    strcpy(char_array, point.c_str());

	printS(char_array, -0.167, 0.6);
	glColor3f(0, 0.8, 0.5);
	printS("QUIT", (-40.00 / 600.00), -0.20);
	glutSwapBuffers();

}




void initRendering()
{
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.7, 1.50, 1);
    glMatrixMode(GL_MODELVIEW);
//    glEnable(GL_LIGHTING); //Enable lighting
//	glEnable(GL_LIGHT0); //Enable light #0
//    glEnable(GL_COLOR_MATERIAL);   //lets us use the glcolor3f.
//
//
//    glEnable(GL_LIGHT1); //Enable lighting
//    glEnable(GL_NORMALIZE); //Automatically normalize normals
//    glShadeModel(GL_SMOOTH); //Enable smooth shading


}
void disableRendering()
{
	glDisable(GL_DEPTH_TEST);
}


void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(0.0, w / h, 1.0, 200.0);

}


void drawScore(void * font, char *s, int point, float x, float y)
{
	glRasterPos2f(x, y);
	glColor3f(0.000, 1.000, 1.000);

	for (int i = 0; i < strlen(s); i++)
		glutBitmapCharacter(font, s[i]);
	int temp = point;
	int countArr = 0;
	int pointArr[5];
	while (temp > 9)
	{
		pointArr[countArr] = temp % 10;
		temp /= 10;
		countArr++;
	}
	pointArr[countArr] = temp % 10;
	countArr++;
	for (int i = countArr; i >= 0; i--)
	{
		glutBitmapCharacter(font, 48 + (pointArr[i]));
	}
}

void drawTotalScore(void * font, char *s, int point, float x, float y)
{
	glRasterPos2f(x, y);
	glColor3f(1.0, 1.0, 1.0);

	for (int i = 0; i < strlen(s); i++)
		glutBitmapCharacter(font, s[i]);
	int temp = point;
	int countArr = 0;
	int pointArr[5];
	while (temp > 9)
	{
		pointArr[countArr] = temp % 10;
		temp /= 10;
		countArr++;
	}
	pointArr[countArr] = temp % 10;
	countArr++;
	for (int i = countArr; i >= 0; i--)
	{
		glutBitmapCharacter(font, 48 + (pointArr[i]));
	}
}

void cloud()
{
	///right cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(cloudSpeed, 0.875, 0.35);
	glutSolidSphere(.06, 50, 50);
	glPopMatrix();

	///bottom cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(0.08 + cloudSpeed, 0.850, 0.35);
	glutSolidSphere(.07, 50, 50);
	glPopMatrix();


	///above cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(0.08 + cloudSpeed, 0.90, 0.35);
	glutSolidSphere(.07, 50, 50);
	glPopMatrix();

	///left cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(0.15 + cloudSpeed, 0.85, 0.35);
	glutSolidSphere(0.06, 50, 50);
	glPopMatrix();


	///********

	///right cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(cloudSpeed1, 0.575, 0.35);
	glutSolidSphere(.06, 20, 50);
	glPopMatrix();

	///bottom cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(cloudSpeed1 - 0.08, 0.550, 0.35);
	glutSolidSphere(.07, 50, 50);
	glPopMatrix();

	///above cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(cloudSpeed1 - 0.08, 0.60, 0.35);
	glutSolidSphere(.09, 50, 50);
	glPopMatrix();

	///left cloud
	glPushMatrix();
	glColor3f(.90, .90, .90);
	glTranslatef(cloudSpeed1 - 0.15, 0.55, 0.35);
	glutSolidSphere(0.09, 50, 50);
	glPopMatrix();


}

///war zone
void field()
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.914, 0.588, 0.478);
	glVertex3f(-1.0, -0.72, 0.90);
	glColor3f(0.133, 0.545, 0.133);
	glVertex3f(1.0, -0.72, 0.90);
	glColor3f(0.914, 0.588, 0.478);
	glVertex3f(1.0, 0.3, 0.90);
	glColor3f(0.133, 0.545, 0.133);
	glVertex3f(-1.0, 0.3, 0.90);
	glPopMatrix();
	glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i, lineAmount = 100;
	GLfloat twicePi = 2.0f * 3.14159265358979323846;

	glBegin(GL_POLYGON);
	glColor3f(0.824, 0.706, 0.549);
	for (i = 0; i <= lineAmount; i++)
	{
		glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)), y + (radius* sin(i * twicePi / lineAmount)));
	}
	glEnd();
}


void tank(float X, float Y, float Z)
{
	glTranslatef(X, Y - .25, Z);
	glScalef(0.5, 0.5, 0.0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1.000, 0.871, 0.678);
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.4f, 0.1f);
	glVertex2f(-0.2f, 0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.871, 0.678);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(0.25f, 0.1f);
	glVertex2f(0.15f, 0.2f);
	glVertex2f(-0.05f, 0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.871, 0.678);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(0.25f, 0.1f);
	glVertex2f(0.15f, 0.2f);
	glVertex2f(-0.05f, 0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.000, 0.973, 0.863);
	glVertex2f(0.15f, 0.125f);
	glVertex2f(0.35f, 0.125f);
	glVertex2f(0.35f, 0.170f);
	glVertex2f(0.15f, 0.170f);
	glEnd();

	drawCircle(-0.1, 0, 0.05);
	drawCircle(0, 0, 0.05);
	drawCircle(0.1, 0, 0.05);
	drawCircle(0.2, 0, 0.05);
	drawCircle(0.3, 0, 0.05);

	glPopMatrix();

}

void tree(float X, float Y, float Z)
{

	glPushMatrix();
	glColor3f(0.000, 0.392, 0.000);
	glTranslatef(X, Y + .1, Z);
	glScalef(0.25, 0.3, 0.0);
	glRotatef(-70, 1.0, 0.0, 0.0);
	glutSolidCone(.28, .95, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(X, Y, Z);
	glScalef(0.32, 0.3, 0.0);
	glRotatef(-70, 1.0, 0.0, 0.0);
	glutSolidCone(.28, .95, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(X, Y - 0.1, Z);
	glScalef(0.35, 0.3, 0.0);
	glRotatef(-70, 1.0, 0.0, 0.0);
	glutSolidCone(.33, .95, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.502, 0.000, 0.000);
	glTranslatef(X - 0.255, Y - 0.50, Z);
	glBegin(GL_POLYGON);
	glVertex3f(0.20, 0.1, 0.0);
	glVertex3f(0.30, 0.1, 0.0);
	glVertex3f(0.27, 0.80, 0.0);
	glVertex3f(0.24, 0.80, 0.0);
	glVertex3f(0.25, 0.65, 0.0);
	glVertex3f(0.26, 0.65, 0.0);
	glPopMatrix();
	glEnd();

}

void road()
{
	///Main road width

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-1.0, -0.78, 0.55);
	glVertex3f(1.0, -0.78, 0.55);
	glVertex3f(1.0, -1, 0.55);
	glVertex3f(-1.0, -1, 0.55);
	glPopMatrix();
	glEnd();

	///road top barder
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(-1.0, -0.78, 0.55);
	glVertex3f(1.0, -0.78, 0.55);
	glVertex3f(1.0, -0.72, 0.55);
	glVertex3f(-1.0, -0.72, 0.55);
	glEnd();
	glPopMatrix();

	///white line
	///Road side Upper border
	glPushMatrix();
	glLineWidth(1);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, -0.78, 0.54);
	glVertex3f(1.0, -0.78, 0.54);
	glEnd();
	glPopMatrix();


	///another white line
	///Road side bottom border
	glPushMatrix();
	glLineWidth(1);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, -0.99, 0.54);
	glVertex3f(1.0, -0.99, 0.54);
	glEnd();
	glPopMatrix();

	///Highway Road middle divider

	glPushMatrix();
	for (int len = 0; len < 20; len++)
	{
		glLineWidth(3);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(-1.0 + (len* 0.1f), -0.90, 0.50); // -0.90 can be -0.89
		glVertex3f(-0.94 + (len* 0.1f), -0.90, 0.50); // -0.90 can be -0.89
		glEnd();
	}
	glPopMatrix();

	glEnd();

}

void sun()
{

	GLfloat x = 0.050f;
	GLfloat y = 0.38f;
	GLfloat radius = 0.1f;
	glPushMatrix();
	int i, lineAmount = 100;
	GLfloat twicePi = 2.0f * 3.14159265358979323846;
	glBegin(GL_POLYGON);
	glColor3f(1.000, 0.271, 0.000);
	for (i = 0; i <= lineAmount; i++)
	{
		glVertex3f(x + (radius * cos(i *  twicePi / lineAmount)), y + (radius* sin(i * twicePi / lineAmount)), 0.0);
	}
	glEnd();
	glPopMatrix();

}


void AirPlane(float z)
{

	glPushMatrix();

	glColor3f(0.400, 0.804, 0.667);
	glBegin(GL_QUADS);
	glVertex3f(-0.27f, 0.0f, z);
	glVertex3f(0.27f, 0.0f, z);
	glVertex3f(0.27f, 0.1f, z);
	glVertex3f(-0.27f, 0.1f, z);
	glEnd();

	glColor3f(0.498, 1.000, 0.831);
	glBegin(GL_QUADS);
	glVertex3f(-0.30f, 0.0f, z);
	glVertex3f(-0.27f, 0.0f, z);
	glVertex3f(-0.27f, 0.1f, z);
	glVertex3f(-0.30f, 0.1f, z);
	glEnd();

	glColor3f(1.000, 0.855, 0.725);
	glBegin(GL_LINES);
	glLineWidth(5);
	glVertex3f(0.3, 0.005, z);
	glVertex3f(0.35, 0.005, z);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5);
	glVertex3f(0.3, 0.025, z);
	glVertex3f(0.35, 0.025, z);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5);
	glVertex3f(0.3, 0.045, z);
	glVertex3f(0.35, 0.045, z);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5);
	glVertex3f(0.3, 0.065, z);
	glVertex3f(0.35, 0.065, z);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(5);
	glVertex3f(0.3, 0.085, z);
	glVertex3f(0.35, 0.085, z);
	glEnd();

	glColor3f(1.0, 0.0, 0.000);
	glBegin(GL_QUADS);
	glVertex3f(0.30f, 0.0f, z);
	glVertex3f(0.27f, 0.0f, z);
	glVertex3f(0.27f, 0.1f, z);
	glVertex3f(0.30f, 0.1f, z);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glLineWidth(10);
	glVertex3f(-0.27, 0.05, z);
	glVertex3f(-0.4, 0.05, z);
	glEnd();

	glColor3f(0.663, 0.663, 0.663);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.25f, 0.1f, z);
	glVertex3f(-0.15f, 0.1f, z);
	glVertex3f(-0.15f, 0.15f, z);
	glEnd();


	glColor3f(0.863, 0.863, 0.863);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.15f, 0.15f, z);
	glVertex3f(-0.15f, 0.1f, z);
	glVertex3f(0.050f, 0.1f, z);
	glEnd();


	glColor3f(0.000, 0.000, 0.545);
	glBegin(GL_QUADS);
	glVertex3f(0.30f, 0.1f, z);
	glVertex3f(0.20f, 0.1f, z);
	glVertex3f(0.25f, 0.2f, z);
	glVertex3f(0.30f, 0.2f, z);
	glEnd();

	glPopMatrix();




}



void survivingObject()
{

	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	drawCircle(-0.090, -0.85f, .02);
	drawCircle(-0.05, -0.85f, .02);
    drawCircle(0, -0.85f, .02);
    drawCircle(0.05, -0.85f, .02);
    drawCircle(0.090, -0.85f,0.02);


	glColor3f(	0.251, 0.878, 0.816);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1f, -0.85f, 0.0f);
	glVertex3f(0.1f, -0.85f, 0.0f);
	glVertex3f(0.1f, -0.75f, 0.0f);
	glVertex3f(-0.1f, -0.75f, 0.0f);
	glEnd();

	glColor3f(	0.251, 0.878, 0.816);
	glBegin(GL_POLYGON);
	glVertex3f(-0.075f, -0.75f, 0.0f);
	glVertex3f(0.070f, -0.75f, 0.0f);
	glVertex3f(0.065f, -0.70f, 0.0f);
	glVertex3f(-0.070f, -0.70f, 0.0f);
	glEnd();

	glColor3f(0.498, 1.000, 0.831);
	glBegin(GL_POLYGON);
	glVertex3f(0.070f, -0.725f, 0.0f);
	glVertex3f(0.09f, -0.725f, 0.0f);
	glVertex3f(0.09f, -0.710f, 0.0f);
	glVertex3f(-0.070f, -0.710f, 0.0f);
	glEnd();
	glPopMatrix();

}


void Points(float radiusX, float radiusY, float x)
{

	glBegin(GL_POLYGON);
	double degree = 3.14159265358979323846 / 180;
	for (int i = 0; i<360; i++)
	{
		float R = (rand() % 100) / 100.00;
		float G = (rand() % 100) / 100.00;
		float B = (rand() % 100) / 100.00;
		float radian = i*degree;
		glColor3f(R, G, B);;;
		glVertex3f(x + cos(radian)*radiusX, sin(radian)*radiusY, 0.30);

	}
	glEnd();

}


void Bomb(float radiusX, float radiusY, float x)
{

	int i;
	glBegin(GL_POLYGON);
	double degree = 3.14159265358979323846 / 180;
	for (i = 0; i<360; i++)
	{
		float radian = i*degree;
		glVertex3f(x + cos(radian)*radiusX, sin(radian)*radiusY, 0.30);
	}
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(x, 0.04, 0.30);
	glVertex3f(x, 0.06, 0.30);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3f(x, 0.065, 0.30);
	glEnd();

}


void Mountain()
{

	glPushMatrix();
	///mountain left
	glPushMatrix();
	glColor3f(0.7, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.80);
	glVertex3f(0.2, 0.0, 0.80);
	glVertex3f(0.0, 0.35, 0.80);
	glVertex3f(-0.02, 0.33, 0.80);
	glVertex3f(-0.15, 0.5, 0.80);
	glVertex3f(-0.32, 0.33, 0.80);
	glVertex3f(-0.3, 0.35, 0.80);
	glVertex3f(-0.5, 0.0, 0.80);
	glEnd();
	glPopMatrix();

	glTranslatef(0.8, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.7, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.80);
	glVertex3f(0.2, 0.0, 0.80);
	glVertex3f(0.0, 0.35, 0.80);
	glVertex3f(-0.02, 0.33, 0.80);
	glVertex3f(-0.15, 0.5, 0.80);
	glVertex3f(-0.32, 0.33, 0.80);
	glVertex3f(-0.3, 0.35, 0.80);
	glVertex3f(-0.5, 0.0, 0.80);
	glEnd();
	glPopMatrix();

	glLoadIdentity();

	///left mountain head....
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.13, 0.445, 0.80);
	glVertex3f(-0.08, 0.415, 0.80);
	glVertex3f(-0.15, 0.5, 0.80);
	glVertex3f(-0.23, 0.42, 0.80);
	glVertex3f(-0.19, 0.43, 0.80);
	glVertex3f(-0.198, 0.37, 0.80);
	glVertex3f(-0.17, 0.45, 0.80);
	glVertex3f(-0.1, 0.37, 0.80);
	glEnd();
	glPopMatrix();

	///mountain right

	glPushMatrix();
	glTranslatef(-0.1, 0.0, 0.0);
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, 0.80);
	glVertex3f(0.7, 0.0, 0.80);
	glVertex3f(0.5, 0.35, 0.80);
	glVertex3f(0.48, 0.33, 0.80);
	glVertex3f(0.35, 0.5, 0.80);
	glVertex3f(0.22, 0.33, 0.80);
	glVertex3f(0.2, 0.35, 0.80);
	glVertex3f(0.0, 0.0, 0.80);
	glEnd();
	glPopMatrix();


	///right mountain head.....
	glPushMatrix();
	glTranslatef(0.402, 0.0, 0.0);
	glColor3f(0.99, 0.99, 0.99);
	glBegin(GL_POLYGON);
	glVertex3f(-0.13, 0.444, 0.80);
	glVertex3f(-0.08, 0.414, 0.80);
	glVertex3f(-0.15, 0.52, 0.80);
	glVertex3f(-0.22, 0.414, 0.80);
	glVertex3f(-0.19, 0.43, 0.80);
	glVertex3f(-0.17, 0.445, 0.80);
	glVertex3f(-0.15, 0.36, 0.80);
	glEnd();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-0.9, 0.0, 0.0);
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, 0.80);
	glVertex3f(0.7, 0.0, 0.80);
	glVertex3f(0.5, 0.35, 0.80);
	glVertex3f(0.48, 0.33, 0.80);
	glVertex3f(0.35, 0.5, 0.80);
	glVertex3f(0.22, 0.33, 0.80);
	glVertex3f(0.2, 0.35, 0.80);
	glVertex3f(0.0, 0.0, 0.80);
	glEnd();
	glPopMatrix();


	glPopMatrix();

}


void drawTreeAndTank()
{
	for (int i = 0; i<8; i++)
	{
		glPushMatrix();
		tree(-1.0 + (i*.29f), -0.37, 0.45);
		glPopMatrix();
	}
	glPushMatrix();

	glTranslatef(tankPosition, 0.0f, 0.0f);
	tank(-0.7, 0.2, 0.5);
	glTranslatef(tankPosition1, 0.0f, 0.0f);
	tank(-0.35, 0.0, 0.5);

	glPopMatrix();

	glEnd();
}

void drawAirPlane()
{

	///AirPlane 1
	glPushMatrix();
	glColor3f(.5, 1.0, 0.0);
	glTranslatef(transAirPlane1, 0.750f, 0.0f);
	glScalef(scale1, .6, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	AirPlane(.10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.000, 1.000, 0.000);
	glTranslatef(0.0, transPoints1, 0.0f);
	Points(0.05, 0.02, PointsPos1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, transBomb1, 0.0f);
	Bomb(0.03, 0.04, BombPos1);
	glPopMatrix();



    ///AirPlane 2
    glPushMatrix();
    glColor3f(.5, 1.0, 0.0);
    glTranslatef(transAirPlane2, 0.750f, 0.0f);
    glScalef(scale2, .6, 1.0);
    AirPlane(.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.000, 1.000, 0.000);
    glTranslatef(0.0, transPoints2, 0.0f);
    Points(0.05, 0.02, PointsPos2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, transBomb2, 0.0f);
    Bomb(0.03, 0.04, BombPos2);
    glPopMatrix();



    if(Total_Score>8)
    {
        ///AirPlane 3
        glPushMatrix();
        glColor3f(.7, 0.50, 1.00);
        glTranslatef(transAirPlane3, 0.750f, 0.0f);
        glScalef(scale3, .6, 1.0);
        AirPlane(.20);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.000, 1.000, 0.000);
        glTranslatef(0.0, transPoints3, 0.0f);
        Points(0.05, 0.02, PointsPos3);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(0.0, transBomb3, 0.0f);
        Bomb(0.03, 0.04, BombPos3);
        glPopMatrix();

    }
    if(Total_Score>12)
    {
        ///AirPlane 4
        glPushMatrix();
        glColor3f(.50, 0.50, 0.30);
        glTranslatef(transAirPlane4, 0.750f, 0.0f);
        glScalef(scale4, .6, 1.0);
        AirPlane(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.000, 1.000, 0.000);
        glTranslatef(0.0, transPoints4, 0.0f);
        Points(0.05, 0.02, PointsPos4);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(0.0, transBomb4, 0.0f);
        Bomb(0.03, 0.04, BombPos4);
        glPopMatrix();
    }
}

void collideCondition()
{

	if (moveTank + .06f >= PointsPos1 && moveTank - 0.06f <= PointsPos1 && transPoints1 <= -.7f && transPoints1 >= -.8f)
	{
		score += 1;
		transPoints1 = -1.1f;
		Total_Score++;
	}
	if (moveTank + .06f >= PointsPos2 && moveTank - 0.06f <= PointsPos2 && transPoints2 <= -.7f &&transPoints2 >= -.8f)
	{
		score += 1;
		transPoints2 = -1.1f;
		Total_Score++;
	}
	if (moveTank + .06f >= PointsPos3 && moveTank - 0.06f <= PointsPos3 && transPoints3 <= -.7f && transPoints3 >= -.8f)
	{
		score += 1;
		transPoints3 = -1.1f;
		Total_Score++;

	}
	if (moveTank + .06f >= PointsPos4 && moveTank - 0.06f <= PointsPos4 && transPoints4 <= -.7f &&transPoints4 >= -.8f)
	{
		score += 1;
		transPoints4 = -1.1f;
		Total_Score++;

	}

	if (moveTank + 0.06f >= BombPos1 && moveTank - 0.06f <= BombPos1 && transBomb1 <= -.7f && transBomb1 >= -.8f)
	{
		score -= 2;
		transBomb1 = -1.1f;

	}
	if (moveTank + 0.06f >= BombPos2 && moveTank - 0.06f <= BombPos2 && transBomb2 <= -.7f  && transBomb2 >= -.8f)
	{
		score -= 2;
		transBomb2 = -1.1f;
	}
	if (moveTank + 0.06f >= BombPos3 && moveTank - 0.06f <= BombPos3 && transBomb3 <= -.7f  && transBomb3 >= -.8f)
	{
		score -= 2;
		transBomb3 = -1.1f;
	}
	if (moveTank + 0.06f >= BombPos4 && moveTank - 0.06f <= BombPos4 && transBomb3 <= -.7f  && transBomb3 >= -.8f)
	{
		score -= 2;
		transBomb4 = -1.1f;
	}

	if (score <0)
	{
        disableRendering();
        glutDisplayFunc(ScoreMenu);
	}
}

void checkFunction()
{
	/// tank translation
	if (tankPosition > 1.8f)
		tankPosition = -1.2f;
	if (tankPosition1 > 1.4f)
		tankPosition1 = -1.2f;


	/// cloud translation
	if (cloudSpeed > 1.2f)
	{
		cloudSpeed = -1.2f;
	}
	if (cloudSpeed1 < -1.2f)
	{
		cloudSpeed1 = 1.2f;
	}

	/// points translation
	if (transPoints1 <= -0.88f && transPoints1 >= -0.92f)
	{
		transPoints1 = -1.2f;
	}
	if (transPoints2 <= -0.88f && transPoints2 >= -0.92f)
	{
		transPoints2 = -1.2f;
	}
	if (transPoints3 <= -0.88f && transPoints3 >= -0.92f)
	{
		transPoints3 = -1.2f;
	}
	if (transPoints4 <= -0.88f && transPoints4 >= -0.92f)
	{
		transPoints4 = -1.2f;
	}

	if (transBomb1 <= -0.9f && transBomb1 >= -0.92f)
	{
		transBomb1 = -1.2f;
	}
	if (transBomb2 <= -0.9f && transBomb2 >= -0.92f)
	{
		transBomb2 = -1.2f;
	}
	if (transBomb3 <= -0.9f && transBomb3 >= -0.92f)
	{
		transBomb3 = -1.2f;
	}
	if (transBomb4 <= -0.9f && transBomb4 >= -0.92f)
	{
		transBomb4 = -1.2f;
	}

	/// relay Points
	if (transPoints1 <= -03.5f)
	{
		transPoints1 = 0.75f;
		PointsPos1 = transAirPlane1;
	}
	if (transPoints2 <= -3.5f)
	{
		transPoints2 = 0.75f;
		PointsPos2 = transAirPlane2;
	}
	if (transPoints3 <= -3.5f)
	{
		transPoints3 = 0.75f;
		PointsPos3 = transAirPlane3;
	}
	if (transPoints4 <= -3.5f)
	{
		transPoints4 = 0.75f;
		PointsPos4 = transAirPlane4;
	}

	///Bomb reLay
	if (transBomb1 <= -3.50f)
	{
		transBomb1 = 0.75f;
		BombPos1 = transAirPlane1;
	}
	if (transBomb2 <= -3.50f)
	{
		transBomb2 = 0.75f;
		BombPos2 = transAirPlane2;
	}
	if (transBomb3 <= -3.50f)
	{
		transBomb3 = 0.75f;
		BombPos3 = transAirPlane3;
	}
	if (transBomb4 <= -3.5f)
	{
		transBomb4 = 0.75f;
		BombPos4 = transAirPlane4;
	}

	if (transAirPlane1 >= 0.90 || transAirPlane1 <= -0.90)
	{
		positionOfPlane1 *= -1;
		scale1 *= -1;
	}
	if (transAirPlane2 >= 0.90 || transAirPlane2 <= -0.90)
	{
		positionOfPlane2 *= -1;
		scale2 *= -1;
	}
	if (transAirPlane3 >= 0.90 || transAirPlane3 <= -0.90)
	{
		positionOfPlane3 *= -1;
		scale3 *= -1;
	}
	if (transAirPlane4 >= 0.90 || transAirPlane4 <= -0.90)
	{
		positionOfPlane4 *= -1;
		scale4 *= -1;
	}

	/// survivingObject Movement
	if (moveTank >= 0.9)
	{
		moveTank = 0.9f;
	}
	if (moveTank <= -0.9)
	{
		moveTank = -0.9f;
	}

	///timer & speed checking
	if (Total_Score == 5)
	{
		timer = 10;
	}
	else if (Total_Score == 10)
	{
		timer = 7;
	}
	else if (Total_Score == 15)
	{
		timer = 5;
	}
	else if (Total_Score == 20)
	{
		timer = 3;
	}
	else if (Total_Score == 20)
	{
		timer = 1;
	}

}


void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

	/// draw score
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	drawScore(GLUT_BITMAP_TIMES_ROMAN_24, "LIFE :: ", score, -0.93, -0.94);
	drawTotalScore(GLUT_BITMAP_TIMES_ROMAN_24, "Total Score :: ", Total_Score, 0.60, -0.94);
	glPopMatrix();

	road();
	field();
	cloud();
	drawTreeAndTank();

	glPushMatrix();
	glTranslatef(moveTank, 0.0f, 0.0f);
	survivingObject();
	glPopMatrix();


	drawAirPlane();

	glTranslatef(0.0, 0.0, 0.90);
	sun();
	glLoadIdentity();

	Mountain();


	collideCondition();
	checkFunction();

	glutSwapBuffers();
}


void update(int value)
{
	if (gameMode == 'r')
	{
		tankPosition += .0075;
		tankPosition1 += .0050;


		cloudSpeed += 0.0007f;
		cloudSpeed1 -= 0.0010f;

		transPoints1 -= 0.005;
		transPoints2 -= 0.005;
		transPoints3 -= 0.005;
		transPoints4 -= 0.005;

		transBomb1 -= 0.005f;
		transBomb2 -= 0.005f;
		transBomb3 -= 0.005f;
		transBomb4 -= 0.005f;


		transAirPlane1 += positionOfPlane1;
		transAirPlane2 += positionOfPlane2;
		transAirPlane3 += positionOfPlane3;
		transAirPlane4 += positionOfPlane4;
	}

	else
	{
		tankPosition += 0;
		tankPosition1 += 0;

		cloudSpeed += 0;
		cloudSpeed1 -= 0;

		transPoints1 -= 0;
		transPoints2 -= 0;
		transPoints3 -= 0;
		transPoints4 -= 0;

		transBomb1 -= 0;
		transBomb2 -= 0;
		transBomb3 -= 0;
		transBomb4 -= 0;


		transAirPlane1 += 0;
		transAirPlane2 += 0;
		transAirPlane3 += 0;
		transAirPlane4 += 0;
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed

	glutTimerFunc(timer, update, 0);
}


void specialKeys(int key, int x, int y)
{

	switch (key)
	{
	case GLUT_KEY_LEFT:
		moveTank -= 0.05f;

		break;
	case GLUT_KEY_RIGHT:
		moveTank += 0.05f;
		break;
	}
}


void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
            //cout<< x<<" "<<y<<endl;
			if (x >= 330 && x <= 900)
			{
				if (y >= 265 && y <= 320)
				{
					initRendering();
					glutDisplayFunc(drawScene);
				}
			}

			if (x >= 400 && x <= 900)
			{
				if (y >= 350 && y <= 600)
				{
					exit(0);

				}
			}

		}
	}
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{



	switch (key)
	{

	case 'p':
	case 'P':
	{
		gameMode = 'p';

		break;
	}

	case 'r':
	case 'R':
	{
		gameMode = 'r';

		break;
	}

	case 'A':
	case 'a':
		moveTank -= 0.05f;

		break;
	case 'D':
	case 'd':
		moveTank += 0.05f;
		break;


	glutPostRedisplay();


	}
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 700);


	glutCreateWindow("Ultimate Survival");
	glutDisplayFunc(Menu);
	glutReshapeFunc(handleResize);


	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMouse);

	glutTimerFunc(10, update, 0);
	glutMainLoop();
	return 0;
}




