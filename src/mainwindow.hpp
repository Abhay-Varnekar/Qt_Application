 #ifndef MAINWINDOW_HPP
 #define MAINWINDOW_HPP
 
 #include <QMainWindow>
 #include <QLabel>
 #include <QPushButton>
 #include <QVBoxLayout>
 #include <QHBoxLayout>
 #include <QWidget>
 #include <QStatusBar>
 #include <QTimer>
 #include <QString>
 #include <vector>
 
 /**
  * @class MainWindow
  * @brief The main window of the application
  * 
  * This class implements the main UI window containing a label that
  * changes its text when a button is clicked.
  */
 class MainWindow : public QMainWindow {
     Q_OBJECT  
 
 public:
     explicit MainWindow(QWidget* parent = nullptr);
     
     ~MainWindow() override = default;
 
 private slots:
     void onButtonClicked();
     
     void clearStatusMessage();
 
 private:
     void setupUi();
     
     void initializeMessages();
 
     // UI Components
     QWidget* centralWidget;          
     QVBoxLayout* mainLayout;         
     QLabel* headerLabel;             
     QLabel* displayLabel;            
     QPushButton* changeButton;       
     QStatusBar* statusBar;            
     QTimer* statusTimer;             
     

     std::vector<QString> messages;    
     size_t currentMessageIndex = 0;  
 };
 
 #endif 
 