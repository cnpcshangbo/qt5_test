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
    QPixmap pic("../Vicon.png");
    int w = ui->label_vicon->width();
    int h = ui->label_vicon->height();
    ui->label_vicon->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    //load quad image
    QPixmap pic_quad("../quad.png");
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

void MainWindow::on_pushButton_vicon_bridge_clicked()
{

    cout << "clicked vicon_bridge." << endl;

    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch vicon_bridge vicon.launch datastream_hostport:=\\\"131.151.8.114:801\\\"; echo Finished roslaunch mavros apm2.launch; bash\"");
}
void MainWindow::on_pushButton_vicon2mavros_clicked()
{
    cout << "vicon2mavros clicked." << endl;
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; rosrun vicon_to_mavros talker; echo Finished rosrun vicon_to_mavros talker; bash\"");
}
