#include <QtGui>
#include <mainwindow.h>

MainWindow::MainWindow()
{
        m_createActions();
        m_createMenus();
        m_createCentralWidget();
}