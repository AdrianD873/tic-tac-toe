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

    char inX;

    char *p_Array[3] = { A, B, C};



public:

    int move()
    {
        cout << turn << "'s turn (X,Y): ";
        cin >> inX >> y;

        if((int(inX) >= 49 && int(inX <= 51)) && (int(y) == 65 || int(y) == 66 || int(y) == 67))
        {
            x = int(inX) - 48;
            switch (y)
        {
            case 'A':
                if(int(A[x - 1]) == 32)
                {
                    A[x - 1] = turn;
                }
                else
                {
                    cout << "ungueltige Eingabe!" << endl;
                    return 1;
                }
                
                break;
            case 'B':
                if(int(B[x - 1]) == 32)
                    {
                        B[x - 1] = turn;
                    }    
                else
                {
                    cout << "ungueltige Eingabe!" << endl;
                    return 1;
                }            
                break;
            case 'C':
                if(int(C[x - 1]) == 32)
                {
                    C[x - 1] = turn;
                }
                else
                {
                    cout << "ungueltige Eingabe!" << endl;
                    return 1;
                }          
            default:
                break;
        }
        }
        else
        {
            cout << "fehlerhafte Eingabe!" <<endl;
            return 2;
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

        for(int i = 0; i  <= 2;)
        {
            if (A[0 + i] == turn2 && B[1] == turn2 && C[2 - i] == turn2)
            {
                return true;
            }
            i = i + 2;
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
        int x = 0;
        x = ticTacToe.move();
        if(x == 0)
        {
            ticTacToe.drawBoard();
        }
    }
    return 0;
}
