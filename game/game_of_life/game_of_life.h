#ifndef GAME_OF_LIFE_H_INCLUDED
#define GAME_OF_LIFE_H_INCLUDED

class GameOfLife{
private:
    char matrix[][];
public:
    GameOfLife();
    ~GameOfLife();
    void init();
    void next();
    void configure();

};

#endif // GAME_OF_LIFE_H_INCLUDED
