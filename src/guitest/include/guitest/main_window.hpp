/**
 * @file /include/guitest/main_window.hpp
 *
 * @brief Qt based gui for guitest.
 *
 * @date November 2010
 **/
#ifndef guitest_MAIN_WINDOW_H
#define guitest_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "imagesave_node.hpp"
#include "socketsend_node.hpp"
#include <QtWebKit/QWebView>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace guitest {

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

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
  void showSocketInitFailedMessage();
  void showSlamMap();
  void showWebMap();
  long num = 0;

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
  void on_button_connect_clicked(bool checked );
	void on_checkbox_use_environment_stateChanged(int state);

  // TODO HERE,ADD YOUR BUTTON
  void on_button_roscore_clicked(bool checked );
  void on_button_openCam_clicked(bool checked );

  void on_button_onestepSLAM_clicked(bool checked );
  void on_button_saveMap_clicked(bool checked);
  void on_button_loadMap_clicked(bool ckecked);
  void on_button_rviz_clicked(bool checked);

  void on_button_connect_turtlebot_clicked(bool checked);
  void on_button_gps_clicked(bool checked);
  void on_button_nav_clicked(bool checked);
  void on_button_speech_clicked(bool checked);


    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void displayCameraImageLabel();
    void mcnnResaultShow();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
  //TODO HERE ,INSTANTIATION YOUR NODE TO USE IN MAINWINDOW
  ImageSaveNode imagesavenode;
  SocketSendNode socketsendnode;
};

}  // namespace guitest



#endif // guitest_MAIN_WINDOW_H
