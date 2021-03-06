/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_3;
    QFrame *frame_2;
    QLabel *label_cameraImg;
    QFrame *frame_3;
    QLabel *label_slammap;
    QListView *view_logging;
    QFrame *frame_4;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QDockWidget *dock_status;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkbox_use_environment;
    QLabel *label;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QLineEdit *line_edit_host;
    QLabel *label_3;
    QLineEdit *line_edit_topic;
    QCheckBox *checkbox_remember_settings;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_onestepSLAM;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_saveMap;
    QPushButton *button_loadMap;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *button_roscore;
    QPushButton *button_natapp;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *button_openCam;
    QPushButton *button_connect_turtlebot;
    QGroupBox *groupBox_4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_gps;
    QPushButton *button_speech;
    QPushButton *button_connect;
    QPushButton *button_nav;
    QGroupBox *groupBox_5;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *line_edit_mcnn;
    QPushButton *quit_button;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1173, 777);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowDesign->sizePolicy().hasHeightForWidth());
        MainWindowDesign->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_12 = new QGroupBox(centralwidget);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(groupBox_12);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_2 = new QFrame(groupBox_12);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_cameraImg = new QLabel(frame_2);
        label_cameraImg->setObjectName(QString::fromUtf8("label_cameraImg"));
        label_cameraImg->setGeometry(QRect(0, 0, 361, 331));
        label_cameraImg->setScaledContents(true);

        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);

        frame_3 = new QFrame(groupBox_12);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_slammap = new QLabel(frame_3);
        label_slammap->setObjectName(QString::fromUtf8("label_slammap"));
        label_slammap->setGeometry(QRect(0, 0, 361, 331));
        label_slammap->setScaledContents(true);

        gridLayout_3->addWidget(frame_3, 2, 0, 1, 1);

        view_logging = new QListView(groupBox_12);
        view_logging->setObjectName(QString::fromUtf8("view_logging"));
        sizePolicy.setHeightForWidth(view_logging->sizePolicy().hasHeightForWidth());
        view_logging->setSizePolicy(sizePolicy);
        view_logging->setMinimumSize(QSize(400, 300));
        view_logging->setMaximumSize(QSize(600, 600));

        gridLayout_3->addWidget(view_logging, 1, 1, 1, 1);

        frame_4 = new QFrame(groupBox_12);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(frame_4, 2, 1, 1, 1);


        hboxLayout->addWidget(groupBox_12);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1173, 19));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);
        dock_status = new QDockWidget(MainWindowDesign);
        dock_status->setObjectName(QString::fromUtf8("dock_status"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dock_status->sizePolicy().hasHeightForWidth());
        dock_status->setSizePolicy(sizePolicy2);
        dock_status->setMinimumSize(QSize(350, 560));
        dock_status->setMaximumSize(QSize(350, 524287));
        dock_status->setAllowedAreas(Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(dockWidgetContents_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkbox_use_environment = new QCheckBox(groupBox);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 6, 0, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_edit_master = new QLineEdit(groupBox);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(line_edit_master->sizePolicy().hasHeightForWidth());
        line_edit_master->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_edit_host = new QLineEdit(groupBox);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(line_edit_host->sizePolicy().hasHeightForWidth());
        line_edit_host->setSizePolicy(sizePolicy6);

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        line_edit_topic = new QLineEdit(groupBox);
        line_edit_topic->setObjectName(QString::fromUtf8("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        gridLayout->addWidget(line_edit_topic, 5, 0, 1, 3);

        checkbox_remember_settings = new QCheckBox(groupBox);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 7, 0, 1, 3);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 96));
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 271, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_onestepSLAM = new QPushButton(horizontalLayoutWidget);
        button_onestepSLAM->setObjectName(QString::fromUtf8("button_onestepSLAM"));
        sizePolicy.setHeightForWidth(button_onestepSLAM->sizePolicy().hasHeightForWidth());
        button_onestepSLAM->setSizePolicy(sizePolicy);
        button_onestepSLAM->setMinimumSize(QSize(80, 0));
        button_onestepSLAM->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(button_onestepSLAM);

        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 60, 271, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_saveMap = new QPushButton(horizontalLayoutWidget_2);
        button_saveMap->setObjectName(QString::fromUtf8("button_saveMap"));
        sizePolicy.setHeightForWidth(button_saveMap->sizePolicy().hasHeightForWidth());
        button_saveMap->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button_saveMap);

        button_loadMap = new QPushButton(horizontalLayoutWidget_2);
        button_loadMap->setObjectName(QString::fromUtf8("button_loadMap"));
        sizePolicy.setHeightForWidth(button_loadMap->sizePolicy().hasHeightForWidth());
        button_loadMap->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button_loadMap);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 93));
        horizontalLayoutWidget_6 = new QWidget(groupBox_3);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(20, 30, 271, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        button_roscore = new QPushButton(horizontalLayoutWidget_6);
        button_roscore->setObjectName(QString::fromUtf8("button_roscore"));
        sizePolicy.setHeightForWidth(button_roscore->sizePolicy().hasHeightForWidth());
        button_roscore->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(button_roscore);

        button_natapp = new QPushButton(horizontalLayoutWidget_6);
        button_natapp->setObjectName(QString::fromUtf8("button_natapp"));
        sizePolicy.setHeightForWidth(button_natapp->sizePolicy().hasHeightForWidth());
        button_natapp->setSizePolicy(sizePolicy);
        button_natapp->setMinimumSize(QSize(40, 0));

        horizontalLayout_6->addWidget(button_natapp);

        horizontalLayoutWidget_7 = new QWidget(groupBox_3);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(20, 60, 271, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        button_openCam = new QPushButton(horizontalLayoutWidget_7);
        button_openCam->setObjectName(QString::fromUtf8("button_openCam"));
        sizePolicy.setHeightForWidth(button_openCam->sizePolicy().hasHeightForWidth());
        button_openCam->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(button_openCam);

        button_connect_turtlebot = new QPushButton(horizontalLayoutWidget_7);
        button_connect_turtlebot->setObjectName(QString::fromUtf8("button_connect_turtlebot"));
        sizePolicy.setHeightForWidth(button_connect_turtlebot->sizePolicy().hasHeightForWidth());
        button_connect_turtlebot->setSizePolicy(sizePolicy);
        button_connect_turtlebot->setMinimumSize(QSize(40, 0));

        horizontalLayout_7->addWidget(button_connect_turtlebot);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 70));
        horizontalLayoutWidget_4 = new QWidget(groupBox_4);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(20, 30, 271, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        button_gps = new QPushButton(horizontalLayoutWidget_4);
        button_gps->setObjectName(QString::fromUtf8("button_gps"));
        sizePolicy.setHeightForWidth(button_gps->sizePolicy().hasHeightForWidth());
        button_gps->setSizePolicy(sizePolicy);
        button_gps->setMinimumSize(QSize(40, 0));

        horizontalLayout_4->addWidget(button_gps);

        button_speech = new QPushButton(horizontalLayoutWidget_4);
        button_speech->setObjectName(QString::fromUtf8("button_speech"));
        sizePolicy.setHeightForWidth(button_speech->sizePolicy().hasHeightForWidth());
        button_speech->setSizePolicy(sizePolicy);
        button_speech->setMinimumSize(QSize(40, 0));

        horizontalLayout_4->addWidget(button_speech);

        button_connect = new QPushButton(horizontalLayoutWidget_4);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        sizePolicy.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy);
        button_connect->setMinimumSize(QSize(30, 0));

        horizontalLayout_4->addWidget(button_connect);

        button_nav = new QPushButton(horizontalLayoutWidget_4);
        button_nav->setObjectName(QString::fromUtf8("button_nav"));
        sizePolicy.setHeightForWidth(button_nav->sizePolicy().hasHeightForWidth());
        button_nav->setSizePolicy(sizePolicy);
        button_nav->setMinimumSize(QSize(40, 0));
        button_nav->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(button_nav);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 70));
        horizontalLayoutWidget_5 = new QWidget(groupBox_5);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(19, 30, 271, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        line_edit_mcnn = new QLineEdit(horizontalLayoutWidget_5);
        line_edit_mcnn->setObjectName(QString::fromUtf8("line_edit_mcnn"));

        horizontalLayout_5->addWidget(line_edit_mcnn);


        verticalLayout_3->addWidget(groupBox_5);


        verticalLayout->addWidget(frame);

        quit_button = new QPushButton(dockWidgetContents_2);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        sizePolicy6.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy6);

        verticalLayout->addWidget(quit_button);

        dock_status->setWidget(dockWidgetContents_2);
        MainWindowDesign->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_status);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(quit_button, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindowDesign", "                                                                     \347\254\254\345\215\201\344\270\211\345\261\212\344\270\255\345\233\275\347\240\224\347\251\266\347\224\237\347\224\265\345\255\220\350\256\276\350\256\241\347\253\236\350\265\233\344\270\212\346\265\267\350\265\233\345\214\272", 0, QApplication::UnicodeUTF8));
        label_cameraImg->setText(QApplication::translate("MainWindowDesign", "\347\233\270\346\234\272\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        label_slammap->setText(QApplication::translate("MainWindowDesign", "slam\345\234\260\345\233\276\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
        dock_status->setWindowTitle(QApplication::translate("MainWindowDesign", "Command Panel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "ROS\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Use environment variables", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "ROS\347\275\221\347\273\234\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "ROS\343\200\200IP\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowDesign", "ROS\344\270\273\346\234\272\345\220\215", 0, QApplication::UnicodeUTF8));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", 0, QApplication::UnicodeUTF8));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings on startup", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "\346\211\213\345\212\250\345\234\260\345\233\276\346\236\204\345\273\272", 0, QApplication::UnicodeUTF8));
        button_onestepSLAM->setText(QApplication::translate("MainWindowDesign", "\345\220\257\345\212\250\346\277\200\345\205\211SLAM ", 0, QApplication::UnicodeUTF8));
        button_saveMap->setText(QApplication::translate("MainWindowDesign", "\344\277\235\345\255\230\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        button_loadMap->setText(QApplication::translate("MainWindowDesign", "\345\212\240\350\275\275\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindowDesign", "\345\210\235\345\247\213\345\214\226\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        button_roscore->setText(QApplication::translate("MainWindowDesign", "roscore", 0, QApplication::UnicodeUTF8));
        button_natapp->setText(QApplication::translate("MainWindowDesign", "\350\277\234\347\250\213\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        button_openCam->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200\347\233\270\346\234\272", 0, QApplication::UnicodeUTF8));
        button_connect_turtlebot->setText(QApplication::translate("MainWindowDesign", "\350\277\236\346\216\245\345\260\217\350\275\246", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindowDesign", "\345\257\274\350\210\252\344\270\216\350\257\255\351\237\263\344\272\272\346\234\272\344\272\244\344\272\222", 0, QApplication::UnicodeUTF8));
        button_gps->setText(QApplication::translate("MainWindowDesign", "GPS", 0, QApplication::UnicodeUTF8));
        button_speech->setText(QApplication::translate("MainWindowDesign", "\350\257\255\351\237\263\344\272\244\344\272\222", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "\345\274\202\345\270\270\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        button_nav->setText(QApplication::translate("MainWindowDesign", "\345\257\274\350\210\252", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindowDesign", "\345\234\272\346\231\257\345\274\202\345\270\270\346\243\200\346\265\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowDesign", "\345\234\272\346\231\257\344\272\272\346\225\260\347\273\237\350\256\241:", 0, QApplication::UnicodeUTF8));
        quit_button->setText(QApplication::translate("MainWindowDesign", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
