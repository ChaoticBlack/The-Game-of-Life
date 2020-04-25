#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if(flag==1)
    {
        for(row=0;row<500;row++)
                {
                    srand(time(NULL));
                    for(column=0;column<500;column++)
                    {
                        //srand(time(NULL));
                        int random = rand() % 2;
                        //cout<<random<<endl;
                        if(random == 1)
                            grid[row][column]=1;
                        else
                            grid[row][column]=0;
                    }

                }
      /*  for(row=0;row<500;row++)
                {
                    //srand(time(NULL));
                    for(column=0;column<500;column++)
                    {
                        //srand(time(NULL));
                       // int random = rand() % 2;
                        //cout<<random<<endl;
                       // if(random == 1)
                         //   grid[row][column]=1;
                        //else
                            grid[row][column]=0;
                    }

                }
        grid[100][100]=grid[101][100]=grid[100][101]=grid[200][100]=1;*/


        for(row=0;row<500;row++)
                {
                    for(column=0;column<500;column++)
                    {
                        nextGen[row][column]=grid[row][column];
                    }
                }

        for(row=0;row<500;row++)
                {
                    for(column=0;column<500;column++)
                    {
                       //cout<<grid[row][column];
                        if(grid[row][column]==1)
                        p.drawPoint(row+100,column+100);
                    }
                //cout<<endl;
                }
        flag=3;
        update();
    }
                //cout<<endl;
                //cout<<"nextGen IS "<<endl;
            /*for(row=0;row<10;row++)
                {
                    for(column=0;column<10;column++)
                    {
                        cout<<nextGen[row][column];
                    }
                cout<<endl;
                }
                cout<<endl;*/
        //for (i=0;i<1000;i++)
        if(flag==3)
            //while (1)
            {
                for(row=0;row<500;row++) //matrix traversal
                {
                    for(column=0;column<500;column++)
                    {
                        if(grid[row][column]==1) //if cell is alive
                        {
                            //if cell is alive then check neighboring 8 cells to find how many are alive

                            if(row-1>=0 && grid[row-1][column] == 1)
                            Acount++;
                            if(row-1>=0 && column+1<500 && grid[row-1][column+1] == 1)
                            Acount++;
                            if(column+1<500 && grid[row][column+1] == 1)
                            Acount++;
                            if(row+1<500 && column+1<500 && grid[row+1][column+1] == 1)
                            Acount++;
                            if(row+1<500 && grid[row+1][column] == 1)
                            Acount++;
                            if(row+1<500 && column-1>0 && grid[row+1][column-1] == 1)
                            Acount++;
                            if(column-1>=0 && grid[row][column-1] == 1)
                            Acount++;
                            if(row-1>=0 && column-1>=0 && grid[row-1][column-1] == 1)
                            Acount++;

                            //check game of life rules
                            if(Acount<2)
                            nextGen[row][column]=0;
                            else if (Acount==2 || Acount==3)
                            nextGen[row][column]=1;
                            else if (Acount>3)
                            nextGen[row][column]=0;
                            Acount=0;

                        }
                        if(grid[row][column]==0) //if cell is dead
                        {
                            //if cell is dead check neighboring 8 cells to find how many cells are alive

                            if(row-1>=0 && grid[row-1][column] == 1)
                            Acount++;
                            if(row-1>=0 && column+1<500 && grid[row-1][column+1] == 1)
                            Acount++;
                            if(column+1<500 && grid[row][column+1] == 1)
                            Acount++;
                            if(row+1<500 && column+1<500 && grid[row+1][column+1] == 1)
                            Acount++;
                            if(row+1<500 && grid[row+1][column] == 1)
                            Acount++;
                            if(row+1<500 && column-1>=0 && grid[row+1][column-1] == 1)
                            Acount++;
                            if(column-1>=0 && grid[row][column-1] == 1)
                            Acount++;
                            if(row-1>=0 && column-1>=0 && grid[row-1][column-1] == 1)
                            Acount++;

                            if(Acount==3)
                            {
                                nextGen[row][column]=1;
                            }
                            Acount=0;

                        }
                        //

                    }
                }
                //displaying the new grid
            for(row=0;row<500;row++)
                {
                    for(column=0;column<500;column++)
                    {
                        //cout<<nextGen[row][column];
                        if(nextGen[row][column]==1)
                        p.drawPoint(row+100,column+100);
                    }
                //cout<<endl;
                }
               // cout<<endl;
                //clrscr();
        //		clear();
        //		refresh();
                //shifting nextGen to grid
                //displaying the grid
            for(row=0;row<500;row++)
                {
                    for(column=0;column<500;column++)
                    {
                        grid[row][column]=nextGen[row][column];
                    }

                }
            for(row=0;row<500;row++)
                {
                    for(column=0;column<500;column++)
                    {
                        nextGen[row][column]=0;
                    }

                }
            delay();
            update();
            }


    if(flag==2)
    {
        for(row=0;row<10;row++)
            {
                for(column=0;column<10;column++)
                {
                    //nextGen[row][column]=0;
                    p.drawPoint(row+100,column+100);
                }

            }
    }

}
void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    flag=1;
    update();
}
