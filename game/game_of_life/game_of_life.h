#ifndef GAME_OF_LIFE_H_INCLUDED
#define GAME_OF_LIFE_H_INCLUDED

class GameOfLife{
private:
    int w;
    int h;
    int min;//�����������Χϸ����������
    int max;//�����������Χϸ����������
    int step;//�濪ʼ�������Ĳ���
    char **now;
    char **pre;
    char **matrix1;//��ά����
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
