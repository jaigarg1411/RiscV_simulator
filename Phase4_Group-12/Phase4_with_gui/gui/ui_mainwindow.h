/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *Tab;
    QWidget *Editor;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit;
    QWidget *Simulator;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_step;
    QTabWidget *tabWidget_2;
    QWidget *Registers;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QLabel *x10;
    QLineEdit *val_x21;
    QLineEdit *val_x14;
    QLineEdit *val_x0;
    QLabel *x23;
    QLineEdit *val_x30;
    QLabel *x15;
    QLabel *x28;
    QLineEdit *val_x25;
    QLineEdit *val_x31;
    QLabel *x26;
    QLabel *x11;
    QLabel *x29;
    QLineEdit *val_x18;
    QLineEdit *val_x22;
    QLabel *x13;
    QLineEdit *val_x8;
    QLabel *x19;
    QLineEdit *val_x6;
    QLabel *x7;
    QLineEdit *val_x26;
    QLabel *x22;
    QLabel *x16;
    QLineEdit *val_x4;
    QLabel *x2;
    QLineEdit *val_x12;
    QLabel *x14;
    QLabel *x21;
    QLineEdit *val_x27;
    QLabel *x8;
    QLabel *x18;
    QLabel *x17;
    QLineEdit *val_x20;
    QLineEdit *val_x29;
    QLineEdit *val_x16;
    QLineEdit *val_x5;
    QLabel *x4;
    QLabel *x27;
    QLineEdit *val_x15;
    QLabel *x31;
    QLabel *x1;
    QLineEdit *val_x19;
    QLabel *x24;
    QLineEdit *val_x10;
    QLineEdit *val_x13;
    QLineEdit *val_x23;
    QLabel *x0;
    QLabel *x20;
    QLabel *x9;
    QLineEdit *val_x3;
    QLabel *x12;
    QLineEdit *val_x9;
    QLabel *x5;
    QLineEdit *val_x7;
    QLabel *x3;
    QLabel *x30;
    QLineEdit *val_x24;
    QLineEdit *val_x1;
    QLineEdit *val_x17;
    QLabel *x6;
    QLineEdit *val_x2;
    QLineEdit *val_x11;
    QLabel *x25;
    QLineEdit *val_x28;
    QWidget *Memory;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(520, 322);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Tab = new QTabWidget(centralWidget);
        Tab->setObjectName(QString::fromUtf8("Tab"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Tab->setFont(font);
        Editor = new QWidget();
        Editor->setObjectName(QString::fromUtf8("Editor"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        Editor->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(Editor);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textEdit = new QTextEdit(Editor);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font2;
        font2.setPointSize(16);
        textEdit->setFont(font2);

        verticalLayout_3->addWidget(textEdit);


        verticalLayout_4->addLayout(verticalLayout_3);

        Tab->addTab(Editor, QString());
        Simulator = new QWidget();
        Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->setEnabled(true);
        Simulator->setMouseTracking(true);
        Simulator->setTabletTracking(true);
        gridLayout_2 = new QGridLayout(Simulator);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_step = new QPushButton(Simulator);
        pushButton_step->setObjectName(QString::fromUtf8("pushButton_step"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_step->sizePolicy().hasHeightForWidth());
        pushButton_step->setSizePolicy(sizePolicy);
        pushButton_step->setFont(font);
        pushButton_step->setMouseTracking(true);

        gridLayout_2->addWidget(pushButton_step, 0, 1, 1, 1);

        tabWidget_2 = new QTabWidget(Simulator);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setFont(font);
        Registers = new QWidget();
        Registers->setObjectName(QString::fromUtf8("Registers"));
        Registers->setFont(font);
        Registers->setMouseTracking(true);
        Registers->setTabletTracking(true);
        Registers->setAutoFillBackground(false);
        verticalLayout_5 = new QVBoxLayout(Registers);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scrollArea = new QScrollArea(Registers);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 224, 840));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        x10 = new QLabel(scrollAreaWidgetContents);
        x10->setObjectName(QString::fromUtf8("x10"));

        gridLayout_4->addWidget(x10, 10, 0, 1, 1);

        val_x21 = new QLineEdit(scrollAreaWidgetContents);
        val_x21->setObjectName(QString::fromUtf8("val_x21"));

        gridLayout_4->addWidget(val_x21, 21, 1, 1, 1);

        val_x14 = new QLineEdit(scrollAreaWidgetContents);
        val_x14->setObjectName(QString::fromUtf8("val_x14"));

        gridLayout_4->addWidget(val_x14, 14, 1, 1, 1);

        val_x0 = new QLineEdit(scrollAreaWidgetContents);
        val_x0->setObjectName(QString::fromUtf8("val_x0"));

        gridLayout_4->addWidget(val_x0, 0, 1, 1, 1);

        x23 = new QLabel(scrollAreaWidgetContents);
        x23->setObjectName(QString::fromUtf8("x23"));

        gridLayout_4->addWidget(x23, 23, 0, 1, 1);

        val_x30 = new QLineEdit(scrollAreaWidgetContents);
        val_x30->setObjectName(QString::fromUtf8("val_x30"));

        gridLayout_4->addWidget(val_x30, 30, 1, 1, 1);

        x15 = new QLabel(scrollAreaWidgetContents);
        x15->setObjectName(QString::fromUtf8("x15"));

        gridLayout_4->addWidget(x15, 15, 0, 1, 1);

        x28 = new QLabel(scrollAreaWidgetContents);
        x28->setObjectName(QString::fromUtf8("x28"));

        gridLayout_4->addWidget(x28, 28, 0, 1, 1);

        val_x25 = new QLineEdit(scrollAreaWidgetContents);
        val_x25->setObjectName(QString::fromUtf8("val_x25"));

        gridLayout_4->addWidget(val_x25, 25, 1, 1, 1);

        val_x31 = new QLineEdit(scrollAreaWidgetContents);
        val_x31->setObjectName(QString::fromUtf8("val_x31"));

        gridLayout_4->addWidget(val_x31, 31, 1, 1, 1);

        x26 = new QLabel(scrollAreaWidgetContents);
        x26->setObjectName(QString::fromUtf8("x26"));

        gridLayout_4->addWidget(x26, 26, 0, 1, 1);

        x11 = new QLabel(scrollAreaWidgetContents);
        x11->setObjectName(QString::fromUtf8("x11"));

        gridLayout_4->addWidget(x11, 11, 0, 1, 1);

        x29 = new QLabel(scrollAreaWidgetContents);
        x29->setObjectName(QString::fromUtf8("x29"));

        gridLayout_4->addWidget(x29, 29, 0, 1, 1);

        val_x18 = new QLineEdit(scrollAreaWidgetContents);
        val_x18->setObjectName(QString::fromUtf8("val_x18"));

        gridLayout_4->addWidget(val_x18, 18, 1, 1, 1);

        val_x22 = new QLineEdit(scrollAreaWidgetContents);
        val_x22->setObjectName(QString::fromUtf8("val_x22"));

        gridLayout_4->addWidget(val_x22, 22, 1, 1, 1);

        x13 = new QLabel(scrollAreaWidgetContents);
        x13->setObjectName(QString::fromUtf8("x13"));

        gridLayout_4->addWidget(x13, 13, 0, 1, 1);

        val_x8 = new QLineEdit(scrollAreaWidgetContents);
        val_x8->setObjectName(QString::fromUtf8("val_x8"));

        gridLayout_4->addWidget(val_x8, 8, 1, 1, 1);

        x19 = new QLabel(scrollAreaWidgetContents);
        x19->setObjectName(QString::fromUtf8("x19"));

        gridLayout_4->addWidget(x19, 19, 0, 1, 1);

        val_x6 = new QLineEdit(scrollAreaWidgetContents);
        val_x6->setObjectName(QString::fromUtf8("val_x6"));

        gridLayout_4->addWidget(val_x6, 6, 1, 1, 1);

        x7 = new QLabel(scrollAreaWidgetContents);
        x7->setObjectName(QString::fromUtf8("x7"));

        gridLayout_4->addWidget(x7, 7, 0, 1, 1);

        val_x26 = new QLineEdit(scrollAreaWidgetContents);
        val_x26->setObjectName(QString::fromUtf8("val_x26"));

        gridLayout_4->addWidget(val_x26, 26, 1, 1, 1);

        x22 = new QLabel(scrollAreaWidgetContents);
        x22->setObjectName(QString::fromUtf8("x22"));

        gridLayout_4->addWidget(x22, 22, 0, 1, 1);

        x16 = new QLabel(scrollAreaWidgetContents);
        x16->setObjectName(QString::fromUtf8("x16"));

        gridLayout_4->addWidget(x16, 16, 0, 1, 1);

        val_x4 = new QLineEdit(scrollAreaWidgetContents);
        val_x4->setObjectName(QString::fromUtf8("val_x4"));

        gridLayout_4->addWidget(val_x4, 4, 1, 1, 1);

        x2 = new QLabel(scrollAreaWidgetContents);
        x2->setObjectName(QString::fromUtf8("x2"));

        gridLayout_4->addWidget(x2, 2, 0, 1, 1);

        val_x12 = new QLineEdit(scrollAreaWidgetContents);
        val_x12->setObjectName(QString::fromUtf8("val_x12"));

        gridLayout_4->addWidget(val_x12, 12, 1, 1, 1);

        x14 = new QLabel(scrollAreaWidgetContents);
        x14->setObjectName(QString::fromUtf8("x14"));

        gridLayout_4->addWidget(x14, 14, 0, 1, 1);

        x21 = new QLabel(scrollAreaWidgetContents);
        x21->setObjectName(QString::fromUtf8("x21"));

        gridLayout_4->addWidget(x21, 21, 0, 1, 1);

        val_x27 = new QLineEdit(scrollAreaWidgetContents);
        val_x27->setObjectName(QString::fromUtf8("val_x27"));

        gridLayout_4->addWidget(val_x27, 27, 1, 1, 1);

        x8 = new QLabel(scrollAreaWidgetContents);
        x8->setObjectName(QString::fromUtf8("x8"));

        gridLayout_4->addWidget(x8, 8, 0, 1, 1);

        x18 = new QLabel(scrollAreaWidgetContents);
        x18->setObjectName(QString::fromUtf8("x18"));

        gridLayout_4->addWidget(x18, 18, 0, 1, 1);

        x17 = new QLabel(scrollAreaWidgetContents);
        x17->setObjectName(QString::fromUtf8("x17"));

        gridLayout_4->addWidget(x17, 17, 0, 1, 1);

        val_x20 = new QLineEdit(scrollAreaWidgetContents);
        val_x20->setObjectName(QString::fromUtf8("val_x20"));

        gridLayout_4->addWidget(val_x20, 20, 1, 1, 1);

        val_x29 = new QLineEdit(scrollAreaWidgetContents);
        val_x29->setObjectName(QString::fromUtf8("val_x29"));

        gridLayout_4->addWidget(val_x29, 29, 1, 1, 1);

        val_x16 = new QLineEdit(scrollAreaWidgetContents);
        val_x16->setObjectName(QString::fromUtf8("val_x16"));

        gridLayout_4->addWidget(val_x16, 16, 1, 1, 1);

        val_x5 = new QLineEdit(scrollAreaWidgetContents);
        val_x5->setObjectName(QString::fromUtf8("val_x5"));

        gridLayout_4->addWidget(val_x5, 5, 1, 1, 1);

        x4 = new QLabel(scrollAreaWidgetContents);
        x4->setObjectName(QString::fromUtf8("x4"));

        gridLayout_4->addWidget(x4, 4, 0, 1, 1);

        x27 = new QLabel(scrollAreaWidgetContents);
        x27->setObjectName(QString::fromUtf8("x27"));

        gridLayout_4->addWidget(x27, 27, 0, 1, 1);

        val_x15 = new QLineEdit(scrollAreaWidgetContents);
        val_x15->setObjectName(QString::fromUtf8("val_x15"));

        gridLayout_4->addWidget(val_x15, 15, 1, 1, 1);

        x31 = new QLabel(scrollAreaWidgetContents);
        x31->setObjectName(QString::fromUtf8("x31"));

        gridLayout_4->addWidget(x31, 31, 0, 1, 1);

        x1 = new QLabel(scrollAreaWidgetContents);
        x1->setObjectName(QString::fromUtf8("x1"));

        gridLayout_4->addWidget(x1, 1, 0, 1, 1);

        val_x19 = new QLineEdit(scrollAreaWidgetContents);
        val_x19->setObjectName(QString::fromUtf8("val_x19"));

        gridLayout_4->addWidget(val_x19, 19, 1, 1, 1);

        x24 = new QLabel(scrollAreaWidgetContents);
        x24->setObjectName(QString::fromUtf8("x24"));

        gridLayout_4->addWidget(x24, 24, 0, 1, 1);

        val_x10 = new QLineEdit(scrollAreaWidgetContents);
        val_x10->setObjectName(QString::fromUtf8("val_x10"));

        gridLayout_4->addWidget(val_x10, 10, 1, 1, 1);

        val_x13 = new QLineEdit(scrollAreaWidgetContents);
        val_x13->setObjectName(QString::fromUtf8("val_x13"));

        gridLayout_4->addWidget(val_x13, 13, 1, 1, 1);

        val_x23 = new QLineEdit(scrollAreaWidgetContents);
        val_x23->setObjectName(QString::fromUtf8("val_x23"));

        gridLayout_4->addWidget(val_x23, 23, 1, 1, 1);

        x0 = new QLabel(scrollAreaWidgetContents);
        x0->setObjectName(QString::fromUtf8("x0"));

        gridLayout_4->addWidget(x0, 0, 0, 1, 1);

        x20 = new QLabel(scrollAreaWidgetContents);
        x20->setObjectName(QString::fromUtf8("x20"));

        gridLayout_4->addWidget(x20, 20, 0, 1, 1);

        x9 = new QLabel(scrollAreaWidgetContents);
        x9->setObjectName(QString::fromUtf8("x9"));

        gridLayout_4->addWidget(x9, 9, 0, 1, 1);

        val_x3 = new QLineEdit(scrollAreaWidgetContents);
        val_x3->setObjectName(QString::fromUtf8("val_x3"));

        gridLayout_4->addWidget(val_x3, 3, 1, 1, 1);

        x12 = new QLabel(scrollAreaWidgetContents);
        x12->setObjectName(QString::fromUtf8("x12"));

        gridLayout_4->addWidget(x12, 12, 0, 1, 1);

        val_x9 = new QLineEdit(scrollAreaWidgetContents);
        val_x9->setObjectName(QString::fromUtf8("val_x9"));

        gridLayout_4->addWidget(val_x9, 9, 1, 1, 1);

        x5 = new QLabel(scrollAreaWidgetContents);
        x5->setObjectName(QString::fromUtf8("x5"));

        gridLayout_4->addWidget(x5, 5, 0, 1, 1);

        val_x7 = new QLineEdit(scrollAreaWidgetContents);
        val_x7->setObjectName(QString::fromUtf8("val_x7"));

        gridLayout_4->addWidget(val_x7, 7, 1, 1, 1);

        x3 = new QLabel(scrollAreaWidgetContents);
        x3->setObjectName(QString::fromUtf8("x3"));

        gridLayout_4->addWidget(x3, 3, 0, 1, 1);

        x30 = new QLabel(scrollAreaWidgetContents);
        x30->setObjectName(QString::fromUtf8("x30"));

        gridLayout_4->addWidget(x30, 30, 0, 1, 1);

        val_x24 = new QLineEdit(scrollAreaWidgetContents);
        val_x24->setObjectName(QString::fromUtf8("val_x24"));

        gridLayout_4->addWidget(val_x24, 24, 1, 1, 1);

        val_x1 = new QLineEdit(scrollAreaWidgetContents);
        val_x1->setObjectName(QString::fromUtf8("val_x1"));

        gridLayout_4->addWidget(val_x1, 1, 1, 1, 1);

        val_x17 = new QLineEdit(scrollAreaWidgetContents);
        val_x17->setObjectName(QString::fromUtf8("val_x17"));

        gridLayout_4->addWidget(val_x17, 17, 1, 1, 1);

        x6 = new QLabel(scrollAreaWidgetContents);
        x6->setObjectName(QString::fromUtf8("x6"));

        gridLayout_4->addWidget(x6, 6, 0, 1, 1);

        val_x2 = new QLineEdit(scrollAreaWidgetContents);
        val_x2->setObjectName(QString::fromUtf8("val_x2"));

        gridLayout_4->addWidget(val_x2, 2, 1, 1, 1);

        val_x11 = new QLineEdit(scrollAreaWidgetContents);
        val_x11->setObjectName(QString::fromUtf8("val_x11"));

        gridLayout_4->addWidget(val_x11, 11, 1, 1, 1);

        x25 = new QLabel(scrollAreaWidgetContents);
        x25->setObjectName(QString::fromUtf8("x25"));

        gridLayout_4->addWidget(x25, 25, 0, 1, 1);

        val_x28 = new QLineEdit(scrollAreaWidgetContents);
        val_x28->setObjectName(QString::fromUtf8("val_x28"));

        gridLayout_4->addWidget(val_x28, 28, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        tabWidget_2->addTab(Registers, QString());
        Memory = new QWidget();
        Memory->setObjectName(QString::fromUtf8("Memory"));
        Memory->setMouseTracking(true);
        Memory->setTabletTracking(true);
        horizontalLayout = new QHBoxLayout(Memory);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget_2 = new QTableWidget(Memory);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        horizontalLayout->addWidget(tableWidget_2);

        tabWidget_2->addTab(Memory, QString());

        gridLayout_2->addWidget(tabWidget_2, 1, 1, 2, 1);

        pushButton_2 = new QPushButton(Simulator);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);

        tableWidget = new QTableWidget(Simulator);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout_2->addWidget(tableWidget, 2, 0, 1, 1);

        Tab->addTab(Simulator, QString());

        verticalLayout_2->addWidget(Tab);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        Tab->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", nullptr));
        Tab->setTabText(Tab->indexOf(Editor), QApplication::translate("MainWindow", "Editor", nullptr));
        pushButton_step->setText(QApplication::translate("MainWindow", "Stack-data trace", nullptr));
        x10->setText(QApplication::translate("MainWindow", "a0 (x10)", nullptr));
        x23->setText(QApplication::translate("MainWindow", "s7 (x23)", nullptr));
        x15->setText(QApplication::translate("MainWindow", "a5 (x15)", nullptr));
        x28->setText(QApplication::translate("MainWindow", "t3 (x28)", nullptr));
        x26->setText(QApplication::translate("MainWindow", "s10 (x26)", nullptr));
        x11->setText(QApplication::translate("MainWindow", "a1 (x11)", nullptr));
        x29->setText(QApplication::translate("MainWindow", "t4 (x29)", nullptr));
        x13->setText(QApplication::translate("MainWindow", "a3 (x13)", nullptr));
        x19->setText(QApplication::translate("MainWindow", "s3 (x19)", nullptr));
        x7->setText(QApplication::translate("MainWindow", "t2 (x7)", nullptr));
        x22->setText(QApplication::translate("MainWindow", "s6 (x22)", nullptr));
        x16->setText(QApplication::translate("MainWindow", "a6 (x16)", nullptr));
        x2->setText(QApplication::translate("MainWindow", "sp (x2)", nullptr));
        x14->setText(QApplication::translate("MainWindow", "a4 (x14)", nullptr));
        x21->setText(QApplication::translate("MainWindow", "s5 (x21)", nullptr));
        x8->setText(QApplication::translate("MainWindow", "s0 (x8)", nullptr));
        x18->setText(QApplication::translate("MainWindow", "s2 (x18)", nullptr));
        x17->setText(QApplication::translate("MainWindow", "a7 (x17)", nullptr));
        x4->setText(QApplication::translate("MainWindow", "tp (x4)", nullptr));
        x27->setText(QApplication::translate("MainWindow", "s11 (x27)", nullptr));
        x31->setText(QApplication::translate("MainWindow", "t6 (x31)", nullptr));
        x1->setText(QApplication::translate("MainWindow", "ra (x1)", nullptr));
        x24->setText(QApplication::translate("MainWindow", "s8 (x24)", nullptr));
        x0->setText(QApplication::translate("MainWindow", "x0", nullptr));
        x20->setText(QApplication::translate("MainWindow", "s4 (x20) ", nullptr));
        x9->setText(QApplication::translate("MainWindow", "s1 (x9)", nullptr));
        x12->setText(QApplication::translate("MainWindow", "a2 (x12)", nullptr));
        x5->setText(QApplication::translate("MainWindow", "t0 (x5)", nullptr));
        x3->setText(QApplication::translate("MainWindow", "gp (x3)", nullptr));
        x30->setText(QApplication::translate("MainWindow", "t5 (x30)", nullptr));
        x6->setText(QApplication::translate("MainWindow", "t1 (x6)", nullptr));
        x25->setText(QApplication::translate("MainWindow", "s9 (x25)", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Registers), QApplication::translate("MainWindow", "Registers", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "+0", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "+1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "+2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "+3", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Memory), QApplication::translate("MainWindow", "Memory", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Run", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "PC", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Machine_Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Basic_Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Original_Code", nullptr));
        Tab->setTabText(Tab->indexOf(Simulator), QApplication::translate("MainWindow", "Simulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
