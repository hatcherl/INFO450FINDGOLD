#include <iostream>
using namespace std;


void message();
void displayBoard();
void gameBoard();
int const SIZE = 10;

int main()
{
	bool gameOver = false;
	int goldCount = 0;
	int bombCount = 0;
	int guesses = 5;
	char response;
	
	displayBoard();

	cout << endl;

	do {
		message();

		char gameBoardArray[SIZE][SIZE] = { ' ' }; //This is the array we're using to hold the characters such as G and B
		// I also cleared the array out at declaration. When it loops, it'll clear again.
		// This is for the gold
		while (goldCount < 5)
		{
			int gold1 = (rand() % (SIZE - 2)) + 2; //Essentially says Choose a random number between 2-9
			int gold2 = (rand() % (SIZE - 2)) + 2; //Why 2-9? Because 0-1 are not functional game tiles. 
			//2-9 will be our "1-8" on the board. For clarification, we start counting at 0, so its 0-9.


			if (gameBoardArray[gold1][gold2] != 'G')
			{
				gameBoardArray[gold1][gold2] = 'G';
				goldCount++;
			}; // If gameBoardArray has a 'G' in that position, then it won't add a 'G' nor will it increment goldCount

		}

		//This is for the bombs
		while (bombCount < 1)
		{
			int bomb1 = (rand() % (SIZE - 2)) + 2; // Same logic as with the while statement above for the gold
			int bomb2 = (rand() % (SIZE - 2)) + 2;

			if (gameBoardArray[bomb1][bomb2] != 'G')
			{
				gameBoardArray[bomb1][bomb2] = 'B';
				bombCount++;
			}
		}

		cout << endl << "Lets get started!" << endl;

		do
		{
			int x, y;
			cout << "Please input your x-coordinate. Must be between 1-8  ";
			do {

				cin >> x; // need to add cin.fail statements to make sure an exception doesn't happen
				if (cin.fail())
				{
					do {
						cout << "Please choose a number." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> x;
					} while (cin.fail());
				}
			} while (x > (SIZE - 2) || x < 1);

			cout << "Please input your y-coordiate. Must be between 1-8  ";
			do {

				cin >> y;
				if (cin.fail())
				{
					do {
						cout << "Please choose a number." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> y;
					} while (cin.fail());
				}
			} while (x > (SIZE - 2) || x < 1);

			x++;
			y++;
			int goldAmount = 0;

			if (gameBoardArray[x][y] == 'G') //If gold is found the game doesn't take away a guess
			{
				gameBoardArray[x][y] = 'F';
				cout << endl << "You get an extra guess!" << endl;
				guesses++;
				goldAmount++;
				cout << "You currently have " << goldAmount << " gold" << endl;
				cout << "You also have " << guesses << " guesses" << endl;
			}
			else if (gameBoardArray[x][y] == 'B') //If bomb is found, the game ends
			{
				gameOver = true;
				cout << endl << "Uh-Oh. You've found a bomb! :(";
			}
			else //If neither of the above statements are true, then guesses increment
			{
				cout << "Nothing found!";
				guesses--;
				cout << "You currently have " << guesses << " guesses" << endl;
			}

		} while (guesses != 0 && gameOver == false);

		cout << "Please type in 'y' if you want to continue. If not type in any other character." << endl;
		cin >> response;

	} while (response == 'y' || response == 'Y');

	return 0;
};

//The Instructions of the game come from this function
void message()
{
	cout << "Hello! Welcome to Find Gold!" << endl << endl;
	cout << "Each tile has a chance to have a piece of gold or a bomb" << endl << endl;
	cout << "Your goal is to find as much gold as possible!" << endl << endl;
	cout << "You only have five guesses though!" << endl << endl;
	cout << "If you find gold, you get more chances!" << endl;

}; 

void displayBoard() 
{
	int countX = 1;//these are used to make sure they reset at end of each iteration of the game
	int countY = 1;

	/*The two for loops help build the display board
	What happens is that each if, else if, and else statement must will build specific parts of the board
	The X is setup so that it places in specific strings like "_".
	As each increment goes on it fills the board. X resets itself when y loops back and increments, thus starting the process
	over with Y=1, or whatever it increments to at that point. This allows certain conditions to be met to finish the board.
	*/
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			
			 if (x <= 1 && y <= 1)
			{
				cout << " ";
			}
			 else if (x <= SIZE && y == 0)
			 {
				 cout << countX++;
			 }
			 else if (x <= SIZE && y == 1)
			 {
				 cout << "_";
			 }
			 else if (x == 1 && y <= SIZE)
			 {
				 cout << "|";
			 }
			 else if (x == 0 && y <= SIZE)
			 {
				 cout << countY++;
			 }
			 else
			 {
				 cout << "?";
			 }

			cout << " ";
		}
		cout << endl;
	}
};

void gameBoard() 
{

};

