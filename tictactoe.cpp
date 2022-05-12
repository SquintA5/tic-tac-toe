#include<iostream>
#include<cstdio>
#include<conio.h>
#include<Windows.h>
using namespace std;


char name[2][30];		//Two-dimensional array to store names of player
int chance;				//To store the chance, to track which player is to enter the move.
int box;				//To track the current box the player is on at the moment
char arr[3][3];			//Array to hold the actual values that player enters while playing
int turns;				//To count the number of chances

const int CENTER = 35;

//Function prototype to handle key presses & update the current
//box the player is on and to enter the move into the box when 
//the player presses Enter.
int navigate(char arr[3][3], int box, int player, int key);

//Function prototype to put move into player-chosen box and
//to make sure value already present isn't overwritten.
void putIntoBox(char arr[3][3], char ch, int box);

//Show the frame of the tic tac toe board on specified position
void showFrame(int posX, int posY);

//Show a specified character in the specified box
void showBox(int ch, int box);

//Take the cursor into the specified box
void goToBox(int box);

//Checks if the player wins
int checkForWin(char arr[3][3]); 

//To check how many boxes are left
int boxesLeft(char arr[3][3]); 

int main() {		//Marked for revision
	//Set up the game board
	showFrame(12,25);	
	//Get player names
	printf("\nPlayer 1, enter your name:");
	fgets(name[0], 30, stdin);		//stdin means standard input
	printf("\nPlayer 2, enter your name:");
	fgets(name[1], 30, stdin);
	//Assign Xs and Os
	printf("\n%s, you take O", name[0]);
	printf("\n%s, you take X", name[1]);
	getch();	//Get character, returns ASCII value of character read from stdin
	
	clrscr();	//Clear screen? (need to find substitute for this)
	/*
	do {
		while(!enter) {
			if(kbhit())		//kbhit means a non-zero integer is returned if a key is in the keyboard buffer
				ch = getch();
			switch(ch){
				case UPARROW: box = navigate(arr[3][3], box, player, UPARROW);
				break;
				case DOWNARROW: box = navigate(arr[3][3], box, player, DOWNARROW);
				break;
				case LEFTARROW: box = navigate(arr[3][3], box, player, LEFTARROW);
				break;
				case RIGHTARROW: box = navigate(arr[3][3], box, player, RIGHTARROW);
				break;
			}
		}if (quit)
			break;
		win = checkForWin(a); //Check if the player wins
	}while(!win)
		
	//if (win) {
		
		*/
	
	return 0;
}

