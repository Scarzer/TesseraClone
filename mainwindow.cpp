#include "mainwindow.h"
#include "Globals.h"

using namespace std;

MainWindow	*g_mainWindow = NULL;

MainWindow::MainWindow()
    : QMainWindow(),
           m_frameInput	 (NULL),
           m_frameOutput (NULL),
           m_framePalette(NULL),
           m_frameInfo	 (NULL),
           m_controlPanel(NULL)
           //m_tabPreview	 (NULL)
{

    // set g_mainWindow
    g_mainWindow = this;

    m_getTiles(tileMap, "/home/irv/Projects/TesseraClone/TileImages");
    m_createActions();
    m_createMenus();
    m_createCentralWidget();
    m_createToolBars();
    m_createStatusBar();

    //Setting window size.
    setMinimumSize  (600,400);
    resize          (800,500);
    setCentralWidget(w_cWindow);

}
// MainWindow::~MainWindow:
//
// Destructor. Save settings.
//
MainWindow::~MainWindow() {
}

/*void MainWindow::closeEvent(QCloseEvent *event){

}*/

void MainWindow::m_createActions(){
    // File Menu
    a_newProject = new QAction(QIcon(":/icons/file-new.png"),tr("&New"),this);
    a_newProject->setShortcut((QKeySequence::New));
    a_newProject->setStatusTip(tr("Create a new file"));
    connect(a_newProject, SIGNAL(triggered()), this, SLOT(s_newProject()));

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
  //  m_controlPanel   = new QWidget;

    w_cWindow   = new QWidget;
    w_tabs      = new QTabWidget(this);

    m_frameInput = new ImageWindow(this);
    m_frameOutput  = new OutputWindow(this);
    m_framePalette   = new QWidget();
    m_frameInfo      = new QWidget();
    //m_controlPanel   = new QWidget();

    w_tabs->setMinimumSize(QSize(300,200));
    w_tabs->addTab(m_frameInput, tr("Input"));
    w_tabs->addTab(m_frameOutput,tr("Output"));
    w_tabs->addTab(m_framePalette,tr("Palette"));
    w_tabs->addTab(m_frameInfo,tr("Info"));

  //  m_controlPanel->setMinimumSize(QSize(200,200));

    //Create contro panel
    m_controlPanel = new ControlPanel;
    m_controlPanel-> setMinimumSize(350, QSizePolicy::Expanding);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(w_tabs);
    mainLayout->addWidget(m_controlPanel);
    w_cWindow->setLayout(mainLayout);
    w_cWindow->show();
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


void
MainWindow::updateInputFrame()
{
    if(m_params.image().isNull()) {
        qDebug() << "Error: NULL image.";
        return;
    }
    m_frameInput->setImage(m_params.image());
}

void MainWindow::updateOutputFrame()
{
    if(m_params.image().isNull()) {
        qDebug() << "Error: NULL image.";
        return;
    }
    m_frameOutput->setImage(m_params.image());
}

TesseraParameters&
MainWindow::parameters()
{
    return m_params;
}

// Slot functions
void
MainWindow::s_newProject()
{
    // prompt for input filename
    QFileDialog dialog(this);

    // open the last known working directory
    if(!m_currentInDir.isEmpty())
        dialog.setDirectory(m_currentInDir);

    // display existing files and directories
    dialog.setFileMode(QFileDialog::ExistingFile);

    // invoke native file browser to select file
    QString sel("Images");
    QString file =  dialog.getOpenFileName(this,
                 "Open File", m_currentInDir,
                 "Images (*.jpg *.jpeg *.png *.bmp *.tiff *.tif);;"
                  "All files (*)", &sel);

    // no file selected.. return
    if(file.isNull())
        return;

    // update location of current directory
    m_currentInDir = QFileInfo(file).dir().absolutePath();

    // load input image
    QImage image = QImage(file);

    // check whether image could be read
    if(image.isNull()) {
        QMessageBox::critical(this,
                              "Error",
                              "Image could not be read",
                              QMessageBox::Ok);
        return;
    }
    m_params.reset();
    m_params.setOriginalImage(image);
    m_params.setImage(image);
    m_controlPanel->resetControls();
    updateInputFrame();
    updateOutputFrame();
}

void MainWindow::s_loadProject()	{}
void MainWindow::s_saveProject()	{}
void MainWindow::s_undo()		{}
void MainWindow::s_redo()		{}
void MainWindow::s_zoomIn()		{}
void MainWindow::s_zoomOut()		{}

void MainWindow::s_showInputTab()  {w_tabs->setCurrentIndex(0);}
void MainWindow::s_showOutputTab() {w_tabs->setCurrentIndex(1);}
void MainWindow::s_showPaletteTab(){w_tabs->setCurrentIndex(2);}
void MainWindow::s_showInfoTab()   {w_tabs->setCurrentIndex(3);}

void MainWindow::m_createStatusBar(){}

void MainWindow::m_getTiles(QMap<QRgb, Tile> tileMap, QString tileDir){
    QDir                        parentDir(tileDir);
    QFileInfoList               fileInfo;

    fileInfo = parentDir.entryInfoList();
    int fileInfoLen = fileInfo.length();

    for(int i = 0; i < fileInfoLen; i++){
        Tile tileImage (fileInfo[i].absoluteFilePath() );
        tileMap.insert(tileImage.colorKey(), tileImage);
    }
    QList<QRgb> keys = tileMap.keys();
    qDebug() << "Number of Keys: " << keys.length();
    qDebug() << "Number of Files: " << fileInfo.length();
}



