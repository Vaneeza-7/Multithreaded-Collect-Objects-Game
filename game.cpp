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
int x2=0, y2=0;
int x3, y3, x4, y4, x5, y5/**Ptrx, *Ptry*/;
int a = 60, b=100;
int c=b-a;

int x=50, y=670;
int z=y-x;
pthread_t  t1, t2, t3, t4;   


int X1=300, Y1=450, X2=700, Y2=350,X3=500, Y3=400,X4=500, Y4=650,X5=600, Y5=600,X6=400, Y6=550;

int X7=350, Y7=500, X8=200, Y8=350,X9=100, Y9=400,X10=500, Y10=300,X11=150, Y11=200,X12=300, Y12=200;

int score1=0, score2=0;

bool objects[741][691];


	

	
//for(int i=0; i<741; i++)
//{
//  for(int j=0; j<691; j++)
//  {
//     objects[i][j]=false;
//  }
//}
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

void* drawPlayer(void* arg){
 DrawCircle(a, b, 10,colors[BLACK]);
	DrawLine( a , b , a , c , 2 , colors[BLACK] );
	DrawLine( a , c ,  a+10 , c-20 , 2 , colors[BLACK] );
        DrawLine( a , c , a-20 , c-20 , 2 , colors[BLACK] );
        glutPostRedisplay();
        return NULL;
}
void* drawPassenger(void* arg)                                       //draws passenger in the display
{ 

         DrawCircle(x,y,10,colors[BLACK]);
	 DrawLine( x , y,  x , z , 2 , colors[BLACK] );
	 DrawLine( x , z ,  x+10 , z-20 , 2 , colors[BLACK] );
         DrawLine( x , z ,  x-20 , z-20 , 2 , colors[BLACK] );
         glutPostRedisplay();
         return NULL;
//  
//         DrawCircle(50,670,10,colors[WHITE]);
//	 DrawLine( 50 , 670 ,  50 , 620 , 2 , colors[WHITE] );
//	 DrawLine( 50 , 620 ,  60 , 600 , 2 , colors[WHITE] );
//         DrawLine( 50 , 620 ,  40 , 600 , 2 , colors[WHITE] );
        
//        vector<unsigned char> imgArray;
//        ReadImage("sprite.png", imgArray);
//         using namespace cimg_library;
//        CImg<unsigned char> img("sprite.png");
//        img.display();
       
        
//        for (int j = 0; j < img.width(); ++j) {
//		int t = j;
//		for (int i = 0; i < img.height(); ++i, t += img.width()) {
//			imgArray[k++] = rp[t];
//			imgArray[k++] = gp[t];
//			imgArray[k++] = bp[t];
//		}
//		//imgArray[i][j] = img[k++];
//	}
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
cout<<"---------------START MENU---------------\nC0LLECT 0BJECTS GAME\n";

       cout<<"---The Rules---\n1.Player must collect maximum objects to win the game.\n\n";
       cout<<"Player1 plays with arrow keys and shift key to collect objects.\n\nPlayer2 plays with ASDW and spacebar to collect objects.\n\n";
       cout<<"Enter Player1 name: ";
       cin>>name1;
       cout<<"Enter Player2 name: ";
       cin>>name2;

} 



	
void objExist(int xx, int yy)
{
       
       objects[300][450]=true;
	objects[340][450]=true;
	objects[320][490]=true;
	objects[700][350]=true;
	objects[740][350]=true;
	objects[720][390]=true;
	objects[500][400]=true;
	objects[540][400]=true;
        objects[520][440]=true;
	objects[500][650]=true;
	objects[540][650]=true;
	objects[520][690]=true;
	objects[600][600]=true;
	objects[640][600]=true;
	objects[620][640]=true;
	objects[400][550]=true;
	objects[440][550]=true;
	objects[420][590]=true;
	objects[350][500]=true;
	objects[390][500]=true;
	objects[370][540]=true;
	objects[xx][yy]=false;

}	
void drawBoard(int xxx, int yyy)                                 //Draws the player board
{
      // set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1, 1, 1, 1); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	objExist(xxx, yyy);
        DrawLine(100, 100, 800, 100, 10, colors[DARK_CYAN]); //bottom line
	DrawLine(100, 100, 100, 800, 10, colors[DARK_CYAN]); // left line
	DrawLine(100, 800, 800, 800, 10, colors[DARK_CYAN]); //top line
	DrawLine(800, 100, 800, 800, 10, colors[DARK_CYAN]); //right line


        for(int i=100; i<800; i=i+50)
        {DrawLine( 100 , i ,  800 , i , 4 , colors[DARK_CYAN] );}
        
        for(int i=100; i<800; i=i+50)
        {DrawLine( i , 100 ,  i , 800 , 4 , colors[DARK_CYAN] );}
        
        
	
//	objects[300][450]==true;
//	objects[340][450]==true;
//	objects[320][490]==true;
//	objects[700][350]=true;
//	objects[740][350]=true;
//	objects[720][390]=true;
//	objects[500][400]=true;
//	objects[540][400]=true;
//        objects[520][440]=true;
//	objects[500][650]=true;



        DrawTriangle( X1, Y1 , X1+40, Y1 , X1+20 , Y1+40, colors[GOLD] );	
	DrawTriangle( X2, Y2 , X2+40, Y2 , X2+20 , Y2+40, colors[ORANGE] );
	DrawTriangle( X3, Y3 , X3+40, Y3 , X3+20 , Y3+40, colors[BLUE] );
	DrawTriangle( X4, Y4 , X4+40, Y4 , X4+20 , Y4+40, colors[GREEN] );
	DrawTriangle( X5, Y5 , X5+40, Y5 , X5+20 , Y5+40, colors[VIOLET] );
	DrawTriangle( X6, Y6 , X6+40, Y6 , X6+20 , Y6+40, colors[TOMATO] );
	DrawTriangle( X7, Y7 , X7+40, Y7 , X7+20 , Y7+40, colors[CRIMSON] );	
	
	DrawTriangle( X8, Y8 , X8+40, Y8 , X8+20 , Y8+40, colors[HOT_PINK] );
	DrawTriangle( X9, Y9 , X9+40, Y9 , X9+20 , Y9+40, colors[DEEP_PINK] );
	DrawTriangle( X10, Y10 , X10+40, Y10 , X10+20 , Y10+40, colors[NAVY] );
	DrawTriangle( X11, Y11 , X11+40, Y11 , X11+20 , Y11+40, colors[PLUM] );
	DrawTriangle( X12, Y12 , X12+40, Y12 , X12+20 , Y12+40, colors[TAN] );
	

//        DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[var] );	
//	DrawTriangle( 700, 350 , 740, 350 , 720 , 390, colors[ORANGE] );
//	DrawTriangle( 500, 400 , 540, 400 , 520 , 440, colors[BLUE] );
//	DrawTriangle( 500, 650 , 540, 650 , 520 , 690, colors[GREEN] );
//	DrawTriangle( 600, 600 , 640, 600 , 620 , 640, colors[VIOLET] );
//	DrawTriangle( 400, 550 , 440, 550 , 420 , 590, colors[TOMATO] );
//	DrawTriangle( 350, 500 , 390, 500 , 370 , 540, colors[CRIMSON] );	
//	
//	DrawTriangle( 200, 350 , 240, 350 , 220 , 390, colors[HOT_PINK] );
//	DrawTriangle( 100, 400 , 140, 400 , 120 , 440, colors[DEEP_PINK] );
//	DrawTriangle( 500, 300 , 540, 300 , 520 , 340, colors[NAVY] );
//	DrawTriangle( 150, 200 , 190, 200 , 170 , 240, colors[PLUM] );
//	DrawTriangle( 300, 200 , 340, 200 , 320 , 240, colors[TAN] );
	
	//DrawTriangle(xxx, yyy, xxx+40, yyy, xxx+20, yyy+40,colors[WHITE]);
	//Display Score
	DrawString( 20, 800, "Player1 Score=", colors[BLACK]);
	DrawString( 180, 800, Num2Str(score1), colors[BLACK]);
	DrawString( 800, 800, "Player2 Score=", colors[BLACK]);
	DrawString( 950, 800, Num2Str(score2), colors[BLACK]);
	
}	



