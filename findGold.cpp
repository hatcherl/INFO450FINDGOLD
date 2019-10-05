#include <iostream>
using namespace std;


void message();
void gameBoard1();
void gameBoard2();
int const SIZE = 10;

int main()
{
	bool gameOver = false;
	int goldCount = 0;
	int bombCount = 0;
	int guesses = 5;

	message();

	char gameBoardArray[SIZE][SIZE]; //This is the array we're using to hold the characters such as G and B

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

	cout << "Lets get started!" << endl;
	
	do
	{
		int x, y;
		cout << "Please input your x-coordinate  ";
		cin >> x; // need to add cin.fail statements to make sure an exception doesn't happen
		cout << "Please input your y-coordiate  ";
		cin >> y;
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

	system("pause");
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

void gameBoard1() 
{

};

void gameBoard2() 
{

};

