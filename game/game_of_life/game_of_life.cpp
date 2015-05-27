#include "game_of_life.h"
#include <iostream>
#include <cstdlib>

GameOfLife::GameOfLife()
{
    w=22;
    h=22;
    min=2;
    max=3;
    step=0;
    init();
    pre=matrix1;
    now=matrix2;
}

GameOfLife::GameOfLife(int w,int h)
{
    this->w=w<=0?22:w+2;
    this->h=h<=0?22:h+2;
    min=2;
    max=3;
    step=0;
    init();
    pre=matrix1;
    now=matrix2;
}

void GameOfLife::init()
{
    matrix1=new char *[h];
    matrix2=new char *[h];
    for(int i=0;i<h;i++)
    {
        matrix1[i]=new char[w];
        matrix2[i]=new char[w];
    }
    matrix1[0][0]=matrix2[0][0]='/';
    for(int j=1;j<w-1;j++)
    {
        matrix1[0][j]=matrix2[0][j]='-';
    }
    matrix1[0][w-1]=matrix2[0][w-1]='\\';

    for(int i=1,j,num;i<h-1;i++)
    {
        matrix1[i][0]=matrix2[i][0]='|';
        matrix1[i][w-1]=matrix2[i][w-1]='|';
        for(j=1;j<w-1;j++)
        {
            num=rand();
            if(num%2==0) matrix1[i][j]=matrix2[i][j]=' ';
            else matrix1[i][j]=matrix2[i][j]='+';
        }
    }

    matrix1[h-1][0]=matrix2[h-1][0]='\\';
    for(int j=1;j<w-1;j++)
    {
        matrix1[h-1][j]=matrix2[h-1][j]='-';
    }
    matrix1[h-1][w-1]=matrix2[h-1][w-1]='/';
}
void GameOfLife::printNowMatrix()
{
    //system("cls");
    for(int i=0,j=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            std::cout<<now[i][j];
        }
        /*
        for(j=0; j<w; j++)
        {
            std::cout<<pre[i][j];
        }
        */
        std::cout<<std::endl;
    }
}
void GameOfLife::next()
{
    char **tmp=pre;
    pre=now;
    now=tmp;
    for(int i=1,j,count; i<h-1; i++)
    {
        for(j=1; j<w-1; j++)
        {
            count=0;
            if(pre[i-1][j-1]=='+')count++;
            if(pre[i-1][j]=='+')count++;
            if(pre[i-1][j+1]=='+')count++;
            if(pre[i][j-1]=='+')count++;
            if(pre[i][j+1]=='+')count++;
            if(pre[i+1][j-1]=='+')count++;
            if(pre[i+1][j]=='+')count++;
            if(pre[i+1][j+1]=='+')count++;
            if(count>=min&&count<=max)now[i][j]='+';
            else now[i][j]=' ';
        }
    }
    step++;
}

void GameOfLife::setBorder(int min,int max)
{
    this->min=min;
    this->max=max;
}
GameOfLife::~GameOfLife()
{
    for(int i=0;i<h;i++)
    {
        delete []matrix1[i];
        delete []matrix2[i];
    }
    delete []matrix1;
    delete []matrix2;
}
