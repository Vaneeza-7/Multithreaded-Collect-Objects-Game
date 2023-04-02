//============================================================================
// Name        : Vaneeza Ahmad
// Roll no     : 21I-0390
// Class       : BSCS-Y
// Author      : FAST CS Department
// Version     : 2.1
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<pthread.h>

#include <fstream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);           // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

string *ptr;                                          //using pointer to assign color to taxi
int xI = 10, yI = 800;
int x2, y2, x3, y3, x4, y4, x5, y5/**Ptrx, *Ptry*/;
int a = 60, b=100;
int c=b-a;
pthread_t  t1, t2, t3, t4;   
void drawTaxi() 
{
     if(*ptr=="red")
   {
     DrawSquare(xI, yI, 40, colors[RED]);
     glutPostRedisplay();
   }
	                                               //draws the taxi that moves with controls
     else if(*ptr=="yellow")
   {
      DrawSquare(xI, yI, 40, colors[ORANGE]);
      glutPostRedisplay();
   }
}


void drawblueCar() 
{   

       x2 = 300;
       y2 = GetRandInRange(10, 300);
                                                        //draws a random moving blue car 
       DrawSquare(x2, y2, 30, colors[BLUE]);
       glutPostRedisplay();
}

void drawGreenCar()
{

      InitRandomizer();       
       x3 = GetRandInRange(550, 1010);
       y3 = 65;
                                                      //draws a random moving green car 
       DrawSquare(x3, y3, 30, colors[YELLOW]);      
}

void drawPlayer(){
 DrawCircle(a, b, 10,colors[WHITE]);
	DrawLine( a , b , a , c , 2 , colors[WHITE] );
	DrawLine( a , c ,  a+10 , c-20 , 2 , colors[WHITE] );
        DrawLine( a , c , a-20 , c-20 , 2 , colors[WHITE] );
        glutPostRedisplay();
}
void drawPassenger()                                       //draws passenger in the display
{   
         DrawCircle(50,670,10,colors[WHITE]);
	 DrawLine( 50 , 670 ,  50 , 620 , 2 , colors[WHITE] );
	 DrawLine( 50 , 620 ,  60 , 600 , 2 , colors[WHITE] );
         DrawLine( 50 , 620 ,  40 , 600 , 2 , colors[WHITE] );
        
      /*int a = GetRandInRange(50, 90);
      int b = 100;  
      int c= b-a;*/
        
        
         
//        DrawCircle(500, 530, 10,colors[WHITE]);
//	DrawLine( 500 , 530 , 500 , 490 , 2 , colors[WHITE] );
//	DrawLine( 500 , 490,  510 , 470 , 2 , colors[WHITE] );
//        DrawLine( 500 , 490 , 480 , 470 , 2 , colors[WHITE] );
}      
void drawCyanCar() 
{   

        x4 = GetRandInRange(500, 880);
        y4 = 410;
                         //draws a random moving cyan car 
       DrawSquare(x4, y4, 30, colors[DARK_CYAN]);
       glutPostRedisplay();
}

void drawPurpleCar() 
{   

        x5 = GetRandInRange(515, 990);
        y5 = 800;
                         //draws a random moving purple car 
       DrawSquare(x5, y5, 30, colors[VIOLET]);
       glutPostRedisplay();
}

void* Menu(void* arg)
{
string name1, name2, taxi;
cout<<"---------------START MENU---------------\nC0LLECT 0BJECTS GAME\n TWO PLAYERS GAME";
       cout<<"Enter Player1 name: ";
       cin>>name1;
       cout<<"Enter Player2 name: ";
       cin>>name2;
       cin>>taxi;
            
      
       cout<<"Play the game by using arrowkeys"<<endl;


}

