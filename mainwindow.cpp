#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <QProcess>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //load vicon image
    QPixmap pic("/home/bo/code/qt5_test/Vicon.png");
    int w = ui->label_vicon->width();
    int h = ui->label_vicon->height();
    ui->label_vicon->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    //load quad image
    QPixmap pic_quad("/home/bo/code/qt5_test/quad.png");
    int w_quad = ui->label_quad->width();
    int h_quad = ui->label_quad->height();
    ui->label_quad->setPixmap(pic_quad.scaled(w_quad,h_quad,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText("clicked");
    cout << "clicked." << endl;
//    QProcess builder;
//    builder.start("gnome-terminal", QStringList() << "source ~/catkin_ws/devel/setup.bash; roslaunch mavros mavros.launch");
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch mavros apm2.launch; echo Finished roslaunch mavros apm2.launch; bash\"");


}

