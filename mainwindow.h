#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include<time.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int grid[100][100];
        int nextGen[500][500];
        int row,column;
        int Acount =0;
        int i=0;
        int flag=0;

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void delay();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
