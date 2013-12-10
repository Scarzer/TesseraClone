#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QMap>
#include "ControlPanel.h"
#include "ImageWindow.h"
#include "TesseraParameters.h"
#include "OutputWindow.h"
#include "Tile.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //! Constructor.
    MainWindow();

    TesseraParameters&	parameters		();
    void			updateInputFrame	();
    void            updateOutputFrame   (); //output window


    //! Destructor.
    ~MainWindow();

private slots:

    // slots
    void s_newProject	();
    void s_loadProject	();
    void s_saveProject	();
    void s_undo		();
    void s_redo		();
    void s_zoomIn		();
    void s_zoomOut		();
    void s_showInputTab	();
    void s_showOutputTab	();
    void s_showPaletteTab	();
    void s_showInfoTab	();

private:
    void m_createActions();
    void m_createMenus();
    void m_createControlPanel ();
    void createCentralWidget();
    void m_createCentralWidget();
    void m_createToolBars();
    void m_createStatusBar();
    void m_getTiles(const QMap<QRgb, Tile> tileMap, QString tileDir);

    QMap <QRgb, Tile> tileMap;


    QMenuBar *mainMenu;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *toolsMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    //Central Window
    QHBoxLayout     *mainLayout;
    QTabWidget      *w_tabs;
    QWidget         *w_cWindow;
    QWidget         *t_Input;
//    QWidget         *t_Output;
//    QWidget         *t_Palette;
//    QWidget         *t_Info;
//    ControlPanel    *p_control;
//    QWidget         *p_control;

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

    // Separate
    QAction *a_toggleSections;
    QAction *a_showLayerManager;

    // Separate
    QAction *a_input;
    QAction *a_output;
    QAction *a_palette;
    QAction *a_info;

    //Tools Menu
    QAction *a_pencilm;
    QAction *a_eraserm;
    QAction *a_fuzzeSelection;
    QAction *a_colorSelection;
    QAction *a_bucketFillm;
    QAction *a_colorPickerm;
    QAction *a_rectSelectm;
    QAction *a_noneIconm;

    //QAction *

    // Edit Toolbar
    QAction         *a_pencil;
    QAction         *a_eraser;
    QAction         *a_fuzzySelect;
    QAction         *a_byColorSelect;
    QAction         *a_bucketFill;
    QAction         *a_colorPicker;
    QAction         *a_rectSelect;

    // Seperate
    QAction         *a_noneIcon;

    // widgets
    ImageWindow		*m_frameInput;
    OutputWindow    *m_frameOutput;
    QWidget     	*m_framePalette;
    QWidget         *m_frameInfo;
    ControlPanel	*m_controlPanel;
//    QTabWidget		*m_tabPreview;

    // other stuff
    QString         m_currentInDir;
    TesseraParameters m_params;
};

#endif // MAINWINDOW_H

