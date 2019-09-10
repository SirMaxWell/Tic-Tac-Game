// Max.Atkinson Tic Tac Toe Game 
/*-------------------------------------------------------------------------
File Name: Main.cpp
Purpose: allows two users to play Tic Tac Toe 
Author: Max.Atkinson
Modified: 02/25/19


---------------------------------------------------------------------------*/


#include <iostream>



// constant size of grid 
const int Grid_Size = 3;
// 2D Array 3x3
int Grid[Grid_Size][Grid_Size];

bool Player_One = true;



const int Empty = 0;
const int Cross = 1;
const int Knot = 2;


// what will be replaced when the user press a number on numpad = bacially the tiles
const char* X = "[X]";
const char* O = "[O]";
// represents the empty titles when the game is drawn 
const char* tile = "[  ]";
// functions
//draws board
void board();
// takes in user input
void input();
// will check the board to see if anyone has won
bool Check_Win(int turn);
// displays win text 
void Win_Text();
// displays draw text
void Draw_Text();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // just a double check to 
	int turns = 0;											// make sure no memory leaks happen.
	bool Game_Over = false;

	while (!Game_Over) {
		board();
		Check_Win(turns);

		if (Check_Win(turns) == true) {
			if (turns != 9) // if turns is not equal to 9 
			{
				Win_Text(); // do Win_Text
			}
			else			
			{
				Draw_Text(); // else do Draw_Text
			}
			Game_Over = true;
		}
		else {
			Game_Over = false;
			input();
			Player_One = !Player_One;
			turns += 1;
		}
	}

	/*while (Game_Over == false)
	{

		input();
		Check_Win(turns);
	}*/

	system("pause");

	/*std::cin.get();
	return 0;*/
}

