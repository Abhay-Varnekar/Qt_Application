 #include "mainwindow.hpp"

 #include <QApplication>
 #include <QFont>
 #include <QFontMetrics>
 #include <QTime>
 
 /**
  * @class MainWindow
  * @brief The main window of the application.
  * 
  * This class defines the UI for the main window, including a header label,
  * a display label that changes its text when a button is clicked, and a status bar
  * that shows a message when the text changes. It is built using the Qt framework.
  */
 MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
     setWindowTitle(tr("Qt Application"));
     resize(400, 300);
     
     setupUi();
     initializeMessages();
 
     displayLabel->setText(messages[currentMessageIndex]);
 }
 
 /**
  * @brief Sets up the user interface components.
  * 
  * This method initializes the main window layout, header label, display label,
  * change message button, and status bar. It also connects the button's click event
  * to the onButtonClicked slot.
  */
 void MainWindow::setupUi() {
     centralWidget = new QWidget(this);
     setCentralWidget(centralWidget);
     
     mainLayout = new QVBoxLayout(centralWidget);
     mainLayout->setContentsMargins(20, 20, 20, 20);
     mainLayout->setSpacing(15);

     headerLabel = new QLabel(tr("Welcome to Qt Application"), centralWidget);
     QFont headerFont = headerLabel->font();
     headerFont.setPointSize(16);
     headerFont.setBold(true);
     headerLabel->setFont(headerFont);
     headerLabel->setAlignment(Qt::AlignCenter);
     mainLayout->addWidget(headerLabel);

     displayLabel = new QLabel(centralWidget);
     QFont displayFont = displayLabel->font();
     displayFont.setPointSize(12);
     displayLabel->setFont(displayFont);
     displayLabel->setAlignment(Qt::AlignCenter);
     displayLabel->setWordWrap(true);
     displayLabel->setMinimumHeight(100);
     
     displayLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
     displayLabel->setLineWidth(1);
     mainLayout->addWidget(displayLabel);
     
     mainLayout->addStretch();

     changeButton = new QPushButton(tr("Change Message"), centralWidget);
     changeButton->setMinimumHeight(40);
 
     connect(changeButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
     mainLayout->addWidget(changeButton);

     statusBar = new QStatusBar(this);
     setStatusBar(statusBar);

     statusTimer = new QTimer(this);
     statusTimer->setSingleShot(true);
     connect(statusTimer, &QTimer::timeout, this, &MainWindow::clearStatusMessage);
 }
 
 /**
  * @brief Initializes the collection of messages that can be displayed.
  * 
  * This method sets up a list of messages that will be shown when the button is clicked.
  */
 void MainWindow::initializeMessages() {
     messages = {
       tr("Hello! Click the button to see a new message."),
       tr("Qt is a powerful C++ framework for cross-platform development."),
       tr("This is a simple Qt application created in C++20 using the Meson build system."),
     };
 }
 
 /**
  * @brief Slot that handles button click events.
  * 
  * This slot changes the displayed message to the next one in the list, and updates
  * the status bar to show the time the message was changed. It also starts a timer
  * to clear the status message after 3 seconds.
  */
 void MainWindow::onButtonClicked() {
     currentMessageIndex = (currentMessageIndex + 1) % messages.size();
     
     displayLabel->setText(messages[currentMessageIndex]);
     
     statusTimer->start(3000);
 }
 
 /**
  * @brief Clears the status message from the status bar.
  * 
  * This method is called after the status timer times out, clearing the message
  * displayed in the status bar.
  */
 void MainWindow::clearStatusMessage() {
     statusBar->clearMessage();
 }
 