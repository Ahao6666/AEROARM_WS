/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/qt_joystick/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_joystick {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
  QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

  setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
  QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

  connect(ui.ComboBox_1,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
  connect(ui.ComboBox_2,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
  connect(ui.ComboBox_3,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
  connect(ui.ComboBox_4,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
  connect(ui.ComboBox_5,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
  connect(ui.ComboBox_6,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue_com()));
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
  close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked() {
  if ( !qnode.init() ) {
    showNoMasterMessage();
  } else {
    ui.button_connect->setEnabled(false);
  }
}

void MainWindow::get_value(){
    int Send_Data[6];
    switch(ui.ComboBox_1->currentIndex()){
      case 0:
        ui.lcdNumber_1->display(-1);
        Send_Data[0] = -1;
        break;
    case 1:
        ui.lcdNumber_1->display(0);
        Send_Data[0] = 0;
        break;
    case 2:
        ui.lcdNumber_1->display(1);
        Send_Data[0] = 1;
      break;
    default:
        qDebug()<<"mode error!";
    }
    switch(ui.ComboBox_2->currentIndex()){
      case 0:
        ui.lcdNumber_2->display(0);
        Send_Data[1] = 0;
        break;
      case 1:
        ui.lcdNumber_2->display(1);
        Send_Data[1] = 1;
        break;
      default:
        qDebug()<<"mode error!";
    }
    switch(ui.ComboBox_3->currentIndex()){
      case 0:
        ui.lcdNumber_3->display(-1);
        Send_Data[2] = -1;
        break;
    case 1:
        ui.lcdNumber_3->display(0);
        Send_Data[2] = 0;
        break;
    case 2:
        ui.lcdNumber_3->display(1);
        Send_Data[2] = 1;
        break;
    default:
        qDebug()<<"mode error!";
    }
    switch(ui.ComboBox_4->currentIndex()){
      case 0:
        ui.lcdNumber_4->display(0);
        Send_Data[3] = 0;
        break;
    case 1:
        ui.lcdNumber_4->display(1);
        Send_Data[3] = 1;
        break;
    default:
        qDebug()<<"mode error!";
    }
    switch(ui.ComboBox_5->currentIndex()){
      case 0:
      ui.lcdNumber_5->display(0);
      Send_Data[4] = 0;
        break;
    case 1:
      ui.lcdNumber_5->display(1);
      Send_Data[4] = 1;
        break;
    default:
        qDebug()<<"mode error!";
    }
    switch(ui.ComboBox_6->currentIndex()){
      case 0:
        ui.lcdNumber_6->display(0);
        Send_Data[5] = 0;

        break;
    case 1:
        ui.lcdNumber_6->display(1);
        Send_Data[5] = 1;
        break;
    default:
        qDebug()<<"mode error!";
    }

    qnode.Get_data(Send_Data);
  }

void MainWindow::SetValue_com(){
  get_value();
}

}  // namespace qt_joystick

