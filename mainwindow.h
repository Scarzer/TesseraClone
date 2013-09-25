##ifndef MAINWINDOW_H
##define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow();
    
    private slots:
        void s_newFile();
        void s_open();
        bool s_save();
        bool s_saveAs();
    
    private:
        void m_createActions();
        void m_createMenus();
        void m_createCentralWidget();
        
        QMenu *fileMenu;
        QMenu *editMenu;
        QToolBar *fileToolBar;
        QToolBar *editToolBar;
        QAction *newAction;
        QAction *openAction;
        
}


#endif