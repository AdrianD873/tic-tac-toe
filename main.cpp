#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class ticTacToe
{
private:

    char A[4] = "   ";
    char B[4] = "   ";
    char C[4] = "   ";
    char turn = 'X';
    int x;
    char y;

    char *p_Array[3] = { A, B, C};



public:

    int move()
    {
        cout << turn << "'s turn (X,Y): ";
        cin >> x >> y;
        switch (y)
        {
            case 'A':
            A[x - 1] = turn;
                break;
            case 'B':
                B[x - 1] = turn;
                break;
            case 'C':
                C[x - 1] = turn;
            
            default:
                break;
        cout << A[0] << endl;
        }

        if(turn == 'X')
        {
            turn = 'O';
        }
        else
        {
            turn = 'X';
        }

        //returns the matchfield a player has chosen
        return 0;
    }

    bool winnDetection()
    {
        //detects if one player has won
        //returns an array: [winner, matchfield1, matchfield2, matchfield3]
        int winnindicator1 = 0;
        int winnindicator2 = 0;
        int winnindicator3 = 0;
        int winnindicator4 = 0;
        int winnindicator5 = 0;
        int winnindicator6 = 0;
        int winnindicator7 = 0;
        int winnindicator8 = 0;
        
        int *winnArayhori[3] = {&winnindicator1, &winnindicator2, &winnindicator3};
        int *winnArayvert[3] = {&winnindicator4, &winnindicator5, &winnindicator6};
        char turn2 = 'X';
        if(turn == 'X'){turn2 = 'O';}
        for(int i = 0; i < 4; i++)
        {
	    for (int j = 0; j < 3; j++)
		    if (p_Array[j][i] == turn2)
            {
                *winnArayhori[j] = *winnArayhori[j] + 1;
                *winnArayvert[i] = *winnArayvert[i] + 1;
            }
        }
        if(winnindicator1 == 3 || winnindicator2 == 3 || winnindicator3 == 3 || winnindicator4 == 3 || winnindicator5 == 3 || winnindicator6 == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void drawBoard()
    {
        // print the board to the console \xCD 
        cout << A[0] << "\xB3" << " "<< A[1] << " " << "\xB3" << A[2] << endl;
        cout << "\xC4" << "\xC5" << "\xC4\xC4\xC4" << "\xC5" << "\xC4" << endl;
        cout << B[0] << "\xB3" << " "<< B[1] << " " << "\xB3" << B[2] << endl;
        cout << "\xC4" << "\xC5" << "\xC4\xC4\xC4" << "\xC5" << "\xC4" << endl;
        cout << C[0] << "\xB3" << " " << C[1] << " " << "\xB3" << C[2] << endl;
    }
};

int main()
{
    ticTacToe ticTacToe;
    ticTacToe.drawBoard();
    while(ticTacToe.winnDetection() == false)
    {
        ticTacToe.move();
        ticTacToe.drawBoard();
    }
    return 0;
}
