#include <iostream>
#include "game_of_life.h"
using namespace std;

int main()
{
    GameOfLife game(10,10);
    game.printNowMatrix();
    char ch;
    while(1)
    {
        cout<<"n(next step) s(set min and max) q(quit):";
        cin>>ch;
        if(ch=='q')
        {
            break;
        }
        switch(ch)
        {
        case 'n':
            game.next();
            game.printNowMatrix();
            break;
        case 's':
            cout<<"input min and max:";
            int min,max;
            cin>>min>>max;
            game.setBorder(min,max);
            break;
        default:
            break;
        }
    }

    return 0;
}
