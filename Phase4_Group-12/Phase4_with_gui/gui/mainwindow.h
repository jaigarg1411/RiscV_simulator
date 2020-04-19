#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "phase.h"
#include "highlighter.h"
#include <QMainWindow>

class QTextEdit;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Tab_tabBarClicked(int index);

    //void on_tabWidget_2_tabBarClicked(int index);

    void on_pushButton_step_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int time=0,tim2=0,tim3=0,stk=0;
    enum column{
        PC,MACHINE,ORIGINAL,BASIC
    };
    void setupEditor();

     QTextEdit *editor;
     Highlighter *highlighter;
};

#endif // MAINWINDOW_H
