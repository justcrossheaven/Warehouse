/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* Name: John Jia
   Username:cjia881
   ID:165529633
*/
#include "project.h"

/*
TimeWorked function takes 4 inputs: A's working time of minute part, A's working time of seconds part,
B's working time in minute part, B's working time in seconds part. The output is the absolute difference between two people's working time in seconds.
The algorithm is to simply convert the both people's working time to seconds and use bigger one subtract the smaller one.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int resultA, resultB;
	resultA = 60 * minuteA + secondA;
	resultB = 60 * minuteB + secondB;
	
	//Compare the length of time

	if (resultA >= resultB) {
		return resultA - resultB;
	}
	else {
		return resultB - resultA;
	}
}

/*
WarehouseAddress function takes an integer input which is greater than 2. It returns the largest prime number smaller than the input.
The algorithm is to start from the value of (input-1) and check whether it is a prime number by checking if it could not be exactly divided by integers from 2 to (input-1)/2.
If it is not a prime number, it decreases by 1 and then check until it finds a prime number.
*/
int WarehouseAddress(int maximum)
{
	int i = (maximum - 1);
	int j;
	int m = 2;

	// Consider the condition of the input being 3.
	if (i == 2) {
		return m;
	}

	//Check whether a number is prime number.
	int k = 1;
	while (i > 2) {
		k = 1;
		for (j = 2; j <= (i / 2); j++) {
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 1) {
			return i;
		}
		i--;
	}
}

/*
Advertise function takes a input of string. The function should modify the string and make every character in the string move
one position to the left, and the leftmost character join the right hand end of the string. 
The algorithm is to store the first character in the string and use a loop to put characters to their next array position. 
At last put the first stored character to the last position. 
*/
void Advertise(char *words)
{
	int n = strlen(words);
	int i;
	char first = words[0]; //Define the first character of the string
	for (i = 0; i < (n-1); i++) {
		words[i] = words[i + 1];
	}
	words[n - 1] = first;
}

/*
WinningBid function takes two inputs: An array contains at least one integer value and length of the array.
It returns the smallest unique (appears only once) value of the array. If there is no unique value, the function should return -1
The algorithm is to firstly find all unique values and then find the smallest value among them. 
*/
int WinningBid(int *values, int length)
{
	int newValues[100] = { 0 };
	int i, j, k;
	int test = 0;
	int index = 0;
	
	//Below is to find all the unique value in the array and store them in a new array named "newValues"
	for (i = 0; i < length; i++) {
		test = 0;
		for (j = 0; j < length; j++) {
			if (values[i] == values[j]) {
				test++;
			}
		}
		if (test == 1) {
			newValues[index] = values[i];
			index++;
		}
	}

	// Below is to find the smallest value of "newValues"
	int result = newValues[0];
	for (k = 0; k < index; k++) {
		if (newValues[k] < result) {
			result = newValues[k];
		}
	}
	if (result == 0) {
		return -1;
	}
	return result;
}

/*
BoxDesign function takes 3 inputs: An empty 1D string pointer array, the width of the box, and the height of the box.
It modifies the input string array representing it as a "box" by using "*" and denoting the center of the box with letter "X".
The algorithm is to find the position index of the edges by using width and height and use a loop to allocate "*" to them. 
Then consider all conditions that the width and height can be (even or odd number) and determine where to put "X" in the box.
*/
void BoxDesign(char *design, int width, int height)
{
	int i, j, k, m, n;

	//Below is to put "*" on the edge, " " on blank area, and "\n", new line character, at the end of each row.
	for (i = 0; i < width; i++) {
		design[i] = '*';
	}
	for (j = 1; j <= (height - 2); j++) {
		design[j * (width + 1)] = '*';
		design[(j + 1) * width + (j - 1)] = '*';
		for (k = (j * (width + 1) + 1); k < (width * (j + 1) + (j - 1)); k++) {
			design[k] = ' ';
		}
		
	}
	for (m = ((width + 1) * (height - 1)); m <= ((width - 1) + ((width + 1) * (height - 1))); m++) {
		design[m] = '*';
	}
	for (n = 0; n < height; n++) {
		design[(width + n * (width + 1))] = '\n';
	}

	//Below is to consider every possibility only when both height and width are greater than 2 to put "X"in the center.
	while (height > 2 && width > 2) {
		if ((height % 2) == 0 && (width % 2) != 0) {
			design[(width / 2) + ((height / 2) - 1) * (width + 1)] = 'X';
			design[(width / 2) + ((height / 2)) * (width + 1)] = 'X';
		}
		if ((height % 2) != 0 && (width % 2) != 0) {
			design[(width / 2) + ((height / 2)) * (width + 1)] = 'X';
		}
		if ((height % 2) != 0 && (width % 2) == 0) {
			design[(width / 2) + ((height / 2)) * (width + 1)] = 'X';
			design[((width / 2) - 1) + ((height / 2)) * (width + 1)] = 'X';
		}
		if ((height % 2) == 0 && (width % 2) == 0) {
			design[(width / 2) + ((height / 2)) * (width + 1)] = 'X';
			design[((width / 2) - 1) + ((height / 2)) * (width + 1)] = 'X';
			design[(width / 2) + ((height / 2) - 1) * (width + 1)] = 'X';
			design[((width / 2) - 1) + ((height / 2) - 1) * (width + 1)] = 'X';
		}
		break;
	}
}

