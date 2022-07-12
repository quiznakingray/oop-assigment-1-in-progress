#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

// init
void drawingstart(int& turns, char data[6][6]);
void drawinggame(int& turns, char data[6][6]);
void boxturns(int& turns, bool& firstflipped, char matchtwo[6][6], char matchtwocharc[6][6]);
//void firstcardturn(bool& firstflipped, char matchtwo[6][6], char matchtwocharc[6][6]);
//void secondcardturn(int& TURNS, bool& firstflipped, char matchtwo[6][6], char matchtwocharc[6][6]);
int turns = 0;
bool firstflipped = false;
bool secondflipped = false;
bool gameend = false;
// array from the start that changes
char matchtwo[6][6] = { {'_', '_', '_', '_', '_', '_'}, {'_' , '_', '_', '_', '_', '_',}, {'_', '_', '_', '_', '_', '_'},
								{'_', '_', '_', '_', '_', '_'}, {'_' , '_', '_', '_', '_', '_',}, {'_', '_', '_', '_', '_', '_'} 
};
// fixed array with all the alpahbets
char matchtwocharc[6][6] = { {'a', 'b', 'c', 'd', 'e', 'f'}, {'g' , 'h', 'i', 'j', 'k', 'l',}, {'m', 'n', 'o', 'p', 'q', 'r'},
							{'a', 'b', 'c', 'd', 'e', 'f'}, {'g' , 'h', 'i', 'j', 'k', 'l',}, {'m', 'n', 'o', 'p', 'q', 'r'} 
};



int main(void)
{
	// randomising at alphabet array
	srand ((unsigned int)time(0));
	int h, i, j, k, temp;
	for (h = 0; h < 6; h++)
	{
		for (i = 0; i < 6; i++)
		{
			j = (rand() % 6);
			k = (rand() % 6);
			temp = matchtwocharc[h][i];
			matchtwocharc[h][i] = matchtwocharc[j][k];
		}

	}

	

	

	drawingstart(turns, matchtwo);
	while (gameend == false) // loop til no more '_'
	{
		boxturns(turns, firstflipped, matchtwo, matchtwocharc);

	}


	return 0;


	// alphabets (matchtwocharc): {a, a, b, b, c, c, d, d, e, e, f, f, g, g, h, h, i, i, j, j, k, k, l, l, m, m, n, n, o, o, p, p, q, q, r, r } 
	// make variable firstbox and secod box and allocate to the input
	// reveal firstbox after first input ad dispaly qns of second input
	// if firstbox == secondbox , remain the same 
	// if not, both card turn back / turn back into _ 
	// after second input , turn +=1 til all cards are open 
	// if no '_' then game end and then restart 




}
void drawingstart(int& turns, char data[6][6]) // UI at the start
{
	cout << "같같 Turn " << turns << " 같같" << endl;
	cout << "   1 | 2 | 3 | 4 | 5 | 6" << endl;
	for (int row = 0; row < 6; row++)
	{
		cout << (row + 1) << "| ";
		for (int col = 0; col < 6; col++)
		{
			cout << data[row][col] << "   ";

		}
		cout << endl << endl;
	}
}

void drawinggame(int& turns,char data[6][6])// UI during game
{
	system("CLS");
	drawingstart(turns, data);
}

void boxturns(int& turns, bool& firstflipped, char matchtwo[6][6], char matchtwocharc[6][6])
{
	int firstboxrow, firstboxcol;
	int secondboxrow, secondboxcol;
	while (firstflipped == false)
	{
		cout << endl << " Input your first box's row: ";
		cin >> firstboxrow;
		cout << endl << " Input your first box's column: ";
		cin >> firstboxcol;
		if (matchtwo[firstboxrow - 1][firstboxcol - 1] == '_')
		{
			matchtwo[firstboxrow - 1][firstboxcol - 1] = matchtwocharc[firstboxrow - 1][firstboxcol - 1];
			firstflipped = true;
			secondflipped = false;
			drawinggame(turns, matchtwo);

			break;
		}
		else
			system("CLS");
		drawinggame(turns, matchtwo);
		cout << "box is already flipped";
	}

	while (secondflipped == false)
	{
		cout << endl << " Input your second box's row: ";
		cin >> secondboxrow;
		cout << endl << " Input your second box's column: ";
		cin >> secondboxcol;
		if (matchtwo[secondboxrow - 1][secondboxcol - 1] == '_')
		{
			matchtwo[secondboxrow - 1][secondboxcol - 1] = matchtwocharc[secondboxrow - 1][secondboxcol - 1];
			turns += 1;
			drawinggame(turns, matchtwo);
			if (matchtwocharc[secondboxrow - 1][secondboxcol - 1] != matchtwocharc[firstboxrow - 1][firstboxcol - 1])
			{
				matchtwo[secondboxrow - 1][secondboxcol - 1] = '_';
				matchtwo[firstboxrow - 1][firstboxcol - 1] = '_';
				firstflipped = false;
				secondflipped = true;
			}
			else
				firstflipped = false;
				secondflipped = true;
				drawinggame(turns, matchtwo);
			break;


		}
		else
			system("CLS");
			drawinggame(turns, matchtwo);
			cout << "box is already flipped";
	}

}




