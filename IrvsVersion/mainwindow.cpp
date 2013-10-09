#include <QtWidgets>
#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    m_createActions();
    m_createMenus();
    m_createCentralWidget();
    m_createToolBars();
    m_createStatusBar();

    //Setting window size.
    setMinimumSize  (400,300);
    resize          (600,400);
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

    // =========

    a_saveProject = new QAction(QIcon(":/icons/file-save.png"), tr("&Save"),this);
    a_saveProject->setShortcut(QKeySequence::Save);
    a_saveProject->setStatusTip(tr("Save current file"));

    a_saveAsProject = new QAction(QIcon(":/"), tr("Save &As..."),this);
    a_saveAsProject->setShortcut(QKeySequence("Ctrl+Shift+S"));
    a_saveAsProject->setStatusTip(tr("Save current file as a different name"));

    // =========

    a_savePalette = new QAction(QIcon(":/"), tr("Save &Palette"),this);
    a_savePalette->setShortcut(QKeySequence("Ctrl+Shift+P"));

    a_loadPalette = new QAction(QIcon(":/"), tr("Loa&d Palette"),this);
    a_loadPalette->setShortcut(QKeySequence("Ctrl+Shift+L"));

    // =========

    a_exportPallet = new QAction(QIcon(":/"), tr("&Export"),this);
    a_exportPallet->setShortcut(QKeySequence("Ctrl+E"));

    a_quit = new QAction(QIcon(":/"), tr("&Quit"),this);
    a_quit->setShortcut(QKeySequence("Ctrl+Q"));
    connect(a_quit, SIGNAL(triggered()), this, SLOT(close()));

    // Edit Menu
    a_undo = new QAction(QIcon(":/"), tr("&Undo"),this);
    a_undo->setShortcut(QKeySequence::Undo);

    a_redo = new QAction(QIcon(":/"), tr("&Redo"),this);
    a_redo->setShortcut(QKeySequence::Redo);

    // =========

    a_cut = new QAction(QIcon(":/"), tr("C&ut"),this);
    a_cut->setShortcut(QKeySequence::Cut);

    a_copy = new QAction(QIcon(":/"), tr("&Copy"),this);
    a_copy->setShortcut(QKeySequence::Copy);

    a_paste = new QAction(QIcon(":/"), tr("&Paste"),this);
    a_paste->setShortcut(QKeySequence::Paste);

    a_fillSelection = new QAction(QIcon(":/icons/tool-bucket-fill-22.png"), tr("F&ill Selection"),this);
    a_fillSelection->setShortcut(QKeySequence("Ctrl+I"));

    a_blendTool = new QAction(QIcon(":/"), tr("Blen&d Tool"),this);
    a_blendTool->setShortcut(QKeySequence("Ctrl+D"));

    a_copyCurrentLayer = new QAction(QIcon(":/"), tr("Cop&y Current Layer"),this);
    a_copyCurrentLayer->setShortcut(QKeySequence("Ctrl+Shift+C"));

    // =========

    a_resetAllParameters = new QAction(QIcon(":/"), tr("Reset &All Parameters"),this);
    a_resetAllParameters->setShortcut(QKeySequence("Ctrl+Shift+A"));

    a_cropInput = new QAction(QIcon(":/"), tr("Cr&op Input"),this);
    a_cropInput->setShortcut(QKeySequence("Ctrl+Shift+R"));

    a_cropOutput = new QAction(QIcon(":/"), tr("Crop Outpu&t"),this);
    a_cropOutput->setShortcut(QKeySequence("Ctrl+Shift+T"));


    // View Menu
    a_zoomIn = new QAction(QIcon(":/icons/view-zoomin.png"), tr("&Zoom In"),this);
    a_zoomIn->setShortcut(QKeySequence("Ctrl+="));

    a_zoomOut = new QAction(QIcon(":/icons/view-zoomout.png"), tr("Zoom &Out"),this);
    a_zoomOut->setShortcut(QKeySequence("Ctrl+-"));

    a_fitWindow = new QAction(QIcon(":/"), tr("Fit &Window"),this);
    a_fitWindow->setShortcut(QKeySequence("Ctrl+W"));

    a_fullscreen = new QAction(QIcon(":/"), tr("&Fullscreen"),this);
    a_fullscreen->setShortcut(QKeySequence("Ctrl+F"));

    // Seperate
    a_toggleSections = new QAction(QIcon(":/"), tr("Toggle &Sections"),this);
    a_toggleSections->setShortcut(QKeySequence("Ctrl+B"));

    a_showLayerManager = new QAction(QIcon(":/icons/view-layer-manager.png"), tr("Show Layer &Manager"),this);
    a_showLayerManager->setShortcut(QKeySequence("Ctrl+M"));

    // Seperate
    a_input = new QAction(QIcon(":/"), tr("&Input"),this);
    a_input->setShortcut(QKeySequence("1"));

    a_output = new QAction(QIcon(":/"), tr("O&utput"),this);
    a_output->setShortcut(QKeySequence("2"));

    a_palette = new QAction(QIcon(":/"), tr("&Palette"),this);
    a_palette->setShortcut(QKeySequence("3"));

    a_info = new QAction(QIcon(":/"), tr("I&nfo"),this);
    a_info->setShortcut(QKeySequence("4"));

    //Tools Menu

    a_pencilm = new QAction(QIcon(":/icons/tool-pencil-22.png"), tr("Pencil"),this);
    a_eraserm = new QAction(QIcon("://icons/tool-eraser-22.png"), tr("Eraser"), this);
    a_fuzzeSelection = new QAction(QIcon("://icons/tool-fuzzy-select-22.png"), tr("Fuzze Selection Tool"),this);
    a_colorSelection = new QAction(QIcon("://icons/tool-by-color-select-22.png"), tr("By Color Selection Tool"), this);
    a_bucketFillm = new QAction(QIcon("://icons/tool-bucket-fill-22.png"), tr("Bucket Fill"), this);
    a_colorPickerm = new QAction(QIcon("://icons/tool-color-picker-22.png"), tr("Color Picker"), this);
    a_rectSelectm = new QAction(QIcon("://icons/tool-rect-select-22.png"), tr("Rectangle Selection"), this);

    a_noneIconm = new QAction(QIcon("://icons/tool-none-icon.png"), tr("None"), this);


    // Edit Toolbar
    a_pencil = new QAction(QIcon(":/icons/tool-pencil-22.png"), tr("Pencil"),this);
    a_eraser = new QAction(QIcon(":/icons/tool-eraser-22.png"), tr("Eraser"),this);
    a_fuzzySelect = new QAction(QIcon(":/icons/tool-fuzzy-select-22.png"), tr("Fuzze Selection Tool"),this);
    a_byColorSelect = new QAction(QIcon(":/icons/tool-by-color-select-22.png"), tr("By Color Selection Tool"),this);
    a_bucketFill = new QAction(QIcon(":/icons/tool-bucket-fill-22.png"), tr("Bucket Fill"),this);
    a_colorPicker = new QAction(QIcon(":/icons/tool-color-picker-22.png"), tr("Color Picker"),this);
    a_rectSelect = new QAction(QIcon(":/icons/tool-rect-select-22.png"), tr("Rectangle Selection"),this);
    // Seperate
    a_noneIcon = new QAction(QIcon(":/icons/tool-none-icon.png"), tr("None"),this);
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
    editMenu->addAction(a_undo);
    editMenu->addAction(a_redo);
    editMenu->addSeparator();
    editMenu->addAction(a_cut);
    editMenu->addAction(a_copy);
    editMenu->addAction(a_paste);
    editMenu->addAction(a_fillSelection);
    editMenu->addAction(a_blendTool);
    editMenu->addAction(a_copyCurrentLayer);
    editMenu->addSeparator();
    editMenu->addAction(a_resetAllParameters);
    editMenu->addSeparator();
    editMenu->addAction(a_cropInput);
    editMenu->addAction(a_cropOutput);

    // View Menu
    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(a_zoomIn);
    viewMenu->addAction(a_zoomOut);
    viewMenu->addAction(a_fitWindow);
    viewMenu->addAction(a_fullscreen);
    viewMenu->addSeparator();
    viewMenu->addAction(a_toggleSections);
    viewMenu->addAction(a_showLayerManager);
    viewMenu->addSeparator();
    viewMenu->addAction(a_input);
    viewMenu->addAction(a_output);
    viewMenu->addAction(a_palette);
    viewMenu->addAction(a_info);

    //Tools Menu
    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(a_pencilm);
    toolsMenu->addAction(a_eraserm);
    toolsMenu->addAction(a_fuzzeSelection);
    toolsMenu->addAction(a_colorSelection);
    toolsMenu->addAction(a_bucketFillm);
    toolsMenu->addAction(a_colorPickerm);
    toolsMenu->addAction(a_rectSelectm);
    toolsMenu->addAction(a_noneIconm);
}

