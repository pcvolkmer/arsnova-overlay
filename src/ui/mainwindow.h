#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "version.h"
#include "ui_mainwindow.h"
#include "ui/splashscreen.h"
#include "qplugin/loginwidget.h"
#include "ui/qrcodewidget.h"
#include "ui/sessionwidget.h"
#include "ui/overlaywidget.h"
#include "sessioncontext.h"
#include "ui/systemtrayicon.h"

class MainWindow : public QMainWindow, Ui::MainWindow {
    Q_OBJECT

public:
    explicit MainWindow ( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    virtual ~MainWindow();
    const Ui::MainWindow * const getUi();
    void addWidget ( QString title, QWidget * widget );

private:
    Ui::MainWindow * ui;
    QSignalMapper * menuSignalMapper;
    QMap<QString, QWidget *> * widgetList;
    OverlayWidget * overlayWidget;
    SessionContext * sessionContext;

    void checkLeftMenuButton ( QString title );
    QWidget * findWidget ( QString widgetTitle );
    void connectLoginWidget();

    void disconnectAll();

private slots:
    void onSystemTrayActivated ( QSystemTrayIcon::ActivationReason reason );
    void activateWidget ( QString widgetTitle );
    void sessionLogin();
};

#endif // MAINWINDOW_H