/*
WorkerRoute function takes 1 input: A 10*10 array representing a warehouse. 1 represents worker and 2 represents the box. 
The function modifies the array and using 3 to represent the route from worker to the box. Assuming the worker moves horizontally first.
The algorithm is to consider every condition of the relative position between worker and the box and modify the correct path for each condition. 
*/
void WorkerRoute(int warehouse[10][10])
{
	int i, j;
	int Pos1r=0, Pos1c=0, Pos2r=0, Pos2c=0;

	//Below is to determine the position of the worker and box.
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				Pos1r = i;
				Pos1c = j;
			}
			if (warehouse[i][j] == 2) {
				Pos2c = j;
				Pos2r = i;
			}
		}
	}
	int rowdiff, coldiff;
	rowdiff = Pos1r - Pos2r;
	coldiff = Pos1c - Pos2c;
	int k1, k2, m1, m2, n1, n2, w1, w2;

	//Below is all conditions of relative positions of worker and box except for the conditions they are not on the same straigth line.
	if (rowdiff > 0 && coldiff > 0) {
		for (k2 = Pos2c; k2 < Pos1c; k2++) {
			warehouse[Pos1r][k2] = 3;
		}
		for (k1 = Pos2r+1; k1 < Pos1r; k1++) {
			warehouse[k1][Pos2c] = 3;
			}
		
	}
	if (rowdiff < 0 && coldiff < 0) {
		for (w2 = Pos1c + 1; w2 <= Pos2c; w2++) {
			warehouse[Pos1r][w2] = 3;
		}
		for (w1 = Pos1r; w1 < Pos2r; w1++) {
			warehouse[w1][Pos2c] = 3;
		}
	}
	if (rowdiff < 0 && coldiff > 0) {
		for (m2 = Pos2c; m2 < Pos1c; m2++) {
			warehouse[Pos1r][m2] = 3;
		}
		for (m1 = Pos1r+1; m1 < Pos2r; m1++) {
		    warehouse[m1][Pos2c] = 3;
		}
	}
	if (rowdiff > 0 && coldiff < 0) {
		for (n2 = Pos1c+1; n2 <= Pos2c; n2++) {
			warehouse[Pos1r][n2] = 3;
		}
		for (n1 = Pos2r+1; n1 < Pos1r; n1++) {
			warehouse[n1][Pos2c] = 3;
			}
		}

	//Below is all conditions that the worker and the box are on the same line.
	int s, q, e, r;
	while (rowdiff == 0) {
		if (coldiff > 0) {
			for (s = Pos2c + 1; s < Pos1c; s++) {
				warehouse[Pos1r][s] = 3;
			}
		}
		if (coldiff < 0) {
			for (q = Pos1c + 1; q < Pos2c; q++) {
				warehouse[Pos1r][q] = 3;
			}
		}
		break;
	}
	while (coldiff == 0) {
		if (rowdiff > 0) {
			for (e = Pos2r + 1; e < Pos1r; e++) {
				warehouse[e][Pos2c] = 3;
			}
		}
		if (rowdiff < 0) {
			for (r = Pos1r + 1; r < Pos2r; r++) {
				warehouse[r][Pos2c] = 3;
			}
		}
		break;
	}
}