void input()
{
	// gets the first useful number then clears the rest eg you input 1 2 3 , it will only use the first one 
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	//
	int player_tile = Cross;            // needs to be put above the code to know it exists "player_tile"

	if (Player_One) {
		player_tile = Cross;
	}
	else
	{
		player_tile = Knot;
	}
	// instructions and letting the player know what they are 
	if (Player_One)
	{
		std::cout << "Use the Numpad:" << std::endl << "You are Crosses" << std::endl;
	}
	else
	{
		std::cout << "Use the Numpad:" << std::endl << "Your are Knots" << std::endl;
	}




	int selectedtile;
	std::cin >> selectedtile;
	if (std::cin.fail()) {                            // if the information from user input is incorrect 
		std::cout << "That's not a Number!\n";		 // then the console says " That's not a Number! "
		system("pause");
		input();
	}
	else if (selectedtile > 9 || selectedtile < 1) {	// if they are outside 1 or 9 
		std::cout << "Number is outside of range, only use numbers from 1-9!\n"; // then the console says 
		system("pause");														// "Number is outside of range, 
		input();																// only use numbers from 1-9!"
	}
	/*
	--------------------------------------------------------
	 _______________________________
	 | 7 = 0,0 | 8 = 0,1 | 9 = 0,2 |
	 |---------|---------|---------|
	 | 4 = 1,0 | 5 = 1,1 | 6 = 1,2 |
	 |-----------------------------|
	 | 1 = 2,0 | 2 = 2,1 | 3 = 2,2 |
	 -------------------------------

	Diagram of numbers and positional coordinates
	--------------------------------------------------------
	*/

	switch (selectedtile)
	{
	case 1:
		if (Grid[2][0] == Empty) { // press the the number eg 1 then if it is empty 
			Grid[2][0] = player_tile; // will replace with players title
		}
		else
		{								// else if it is press again it will
			std::cout << "Tile has already been placed here\n"; // play this message 
			system("pause");
			input();
		}
		break;

	case 2:
		if (Grid[2][1] == Empty) {
			Grid[2][1] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 3:
		if (Grid[2][2] == Empty) {
			Grid[2][2] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 4:
		if (Grid[1][0] == Empty) {
			Grid[1][0] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 5:
		if (Grid[1][1] == Empty) {
			Grid[1][1] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 6:
		if (Grid[1][2] == Empty) {
			Grid[1][2] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 7:
		if (Grid[0][0] == Empty) {
			Grid[0][0] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 8:
		if (Grid[0][1] == Empty) {
			Grid[0][1] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	case 9:
		if (Grid[0][2] == Empty) {
			Grid[0][2] = player_tile;
		}
		else
		{
			std::cout << "Tile has already been placed here\n";
			system("pause");
			input();
		}
		break;
	}



}


void board()
{
	system("cls");
	std::cout << "\n\n\tTic Tac Toe\n\n"; // Title
	std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl << std::endl; // telling the user which 
	std::cout << std::endl;													// player has what tiles

	for (size_t y = 0; y < Grid_Size; y++) // y = 0,y will increase but is less than Grid_Size 
	{										// or it will not go over Grid_Size
		std::cout << std::endl;
		for (size_t x = 0; x < Grid_Size; x++) // same goes for x 
		{
			switch (Grid[y][x])
			{
			case Empty:
				std::cout << tile;
				break;
			case Cross:
				std::cout << X;
				break;
			case Knot:
				std::cout << O;
				break;
			}
		}
		std::cout << std::endl;
	}


}


bool Check_Win(int turn)
{	// each set of [][] represents a place on the board [0][1] = 7, 
	//if the condtions are meet, like three crosses in a row then will return true for int turn

	if (Grid[0][0] == Grid[0][1] && Grid[0][2] == Grid[0][0] && Grid[0][0] != Empty) {	// 7-8-9
		return true;
	}
	else if (Grid[1][0] == Grid[1][1] && Grid[1][2] == Grid[1][0] && Grid[1][0] != Empty) {	// 4-5-6
		return true;
	}
	else if (Grid[2][0] == Grid[2][1] && Grid[2][2] == Grid[2][0] && Grid[2][0] != Empty) {	 // 1-2-3
		return true;
	}
	else if (Grid[0][0] == Grid[1][0] //  7		--------------------------------------------------------					
		&& Grid[2][0] == Grid[0][0] //	  4		 _______________________________
		&& Grid[0][0] != Empty) { //	  1		 | 7 = 0,0 | 8 = 0,1 | 9 = 0,2 |
		return true;				//			 |---------|---------|---------|
	}								//			 | 4 = 1,0 | 5 = 1,1 | 6 = 1,2 |
	else if (Grid[0][1] == Grid[1][1] // 8		 |-----------------------------|
		&& Grid[2][1] == Grid[0][1] //   5		 | 1 = 2,0 | 2 = 2,1 | 3 = 2,2 |
		&& Grid[0][1] != Empty) { //     2		 -------------------------------
		return true;			//					Diagram of numbers and positional coordinates
	}							//
	else if (Grid[0][2] == Grid[1][2] // 9		--------------------------------------------------------	
		&& Grid[2][2] == Grid[0][2] //   6
		&& Grid[0][2] != Empty) { //     3
		return true;
	}
	else if (Grid[0][0] == Grid[1][1] // 7
		&& Grid[2][2] == Grid[0][0] //		5
		&& Grid[0][0] != Empty) { //			3
		return true;
	}
	else if (Grid[0][2] == Grid[1][1]
		&& Grid[2][0] == Grid[0][2]
		&& Grid[0][2] != Empty) {
		return true;
}





//checking for draw
if (turn == 9) {
	return true;
} else {
	return false;
}


}

/*
	--------------------------------------------------------
	 _______________________________
	 | 7 = 0,0 | 8 = 0,1 | 9 = 0,2 |
	 |---------|---------|---------|
	 | 4 = 1,0 | 5 = 1,1 | 6 = 1,2 |
	 |-----------------------------|
	 | 1 = 2,0 | 2 = 2,1 | 3 = 2,2 |
	 -------------------------------







	Diagram of numbers and positional coordinates
	--------------------------------------------------------
	*/

	// win pop up text
void Win_Text()
{
	Player_One = !Player_One;

	if (Player_One) {
		std::cout << "You win! crosses! \n";
	}
	else {
		std::cout << "You win! Knots! \n";
	}
}
// Draw pop up text
void Draw_Text()
{
	std::cout << "Oh shit it's a draw!\n";

}