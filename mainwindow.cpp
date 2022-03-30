#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <QProcess>
#include <string>
// #include <cstdlib>

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
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch mavros px4.launch fcu_url:=/dev/serial0:921600; echo Finished roslaunch mavros px4.launch fcu_url:=/dev/serial0:921600; bash\"");

}

void MainWindow::on_pushButton_vicon_bridge_clicked()
{

    cout << "clicked vicon_bridge." << endl;
    cout << ui->lineEdit_vicon->text().toStdString() << endl;
    string viconStart("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch vicon_bridge vicon.launch datastream_hostport:=\\\"");
    string viconIP(ui->lineEdit_vicon->text().toStdString());
    string viconEnd("\\\"; echo Finished roslaunch mavros apm2.launch; bash\"");
    string viconCmd = viconStart + viconIP + viconEnd;
    cout << viconCmd << endl;
    system(viconCmd.c_str());

    // system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch vicon_bridge vicon.launch datastream_hostport:=\\\"131.151.8.114:801\\\"; echo Finished roslaunch mavros apm2.launch; bash\"");
}
void MainWindow::on_pushButton_vicon2mavros_clicked()
{
    cout << "vicon2mavros clicked." << endl;
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; rosrun vicon_to_mavros talker; echo Finished rosrun vicon_to_mavros talker; bash\"");
}
void MainWindow::on_pushButton_mavros_clicked()
{
    cout << "mavros button clicked." << endl;
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; source ~/catkin_ws_mavros/devel/setup.bash; roslaunch mavros px4.launch fcu_url:=/dev/serial0:921600; echo Finished source ~/catkin_ws_mavros/devel/setup.bash; roslaunch mavros px4.launch fcu_url:=/dev/serial0:921600; bash\"");
}
void MainWindow::on_pushButton_girder_clicked()
{
    cout << "girder button clicked." << endl;
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; rosrun girder_detection section; echo Finished rosrun girder_detection section; bash\"");
}
void MainWindow::on_pushButton_horizontal_clicked()
{
    cout << "horizontal button clicked." << endl;
    system("gnome-terminal -x bash -c \". ~/catkin_ws/devel/setup.bash; roslaunch girder_detection horizontal.launch; echo Finished horizontal_controller; bash\"");
 
}

void MainWindow::on_pushButton_load_clicked()
{
    cout << "loaded config. " << endl;
}


void MainWindow::on_pushButton_save_clicked()
{
    cout << "saved config. " << endl;
}