/*
MakeMove function takes 2 inputs : A 10*10 warehouse reprensenting the game, and a character representing the movement.
It modifies the movement of worker after taking the movement and returns a boolean value indicating whether the goal of the game is reached.
The algorithm is to consider most of conditions of movement and use nested loop to modify them.
*/
int MakeMove(int warehouse[10][10], char move)
{
	//Below is to determine the position of the worker

	int i, j;
	int workerr=0, workerc=0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == WORKER || warehouse[i][j]==WORKER_ON_TARGET) {
				workerr = i;
				workerc = j;
			}
		}
	}

	int m = 0;    // row 
	int n = 0;    // col 
	int poboxr = 0;
	int poboxc = 0;

	//Below is to determine the change of position of worker and boxes for different movement.

	if (move == 'w') {
		m = -1, n = 0, poboxr = -1, poboxc = 0;
	}
	else if (move == 's') {
		m = 1, n = 0, poboxr = 1, poboxc = 0;
	}
	else if (move == 'a') {
		m = 0, n = -1, poboxr = 0, poboxc = -1;
	}
	else if (move == 'd') {
		m = 0, n = 1, poboxr = 0, poboxc = 1;
	}
	if (move != 'a' && move != 'd' && move != 'w' && move != 's') {
		return 0;
	}

	//Below is the condition when the worker is not on target.

	while ((move == 'a' || move == 'd' || move == 'w' || move == 's') && warehouse[workerr][workerc] == WORKER) {
		if (warehouse[workerr + m][workerc + n] == SPACE) {
			warehouse[workerr + m][workerc + n] = WORKER;
			warehouse[workerr][workerc] = SPACE;
		}
		else if (warehouse[workerr + m][workerc + n] == TARGET) {
			warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
			warehouse[workerr][workerc] = SPACE;
		}
		while (warehouse[workerr + m][workerc + n] == BOX) {
			if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == SPACE) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX;
				warehouse[workerr + m][workerc + n] = WORKER;
				warehouse[workerr][workerc] = SPACE;
			}
			else if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == TARGET) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX_ON_TARGET;
				warehouse[workerr + m][workerc + n] = WORKER;
				warehouse[workerr][workerc] = SPACE;
			}
			break;
		}
		while (warehouse[workerr + m][workerc + n] == BOX_ON_TARGET) {
			if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == SPACE) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX;
				warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
				warehouse[workerr][workerc] = SPACE;
			}
			else if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == TARGET) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX_ON_TARGET;
				warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
				warehouse[workerr][workerc] = SPACE;
			}
			break;
		}
		break;
	}

	//Below is the condition when the worker is on target.

	while ((move == 'a' || move == 'd' || move == 'w' || move == 's') && warehouse[workerr][workerc] == WORKER_ON_TARGET) {
		if (warehouse[workerr + m][workerc + n] == SPACE) {
			warehouse[workerr + m][workerc + n] = WORKER;
			warehouse[workerr][workerc] = TARGET;
		}
		else if (warehouse[workerr + m][workerc + n] == TARGET) {
			warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
			warehouse[workerr][workerc] = TARGET;
		}
		while (warehouse[workerr + m][workerc + n] == BOX) {
			if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == SPACE) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX;
				warehouse[workerr + m][workerc + n] = WORKER;
				warehouse[workerr][workerc] = TARGET;
			}
			else if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == TARGET) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX_ON_TARGET;
				warehouse[workerr + m][workerc + n] = WORKER;
				warehouse[workerr][workerc] = TARGET;
			}
			break;
		}
		while (warehouse[workerr + m][workerc + n] == BOX_ON_TARGET) {
			if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == SPACE) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX;
				warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
				warehouse[workerr][workerc] = TARGET;
			}
			else if (warehouse[workerr + m + poboxr][workerc + n + poboxc] == TARGET) {
				warehouse[workerr + m + poboxr][workerc + n + poboxc] = BOX_ON_TARGET;
				warehouse[workerr + m][workerc + n] = WORKER_ON_TARGET;
				warehouse[workerr][workerc] = TARGET;
			}
			break;
		}
		break;
	}

	//Below is to check whether the goal is reached.
	int q, p;
	for (q = 0; q < 10; q++) {
		for (p = 0; p < 10; p++) {
			if ((warehouse[q][p] == WORKER) || warehouse[q][p] == BOX) {
				return 0;
			}
		}
	}
	return 1;
}