/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	int nothing=0;
	drawBoard(x2, y2);
	//drawTaxi();
	//drawblueCar();
	//drawGreenCar();
	//drawCyanCar();
	//drawPurpleCar();
	DrawTriangle(x2, y2, x2+40, y2, x2+20, y2+40,colors[WHITE]);
	
	drawPassenger((void*)nothing);
	drawPlayer((void*)nothing);
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

void NonPrintableKeys(int key, int xx, int yy) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//xI -= 10;
		a -= 10;
	

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//xI += 10;
		a += 10;
		
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//yI += 10;
		b += 10;
	        c+=10;
		
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//yI -= 10;

		b -= 10;
		c-=10;
		
	}

	     
	
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

void drawing()
{
   DrawTriangle(x, y, x+40, y, x+20, y+40,colors[WHITE]);
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int xx, int yy) {
//	if (key == 27/* Escape key ASCII*/) {
//		exit(1); // exit the program when escape key is pressed.
//	}
//	x =xI;
//	y =yI;

//	if (key == 32 && xI==53)                      //when spacebar pressed disappear the passenger
//			{
//			  if (yI ==670 || yI==187)
//			   {
//			    DrawSquare(xI, yI, 30, colors[BLACK]);
//			   }   
//		
//		cout << "space pressed" << endl;

//	}
//	ascii of A is 97, d is 100 , s is 115, w is 119
	
	
	if(key ==100)
	{
	   //xI+=10;
	   x+=10;
	
	}
	else if (key ==97)
	{
	   //xI-=10;
	   x-=10;
	}
	else if (key ==115)
	{
	   y-=10;
	   z-=10;
	}
	else if (key ==119)
	{
	   y+=10;
	   z+=10;
	}
	else if(key==32)
	{
//	   if (objects[x][y]==true || objects[x][z]==true)
//	       //DrawTriangle(x, y, x+40, y, x+20, y+40,colors[BLUE]);
//	       cout<<"Object at point ["<<x<<"]["<<y<<"]endl";
//	       x2=x;
//	       y2=y;
	       
	       if(x==X1 && y==Y1)
	       {X1=-100;
	       Y1=-100;
	       score1+=5;
	       x2=x;
	       y2=y;}
	       if(x==X2 && y==Y2)
	       {X2=-100;
	       Y2=-100;
	       score1+=5;
	       x2=x;
	       y2=y;}
	       if(x==X3 && y==Y3)
	       {X3=-100;
	       Y3=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X4 && y==Y4)
	       {X4=-100;
	       Y4=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X5 && y==Y5)
	       {X5=-100;
	       Y5=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X6 && y==Y6)
	       {X6=-100;
	       Y6=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X7 && y==Y7)
	       {X7=-100;
	       Y7=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X8 && y==Y8)
	       {X8=-100;
	       Y8=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X9 && y==Y9)
	       {X9=-100;
	       Y9=-100;
	       score1+=5;
	       x2=x;
	       y2=y;} 
	       if(x==X10 && y==Y10)
	       {X10=-100;
	       Y10=-100;
	       score1+=5;
	       x2=x;
	       y2=y;}
	       if(x==X11 && y==Y11)
	       {X11=-100;
	       Y11=-100;
	       score1+=5;
	       x2=x;
	       y2=y;}
	       if(x==X12 && y==Y12)
	       {X12=-100;
	       Y12=-100;
	       score1+=5;
	       x2=x;
	       y2=y;}    
	       objects[x][y]=false;
	       //glutDisplayFunc(drawing);
	       
	}
	
	else if (key==8)
	{
	    if(a==X1 && b==Y1)
	       {X1=-100;
	       Y1=-100;
	       score2+=5;
	       x2=a;
	       y2=b;}
	       if(a==X2 && b==Y2)
	       {X2=-100;
	       Y2=-100;
	       score2+=5;
	       x2=a;
	       y2=b;}
	       if(a==X3 && b==Y3)
	       {X3=-100;
	       Y3=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X4 && b==Y4)
	       {X4=-100;
	       Y4=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X5 && b==Y5)
	       {X5=-100;
	       Y5=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X6 && b==Y6)
	       {X6=-100;
	       Y6=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X7 && b==Y7)
	       {X7=-100;
	       Y7=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X8 && b==Y8)
	       {X8=-100;
	       Y8=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X9 && b==Y9)
	       {X9=-100;
	       Y9=-100;
	       score2+=5;
	       x2=a;
	       y2=b;} 
	       if(a==X10 && b==Y10)
	       {X10=-100;
	       Y10=-100;
	       score2+=5;
	       x2=a;
	       y2=b;}
	       if(a==X11 && b==Y11)
	       {X11=-100;
	       Y11=-100;
	       score2+=5;
	       x2=a;
	       y2=b;}
	       if(a==X12 && b==Y12)
	       {X12=-100;
	       Y12=-100;
	       score2+=5;
	       x2=a;
	       y2=b;}    
	       objects[a][b]=false;
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
        string name1, name2;
          pthread_create(&t1, NULL, Menu, (void*) width);
         pthread_join(t1, NULL);
          //sleep(2);
          
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Collect Objects by Vaneeza Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

//        GLuint texture;
//        texture = LoadTexture("sprite.bmp");
//	glBindTexture (GL_TEXTURE_2D, texture); 
//	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

        generateBoard:
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
         
          pthread_create(&t2, NULL, drawPlayer, NULL);
         pthread_join(t2, NULL);
        
         pthread_create(&t3, NULL, drawPassenger, (void*) width);
         pthread_join(t3, NULL);
         
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
