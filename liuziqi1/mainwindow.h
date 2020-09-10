#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include<QFrame>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int a[21][21];  //储存棋子的位置
    int chuzi1,chuzi;  //出子先，当前出子的人
    int qir;      //棋子半径
    QPoint dian;//平面上的一个点,坐标基点

      const int geshu=20;     //格数
      const int gek=40;   //格子的宽度
      const int x=20,y=20;  //开始坐标

      void startset(int _chuqi1);     //开始绘制棋盘
      void chujie(int hang,  int lie);    //出界判定
      void clearqipan();   //清空棋盘
      virtual void paintEvent(QPaintEvent *);//绘图
      void painqipan(QPainter &q);    //绘制棋盘
      void painqizi(QPainter &q);   //绘制棋子
      void painback();

      //绘制棋子的坐标
      QPoint zhongxin(int hang,int lie);  //棋子的中心坐标
      QPoint zuoshang(int hang,int lie);   //棋子左上角到中心的距离，即左上角的大小
      QRect qizi(int hang,int lie);  //棋子所在的矩形
      bool dianzaiyuan(QPoint q1,int &hang,int &lie);  //判断像素点是否在棋子内

      bool judge(int hang, int lie);   //判断是否赢
      //void mousePressEvent(QMouseEvent *event);

      QPainter *paint;

     private slots:

};

#endif // MAINWINDOW_H
