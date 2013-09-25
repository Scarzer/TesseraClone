#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    m_createActions();
    m_createMenus();
    m_createStatusBar();
    m_createToolBars();
}

void MainWindow::closeEvent(QCloseEvent *event){

}

void MainWindow::m_createActions(){
    // File Menu
    a_newProject = new QAction(QIcon(":/icons/file-new.png"),tr("&New"),this);
    a_newProject->setShortcut((QKeySequence::New));
    a_newProject->setStatusTip(tr("Create a new file"));

    a_openExample = new QAction(QIcon(":/icons/file-load.png"), tr("&Open Examples"), this);
    a_openExample->setStatusTip(tr("Select from a choice of examples"));

    a_loadProject = new QAction(QIcon(":/icons/fine-load.png"), tr("&Load"),this);
    a_loadProject->setShortcut(QKeySequence::Open);
    a_loadProject->setStatusTip(tr("Load a former file"));

    a_saveProject;
    a_saveAsProject;

    a_savePalette;
    a_loadPalette;

    a_exportPallet;
    a_quit;
}

void MainWindow::m_createMenus(){
    // File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(a_newProject);
    fileMenu->addAction(a_openExample);
    fileMenu->addAction(a_loadProject);

    // Edit Menu
    editMenu = menuBar()->addMenu(tr("$Edit"));


    // View Menu
    viewMenu = menuBar()->addMenu(tr("$View"));
}

void MainWindow::m_createStatusBar(){
}

void MainWindow::m_createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(a_newProject);
    fileToolBar->addAction(a_openExample);
    fileToolBar->addAction(a_loadProject)
}