void MainWindow::m_createCentralWidget(){

    QTabWidget *tabs = new QTabWidget();

    QWidget *tabInput = new QWidget();
    QWidget *tabOutput = new QWidget();
    QWidget *tabPalette = new QWidget();
    QWidget *tabInfo = new QWidget();


    tabs->addTab(tabInput, "Input");
    tabs->addTab(tabOutput, "Output");
    tabs->addTab(tabPalette, "Palette");
    tabs->addTab(tabInfo, "Info");

    setCentralWidget(tabs);


/*    QTabWidget *m_tabPreview = new QTabWidget();
    m_tabPreview->setMinimumSize(512, 512);
    m_tabPreview->setContentsMargins(0, 0, 0, 0);
    m_tabPreview->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);
    QWidget *m_frameInput = new QWidget();
    QWidget *m_frameOutput = new QWidget();
    QWidget *m_framePalette = new QWidget();
    QWidget *m_frameInfo = new QWidget();
    m_tabPreview->addTab(m_frameInput, "Input");
    m_tabPreview->addTab(m_frameOutput, "Ouput");
    m_tabPreview->addTab(m_framePalette, "Palette");
    m_tabPreview->addTab(m_frameInfo, "Info");

    QWidget *m_controlPanel = new QWidget();
    m_controlPanel->setMinimumSize(300, QSizePolicy::Expanding);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(m_tabPreview);
    hbox->addWidget(m_controlPanel); */

}

void MainWindow::m_createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(a_newProject);
    fileToolBar->addAction(a_loadProject);
    fileToolBar->addAction(a_saveProject);

    fileToolBar = addToolBar(tr("Zooming Tools"));
    fileToolBar->addAction(a_zoomIn);
    fileToolBar->addAction(a_zoomOut);
    fileToolBar->addAction(a_showLayerManager);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(a_pencil);
    editToolBar->addAction(a_eraser);
    editToolBar->addAction(a_fuzzySelect);
    editToolBar->addAction(a_byColorSelect);
    editToolBar->addAction(a_bucketFill);
    editToolBar->addAction(a_colorPicker);
    editToolBar->addAction(a_rectSelect);
    editToolBar->addSeparator();

    editToolBar->addAction(a_noneIcon);
}

void MainWindow::m_createStatusBar(){
}
