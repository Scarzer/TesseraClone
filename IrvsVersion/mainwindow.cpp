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

    a_openExample = new QAction(QIcon(":/"), tr("&Open Examples"), this);
    a_openExample->setShortcut(QKeySequence::Open);
    a_openExample->setStatusTip(tr("Select from a choice of examples"));

    a_loadProject = new QAction(QIcon(":/icons/file-load.png"), tr("&Load Project"),this);
    a_loadProject->setShortcut(QKeySequence("Ctrl+L"));
    a_loadProject->setStatusTip(tr("Load a former file"));

    a_saveProject = new QAction(QIcon(":/icons/file-save.png"), tr("&Save"),this);
    a_saveProject->setShortcut(QKeySequence::Save);
    a_saveProject->setStatusTip(tr("Save current file"));

    a_saveAsProject = new QAction(QIcon(":/"), tr("&Save As..."),this);
    a_saveAsProject->setShortcut(QKeySequence("Ctrl+Shift+S"));
    a_saveAsProject->setStatusTip(tr("Save current file as a different name"));

    a_savePalette = new QAction(QIcon(":/"), tr("&Save Palette"),this);
    a_savePalette->setShortcut(QKeySequence("Ctrl+Shift+P"));

    a_loadPalette = new QAction(QIcon(":/"), tr("&Load Palette"),this);
    a_loadPalette->setShortcut(QKeySequence("Ctrl+Shift+L"));

    a_exportPallet = new QAction(QIcon(":/"), tr("&Export"),this);
    a_exportPallet->setShortcut(QKeySequence("Ctrl+E"));

    a_quit = new QAction(QIcon(":/"), tr("&Quit"),this);
    a_quit->setShortcut(QKeySequence("Ctrl+Q"));

    // Edit Menu
    a_undo = new QAction(QIcon(":/"), tr("&Quit"),this);
    a_undo->setShortcut(QKeySequence("Ctrl+Q"));
}

void MainWindow::m_createMenus(){
    // File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(a_newProject);
    fileMenu->addAction(a_openExample);
    fileMenu->addAction(a_loadProject);
    fileMenu->addSeparator();
    fileMenu->addAction(a_saveProject);
    fileMenu->addAction(a_saveAsProject);
    fileMenu->addSeparator();
    fileMenu->addAction(a_savePalette);
    fileMenu->addAction(a_loadPalette);
    fileMenu->addSeparator();
    fileMenu->addAction(a_exportPallet);
    fileMenu->addSeparator();
    fileMenu->addAction(a_quit);

    // Edit Menu
    editMenu = menuBar()->addMenu(tr("&Edit"));


    // View Menu
    viewMenu = menuBar()->addMenu(tr("&View"));
}

void MainWindow::m_createStatusBar(){
}

void MainWindow::m_createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(a_newProject);
//    fileToolBar->addAction(a_openExample);
    fileToolBar->addAction(a_loadProject);
    fileToolBar->addAction(a_saveProject);
}
