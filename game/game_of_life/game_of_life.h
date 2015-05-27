#ifndef GAME_OF_LIFE_H_INCLUDED
#define GAME_OF_LIFE_H_INCLUDED

class GameOfLife{
private:
    int w;
    int h;
    int min;//存活条件，周围细胞数的下限
    int max;//存活条件，周围细胞数的上限
    int step;//虫开始到结束的步数
    char **now;
    char **pre;
    char **matrix1;//二维矩阵
    char **matrix2;
public:
    GameOfLife();
    GameOfLife(int w,int h);
    ~GameOfLife();
    void printNowMatrix();
    void next();
    void setBorder(int min,int max);
private:
    void init();
};

#endif // GAME_OF_LIFE_H_INCLUDED
