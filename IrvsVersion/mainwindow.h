#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    // Bunch of functions are going to go here!

private:
    void m_createActions();
    void m_createMenus();
    void m_createToolBars();
    void m_createStatusBar();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    // File Menu
    QAction *a_newProject;
    QAction *a_openExample;
    QAction *a_loadProject;
    // Seperate
    QAction *a_saveProject;
    QAction *a_saveAsProject;
    // Seperate
    QAction *a_savePalette;
    QAction *a_loadPalette;
    // Seperate
    QAction *a_exportPallet;
    QAction *a_quit;

    // Edit Menu
    QAction *a_undo;
    QAction *a_redo;
    // Seperate
    QAction *a_cut;
    QAction *a_copy;
    QAction *a_paste;
    QAction *a_fillSelection;
    QAction *a_blendTool;
    QAction *a_copyCurrentLayer;
    // Seperate
    QAction *a_resetAllParameters;
    // Seperate
    QAction *a_cropInput;
    QAction *a_cropOutput;

    // View Menu
    QAction *a_zoomIn;
    QAction *a_zoomOut;
    QAction *a_fitWindow;
    QAction *a_fullscreen;
    // Seperate
    QAction *a_toggleSections;
    QAction *a_showLayerManager;
    // Seperate
    QAction *a_input;
    QAction *a_output;
    QAction *a_palette;
    QAction *a_info;

    // Edit Toolbar
    QAction *a_pencil;
    QAction *a_eraser;
    QAction *a_fuzzySelect;
    QAction *a_byColorSelect;
    QAction *a_bucketFill;
    QAction *a_colorPicker;
    QAction *a_rectSelect;
    // Seperate
    QAction *a_noneIcon;
};

#endif // MAINWINDOW_H

