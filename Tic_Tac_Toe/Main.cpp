#include <iostream>
#include <string>

struct Position
{
	int x;
	int y;

	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};


Position getPosistionOnBoard(char letter)
{
	switch (letter)
	{
	case 'A': return Position(0, 0);
		break;
	case 'B': return Position(0, 1);
		break;
	case 'C': return Position(0, 2);
		break;
	case 'D': return Position(1, 0);
		break;
	case 'E': return Position(1, 1);
		break;
	case 'F': return Position(1, 2);
		break;
	case 'G': return Position(2, 0);
		break;
	case 'H': return Position(2, 1);
		break;
	case 'I': return Position(2, 2);
		break;
	}
}

void printNewBoard(int board[3][3])
{
	char letters[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	for (int i = 0; i < 9; i++)
	{
		Position pos = getPosistionOnBoard(letters[i]);
		if (board[pos.x][pos.y] == 1)
		{
			letters[i] = 'X';
		} 
		else if (board[pos.x][pos.y] == 2)
		{
			letters[i] = 'O';
		}
	}
	
	std::cout << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << "  " << letters[0] << " | " << letters[1] << " | " << letters[2] << " " << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << " ---+---+---" << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << "  " << letters[3] << " | " << letters[4] << " | " << letters[5] << " " << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << " ---+---+---" << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << "  " << letters[6] << " | " << letters[7] << " | " << letters[8] << " " << std::endl;
	std::cout << "    |   |   " << std::endl;
	std::cout << std::endl;
}

void processWinner(int player)
{
	std::cout << "Player " << player << " has won the game!" << std::endl;
}


int main()
{

	char MIN_SELECTION = 'A';
	char MAX_SELECTION = 'I';

	// Setup board
	int gameBoard[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = 0;
		}
	}

	// Start game
	bool gameOver = false;
	int playerCount = 0;
	char userInput;
	printNewBoard(gameBoard);
	while (!gameOver)
	{
		playerCount = (playerCount++) % 2;
		std::cout << "Player " << playerCount << "'s Turn: ";
		std::cin >> userInput;

		// Invalid input check
		while (userInput < MIN_SELECTION || userInput > MAX_SELECTION)
		{
			std::cout << "Please enter a valid posistion: ";
			std::cin >> userInput;
		}

		Position selectedPosition = getPosistionOnBoard(userInput);

		// Handle user selecting position that has already been used
		while (gameBoard[selectedPosition.x][selectedPosition.y] != 0)
		{
			std::cout << "Please enter an unused posistion: ";
			std::cin >> userInput;
			selectedPosition = getPosistionOnBoard(userInput);
		}

		// Set position to X or O
		gameBoard[selectedPosition.x][selectedPosition.y] = playerCount;


		// Check if anyones won

		if (gameBoard[0][0] != 0)
		{
			if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][0] == gameBoard[0][2])
			{
				// Win 1
				processWinner(gameBoard[0][0]);
				gameOver = true;
			}
			else if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[0][0] == gameBoard[2][0])
			{
				// Win 2
				processWinner(gameBoard[0][0]);
				gameOver = true;
			}
			else if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
			{
				// Win 3
				processWinner(gameBoard[0][0]);
				gameOver = true;
			}
		}
		else if (gameBoard[1][0] != 0 && (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][0] == gameBoard[1][2]))
		{
			// Win 4
			processWinner(gameBoard[1][0]);
			gameOver = true;
		}
		else if (gameBoard[2][0] != 0)
		{
			if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][0] == gameBoard[2][2])
			{
				// Win 5
				processWinner(gameBoard[2][0]);
				gameOver = true;
			}
			else if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[2][0] == gameBoard[0][2])
			{
				// Win 6
				processWinner(gameBoard[2][0]);
				gameOver = true;
			}
		}
		else if (gameBoard[2][1] != 0 && (gameBoard[2][1] == gameBoard[1][1] && gameBoard[2][1] == gameBoard[0][1]))
		{
			// Win 7
			processWinner(gameBoard[2][1]);
			gameOver = true;
		}
		else if (gameBoard[2][2] != 0 && (gameBoard[2][2] == gameBoard[1][2] && gameBoard[2][2] == gameBoard[0][2]))
		{
			// Win 8
			processWinner(gameBoard[2][2]);
			gameOver = true;
		}
		printNewBoard(gameBoard);
	}

	std::cout << "...";
	std::cin >> userInput;
}