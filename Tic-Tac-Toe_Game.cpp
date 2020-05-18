// Gal Kolberg ID:206097925
// Building a tic-tac-toe game

#include <iostream>
using namespace std;

struct Board 
{ // Building a struct for the board
	char A1=' ', A2=' ', A3=' ', B1=' ', B2=' ', B3=' ', C1=' ', C2=' ', C3=' ';
};
// Declaring the functions now for more readble code
void PrintBoard(struct Board B, bool xTurn); 
char IsRowValid(char Row);
char IsColValid(char Col);
struct Board SettingTheCell(struct Board B, char Row, char Col, char Sign);
char IsCellTaken(char Col, int a, int b);
char GetSign(bool xTurn);
bool EndGame(struct Board B, char Sign);
int NumPlayer(bool xTurn);
bool IsTie(struct Board B);
struct Board CleanBoard(struct Board B);

int main()
{
	Board B;
	bool Finish = false, Replay = true, xTurn = true;
	char Row, Col, Again;
	while (Replay)
	{ // Doing while here if you want to check the code again without exiting
		while (!Finish)
		{ // Printing the moves of the players until the game's end
			PrintBoard(B, xTurn);
			cin >> Row;
			Row = IsRowValid(Row);
			cin >> Col;
			Col = IsColValid(Col);
			B = SettingTheCell(B, Row, Col, GetSign(xTurn));
			if (EndGame(B, GetSign(xTurn)))
			{ // Checking if the game end
				Finish = true;
				cout << "Player number " << NumPlayer(xTurn) << " (" << GetSign(xTurn) << ") WON!!!" << endl;
			}
			else
			{ // Or if it's a tie
				if (IsTie(B))
					Finish = true;
			}
			xTurn = !xTurn;
		}
		cout << "You want to play again? choose y/n" << endl;
		cin >> Again;
		if (Again == 'n')
		{
			Replay = false;
		}
		else
		{
			Replay = true;
			B = CleanBoard(B);
			xTurn = true;
		}
	}
	return 0;
}

void PrintBoard(struct Board B, bool xTurn)
{ // Printing the status of the struct right now
	cout << "  " << "1" << " 2" << " 3" << endl;
	cout << "A " << B.A1 << " " << B.A2 << " " << B.A3 << endl;
	cout << "B " << B.B1 << " " << B.B2 << " " << B.B3 << endl;
	cout << "C " << B.C1 << " " << B.C2 << " " << B.C3 << endl;
	cout << "Player number " << NumPlayer(xTurn) << " (" << GetSign(xTurn) << ")" << endl;
	cout << "Please enter a cell input (for example A1)" << endl;
}

char IsRowValid(char Row)
{
	while (Row != 'A' && Row != 'B' && Row != 'C')
	{ // Checking if the input to the row is valid
		cout << "You entered worng row, please try again( A / B / C)" << endl;
		cin >> Row;
	}
	return Row;
}

char IsColValid(char Col)
{
	while (Col != '1' && Col != '2' && Col != '3')
	{ // Checking if the input to the column is valid
		cout << "You entered worng column, please try again( 1 / 2 / 3)" << endl;
		cin >> Col;
	}
	return Col;
}

char IsCellTaken(char Col, int a, int b)
{ // Checking if the input for the cell is correct
	while (!(Col == a || Col == b))
	{
		cout << "The cell you chose is already taken, please choose different column" << endl;
		cin >> Col;
	}
	return Col;
}

struct Board SettingTheCell(struct Board B, char Row, char Col, char Sign)
{ // Setting the desirable cell
	switch (Row)
	{ // Checking which row is chosen
	case 'A':
	{
		switch (Col)
		{ // Checking which column is chosen
		case '1':
			if (B.A1 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 2, 3), Sign);
			else
				B.A1 = Sign;
			break;
		case '2':
			if (B.A2 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 3), Sign);
			else
				B.A2 = Sign;
			break;
		case '3':
			if (B.A3 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 2), Sign);
			else
				B.A3 = Sign;
			break;
		default:
			break;
		}
	}
	break;
	case 'B':
	{
		switch (Col)
		{ // Checking which column is chosen
		case '1':
			if (B.B1 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 2, 3), Sign);
			else
				B.B1 = Sign;
			break;
		case '2':
			if (B.B2 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 3), Sign);
			else
				B.B2 = Sign;
			break;
		case '3':
			if (B.B3 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 2), Sign);
			else
				B.B3 = Sign;
			break;
		default:
			break;
		}
	}
	break;
	case 'C':
	{
		switch (Col)
		{ // Checking which column is chosen
		case '1':
			if (B.C1 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 2, 3), Sign);
			else
				B.C1 = Sign;
			break;
		case '2':
			if (B.C2 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 3), Sign);
			else
				B.C2 = Sign;
			break;
		case '3':
			if (B.C3 != ' ') // Checking if the cell is already taken
				SettingTheCell(B, Row, IsCellTaken(Col, 1, 2), Sign);
			else
				B.C3 = Sign;
			break;
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
	return B;
}

char GetSign(bool xTurn)
{ // Changing the value for the sign for each call of this function
	if (xTurn)
		return 'X';
	return 'O';
}

bool EndGame(struct Board B, char Sign)
{ // Checking all the winning possibilities 
	if (Sign == B.A1 && Sign == B.A2 && Sign == B.A3)
		return true; // If all of the first row have the same sign
	if (Sign == B.B1 && Sign == B.B2 && Sign == B.B3)
		return true; // If all of the second row have the same sign
	if (Sign == B.C1 && Sign == B.C2 && Sign == B.C3)
		return true; // If all of the third row have the same sign
	if (Sign == B.A1 && Sign == B.B1 && Sign == B.C1)
		return true; // If all of the first column have the same sign
	if (Sign == B.A2 && Sign == B.B2 && Sign == B.C2)
		return true; // If all of the second column have the same sign
	if (Sign == B.A3 && Sign == B.B3 && Sign == B.C3)
		return true; // If all of the third column have the same sign
	if (Sign == B.A1 && Sign == B.B2 && Sign == B.C3)
		return true; // If one of the diagonal line have the same sign
	if (Sign == B.A3 && Sign == B.B2 && Sign == B.C1)
		return true; // If the second diagonal line have the same sign
	return false;
}

int NumPlayer(bool xTurn)
{ // Changing the number of the player each call of the function
	if (xTurn)
		return 1;
	return 2;
}

bool IsTie(struct Board B)
{ //Checking if all the board is full to decide if it's a tie
	if (B.A1 != ' ' && B.A2 != ' ' && B.A3 != ' ' && B.B1 != ' ' && B.B2 != ' ' && B.B3 != ' '  && B.C1 != ' '  && B.C2 != ' ' && B.C3 != ' ')
	{
		cout << "It's a tie!" << endl;
		return true;
	}
	return false;
}

struct Board CleanBoard(struct Board B)
{ // Cleaning the board for the next round
	B.A1 = ' ';
	B.A2 = ' ';
	B.A3 = ' ';
	B.B1 = ' ';
	B.B2 = ' ';
	B.B3 = ' ';
	B.C1 = ' ';
	B.C2 = ' ';
	B.C3 = ' ';
	return B;
}