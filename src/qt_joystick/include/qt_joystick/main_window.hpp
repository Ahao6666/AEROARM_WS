/**
 * @file /include/qt_joystick/main_window.hpp
 *
 * @brief Qt based gui for qt_joystick.
 *
 * @date November 2010
 **/
#ifndef qt_joystick_MAIN_WINDOW_H
#define qt_joystick_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QMap>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qt_joystick {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
  void on_button_connect_clicked();
  void get_value();
  void SetValue_com();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

};

}  // namespace qt_joystick

#endif // qt_joystick_MAIN_WINDOW_H