void goToXY(int x, int y) {
	//COORD holds screen coordinates
	COORD coord; //Assign variable name
	coord.X = x; //Assign x coordinate
	coord.Y = y; //Assign y coordinate
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showFrame(int posX, int posY) {
	int hr = 196, vr = 179;		//ASCII characters that display the lines
	int crossbr = 197;			//ASCII character (cross)
	int x = posX, y = posY;		//Storing the function parameters in variables
	int i, j;					//Loop counters
	
	goToXY(CENTER,4);				//goToXY sets coordinates for Windows Console
	_cprintf("TIC TAC TOE");		//cprintf writes output directly to console
	goToXY(CENTER,5);
	for (i = 0; i < 11; i++) {	//Loop to underline title.
		_cprintf("%c", 223);		//%c specifies a single character, ASCII 223 is top half block
	}
	
	for (i = 0; i < 2; i++) {	//Nested loops to print the horizontal board lines
		for (j = 1; j < 11; j++) { //10 horizontal lines printing at function coordinates
			goToXY(x, y);		//Starting point
			printf("%c", hr);	//Printing single horizontal line
			x++;				//Move the x point to right 1 space
		}
		x = posX;				//Reset the x point
		y += 2;					//Add 2 to y (move the y point up 2 spaces?)
	}
		
	x = posX + 3;				//Move x point forward 3 spaces
	y = posY - 1;				//Move y point up 1 space
	
	for (i = 0; i < 2; i++) {	//Nested loops to print the vertical board lines
		for (j = 1; j < 5; j++) {	//5 vertical lines printing at function coordinates
			goToXY(x,y);			//New starting point
			printf("%c", vr);		//Printing single vertical line
			y++;					//Move y point down 1 space
		}
		x += 4;						//Move x point 4 spaces to right
		y = posY - 1;				//Move y point 1 space up from function coordinate
	}
	
	//This whole section is printing the crosses that connect the lines
	x = posX + 3;
	y = posY;
	goToXY(x,y);
	printf("%c", crossbr);
	
	x = posX + 7;
	y = posY;
	goToXY(x,y);
	printf("%c", crossbr);
	
	x = posX + 3;
	y = posY + 2;
	goToXY(x,y);
	printf("%c", crossbr);
	
	x = posX + 7;
	y = posY + 2;
	goToXY(x,y);
	printf("%c", crossbr);
}

void showBox(char ch, int box) {		//Marked for revision
	switch(box) {
		case 1: goToXY(_x+1,_y-1);	//1st box
		printf("%c", ch);
		break;
		case 2: goToXY(_x+5,_y-1);	//2nd box
		printf("%c", ch);
		break;
		case 3: goToXY(_x+9,_y-1);	//3rd box
		printf("%c", ch);
		break;
		case 4: goToXY(_x+1,_y+1);	//4th box
		printf("%c", ch);
		break;
		case 5: goToXY(_x+5,_y+1);	//5th box
		printf("%c", ch);
		break;
		case 6: goToXY(_x+9,_y+1);	//6th box
		printf("%c", ch);
		break;
		case 7: goToXY(_x+1,_y+3);	//7th box
		printf("%c", ch);
		break;
		case 8: goToXY(_x+5,_y+3);	//8th box
		printf("%c", ch);
		break;
		case 9: goToXY(_x+9,_y+3);	//9th box
		printf("%c", ch);
		break;
	}
}

void putIntoBox(char arr[3][3], char ch, int box) {		//Marked for revision
	switch(box) {
		case 1: if(arr[0][0] != 'X' && arr[0][0] != 'O') {
					arr[0][0] = ch;
					showBox(ch,1);
		}
		break;
		case 2: if(arr[0][1] != 'X' && arr[0][1] != 'O') {
					arr[0][1] = ch;
					showBox(ch,2);
		}
		break;
		case 3: if(arr[0][2] != 'X' && arr[0][2] != 'O') {
					arr[0][2] = ch;
					showBox(ch,3);
		}
		break;
		case 4: if(arr[1][0] != 'X' && arr[1][0] != 'O') {
					arr[1][0] = ch;
					showBox(ch,4);
		}
		break;
		case 5: if(arr[1][1] != 'X' && arr[1][1] != 'O') {
					arr[1][1] = ch;
					showBox(ch,5);
		}
		break;
		case 6: if(arr[1][2] != 'X' && arr[1][2] != 'O') {
					arr[1][2] = ch;
					showBox(ch,6);
		}
		break;
		case 7: if(arr[2][0] != 'X' && arr[2][0] != 'O') {
					arr[2][0] = ch;
					showBox(ch,7);
		}
		break;
		case 8: if(arr[2][1] != 'X' && arr[2][1] != 'O') {
					arr[2][1] = ch;
					showBox(ch,8);
		}
		break;
		case 9: if(arr[2][2] != 'X' && arr[2][2] != 'O') {
					arr[2][2] = ch;
					showBox(ch,9);
		}
		break;
	}//End of switch
}

void goToBox(int box) {		//Marked for revision
	switch(box) {
		case 1: goToXY(_x+1,_y-1);	//1st box
		break;
		case 2: goToXY(_x+5,_y-1);	//2nd box
		break;
		case 3: goToXY(_x+9,_y-1);	//3rd box
		break;
		case 4: goToXY(_x+1,_y+1);	//4th box
		break;
		case 5: goToXY(_x+5,_y+1);	//5th box
		break;	
		case 6: goToXY(_x+9,_y+1);	//6th box
		break;
		case 7: goToXY(_x+1,_y+3);	//7th box
		break;
		case 8: goToXY(_x+5,_y+3);	//8th box
		break;
		case 9: goToXY(_x+9,_y+3);	//9th box
		break;
	}
}

int navigate(char arr[3][3], int box, int player, int key) {		//Marked for revision
	switch(key) {
		case UPARROW: if( (box != 1) || (box != 2) || (box != 3) ) {
						box -= 3;
						if (box < 1)
							box = 1;
						goToBox(box);
						}
		break;
		case DOWNARROW: if( (box != 7) || (box != 8) || (box != 9) ) {
						box += 3;
						if (box > 9)
							box = 9;
						goToBox(box);
						}
		break;
		case LEFTARROW: if( (box != 1) || (box != 4) || (box != 7) ) {
						box--;
						if (box < 1)
							box = 1;
						goToBox(box);
						}
		break;
		case RIGHTARROW: if( (box != 3) || (box != 6) || (box != 9) ) {
						box++;
						if (box > 9)
							box = 9;
						goToBox(box);
						}
		break;
		case ENTER:	if(player == 0)
						putIntoBox(arr,'O',box);
					else if(player == 1)
						putIntoBox(arr,'X',box);
		break;
	}//End of switch(key)
	return box;
}

int checkForWin(char arr[3][3]) {		//Marked for revision
	int w = 0;
	/*
	0,0	0,1	0,2
	1,0	1,1	1,2
	2,0	2,1	2,2
	*/
	//rows
	if ( (arr[0][0] == arr[0][1]) && (arr[0][1] == arr[0][2]) )
		w = 1;
	else if ( (arr[1][0] == arr[1][1]) && (arr[1][1] == arr[1][2]) )
		w = 1;
	else if ( (arr[2][0] == arr[2][1]) && (arr[2][1] == arr[2][2]) )
		w = 1;
	//columns
	else if ( (arr[0][0] == arr[1][0]) && (arr[1][0] == arr[2][0]) )
		w = 1;
	else if ( (arr[0][1] == arr[1][1]) && (arr[1][1] == arr[2][1]) )
		w = 1;
	else if ( (arr[0][2] == arr[1][2]) && (arr[1][2] == arr[2][2]) )
		w = 1;
	//diagonal
	else if ( (arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) )
		w = 1;
	else if ( (arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) )
		w = 1;
	
	return w;
}

int boxesLeft(char arr[3][3]) {		//Marked for revision
	int i, j, boxesLeft = 9;
	//Nested loop to go check through each box
	for(i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((arr[i][j] == 'X') || (arr[i][j] == 'O'))
				boxesLeft--;
		}
	}
	return boxesLeft;
}