void drawBoard()                                 //Draws the player board
{
      // set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0, 0, 0, 0); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
//        //Draw Buildings
//        for(int i=20; i<181; i=i+40)
//        {
//	 DrawSquare(400, i, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=400; i<521; i=i+40)
//        {
//	DrawSquare(400, i, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=320; i<561; i=i+40)
//        {
//      	DrawSquare(i, 350, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=700; i<901; i=i+40)
//        {
//	DrawSquare(i, 500, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=740; i<901; i=i+40)
//        {
//	DrawSquare(i, 500, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=600; i<721; i=i+40)
//        {
//	DrawSquare(200, i, 50, colors[DARK_CYAN]);
//	}
//	for(int i=480; i<801; i=i+40)
//        {
//	DrawSquare(i, 700, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=660; i<741; i=i+40)
//	{
//	DrawSquare(720, i, 60, colors[DARK_CYAN]);
//	}
//	
//	for(int i=320; i<521; i=i+40)
//        {
//	DrawSquare(i, 350, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=140; i<261; i=i+40)
//        {
//	DrawSquare(100, i, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=0; i<81; i=i+40)
//        {
//	DrawSquare(i, 140, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=700; i<821; i=i+40)
//        {
//	DrawSquare(i, 260, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=100; i<221; i=i+40)
//        {
//	DrawSquare(700, i, 50, colors[DARK_CYAN]);
//        }
//	
//	for(int i=40; i<161; i=i+40)
//        {
//	DrawSquare(i, 450, 50, colors[DARK_CYAN]);
//	}
//	
//	for(int i=100; i<221; i=i+40)
//        {	
//	DrawSquare(i, 20, 50, colors[DARK_CYAN]);
//	}
//	
//	//Draw Roads
//        



        for(int i=100; i<800; i=i+50)
        {DrawLine( 100 , i ,  800 , i , 4 , colors[DARK_CYAN] );}
        
        for(int i=100; i<800; i=i+50)
        {DrawLine( i , 100 ,  i , 800 , 4 , colors[DARK_CYAN] );}
        
        
	//Draw Trees
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[GOLD] );	
	DrawTriangle( 700, 350 , 740, 350 , 720 , 390, colors[ORANGE] );
	DrawTriangle( 500, 400 , 540, 400 , 520 , 440, colors[BLUE] );
	DrawTriangle( 500, 650 , 540, 650 , 520 , 690, colors[GREEN] );
	DrawTriangle( 600, 600 , 640, 600 , 620 , 640, colors[VIOLET] );
	DrawTriangle( 400, 550 , 440, 550 , 420 , 590, colors[YELLOW] );
	
	
	DrawTriangle( 350, 500 , 390, 500 , 370 , 540, colors[CRIMSON] );	
	DrawTriangle( 200, 350 , 240, 350 , 220 , 390, colors[HOT_PINK] );
	DrawTriangle( 100, 400 , 140, 400 , 120 , 440, colors[DEEP_PINK] );
	DrawTriangle( 500, 300 , 540, 300 , 520 , 340, colors[LAVENDER] );
	DrawTriangle( 150, 200 , 190, 200 , 170 , 240, colors[PLUM] );
	DrawTriangle( 300, 200 , 340, 200 , 320 , 240, colors[TAN] );
	
	
	//Display Score
	DrawString( 20, 800, "Player1 Score=", colors[WHITE]);
	DrawString( 180, 800, Num2Str(45), colors[WHITE]);
	DrawString( 800, 800, "Player2 Score=0", colors[WHITE]);
	
	
}	



/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	
	drawBoard();
	drawTaxi();
	//drawblueCar();
	//drawGreenCar();
	//drawCyanCar();
	//drawPurpleCar();
	drawPassenger();
	drawPlayer();
        glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//xI -= 10;
		a -= 10;
//		if(b>a)
//		{c=b-a;}
//		else
//		c=a-b;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//xI += 10;
		a += 10;
		//c=b-a;
//		if(b>a)
//		{c=b-a;}
//		else
//		c=a-b;
		
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//yI += 10;
		b += 10;
	c+=10;
//		if(b>a)
//		{c=b-a;}
//		else
//		c=a-b;
		
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//yI -= 10;

		b -= 10;
		c-=10;
//		if(b>a)
//		{c=b-a;}
//		else
//		c=a-b;
		
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	x =xI;
	y =yI;

	if (key == 32 && xI==53)                      //when spacebar pressed disappear the passenger
			{
			  if (yI ==670 || yI==187)
			   {
			    DrawSquare(xI, yI, 30, colors[BLACK]);
			   }   
		
		cout << "space pressed" << endl;

	}
	
	
	if(key ==65)
	{
	   xI+=10;
	
	}
	else if (key ==68)
	{
	   xI-=10;
	}
	else if (key ==83)
	{
	   yI-=10;
	}
	else if (key ==87)
	{
	   yI+=10;
	}
	
	
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	
	//moveCyanCar();
	

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600 
        string name1, name2, taxi;
    
       ptr = & taxi;
//       cout<<"---------------START MENU---------------\nC0LLECT 0BJECTS GAME\n TWO PLAYERS GAME";
//       cout<<"Enter Player1 name: ";
//       cin>>name1;
//       cout<<"Enter Player2 name: ";
//       cin>>name2;
//       cin>>taxi;
//            
//      
//       cout<<"Play the game by using arrowkeys"<<endl;

          pthread_create(&t1, NULL, Menu, (void*) width);
         pthread_join(t1, NULL);
          //sleep(2);
          cout<<"Enter taxi";
cin>>taxi;
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Collect Objects by Vaneeza Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
