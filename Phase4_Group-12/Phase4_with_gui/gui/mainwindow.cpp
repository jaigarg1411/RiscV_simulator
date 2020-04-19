#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidget>
#include<QDebug>
#include"phase.h"
#include "phase2.h"
#include<bits/stdc++.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupEditor();
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    editor = new QTextEdit;
    editor->setFont(font);

    highlighter = new Highlighter(editor->document());

}
MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_Tab_tabBarClicked(int index)
{
    if(index==1&&time==0)
     {
        QString filename="Original.txt";
        QFile file( filename );
        QString data = ui->textEdit->toPlainText();
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
         QTextStream out(&file);
            out<<data;
          file.close();
          phase1 pha;//run phase1
////////////////////////////PC-MACHINE CODE /////////////////////////////////////////
          vector<string> program_counter;
          vector<string> instructions_hexa;
          vector<string>original_code;
          vector<string>basic_code;
              string s1,s2,line;
              ifstream input("machine_code.txt");      // generated in phase1 as output
              while(input>>s1>>s2)
              {
                  if( (s1[0] == '\0') || (s2[0] == '\0') )
                      break;
                  program_counter.push_back(s1);
                  instructions_hexa.push_back(s2);
              }
              input.close();
              ifstream fpr("original_code_for_qt.txt",ios::in);
                  while ( getline (fpr,line) )
                  {
                      original_code.push_back(line);
                  }
                  fpr.close();
               ifstream fpr1("original_code_for_qt2.txt",ios::in);
                      while ( getline (fpr1,line) )
                      {
                          basic_code.push_back(line);
                      }
                      fpr1.close();
        for(int i=0;i<program_counter.size();i++)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            int val=ui->tableWidget->rowCount()-1;
            ui->tableWidget->setItem(val,PC,new QTableWidgetItem(QString::fromStdString(program_counter[i])));
            ui->tableWidget->setItem(val,MACHINE,new QTableWidgetItem(QString::fromStdString(instructions_hexa[i])));
            ui->tableWidget->setItem(val,ORIGINAL,new QTableWidgetItem(QString::fromStdString(original_code[i])));
            ui->tableWidget->setItem(val,BASIC,new QTableWidgetItem(QString::fromStdString(basic_code[i])));
        }
        time++;
        ui->val_x0->setText("0");
        ui->val_x1->setText("0");
        ui->val_x2->setText("0");
        ui->val_x3->setText("0");
        ui->val_x4->setText("0");
        ui->val_x5->setText("0");
        ui->val_x6->setText("0");
        ui->val_x7->setText("0");
        ui->val_x8->setText("0");
        ui->val_x9->setText("0");
        ui->val_x10->setText("0");
        ui->val_x11->setText("0");
        ui->val_x12->setText("0");
        ui->val_x13->setText("0");
        ui->val_x14->setText("0");
        ui->val_x15->setText("0");
        ui->val_x16->setText("0");
        ui->val_x17->setText("0");
        ui->val_x18->setText("0");
        ui->val_x19->setText("0");
        ui->val_x20->setText("0");
        ui->val_x21->setText("0");
        ui->val_x22->setText("0");
        ui->val_x23->setText("0");
        ui->val_x24->setText("0");
        ui->val_x25->setText("0");
        ui->val_x26->setText("0");
        ui->val_x27->setText("0");
        ui->val_x28->setText("0");
        ui->val_x29->setText("0");
        ui->val_x30->setText("0");
        ui->val_x31->setText("0");

    }
    if(index==0)
    {
        time=0;
        ui->tableWidget->setRowCount(0);
        ui->tableWidget_2->setRowCount(0);
        tim3 =0;
        tim2 = 0;
    }

}


void MainWindow::on_pushButton_step_clicked()
{
    if(stk==0)
    {
        ui->tableWidget_2->selectRow(1000-1);
        stk = 1;
    }
    else
    {
        ui->tableWidget_2->selectRow(0);
        stk = 0;
    }



}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    if(tim2 ==0 && index==1&&tim3==0)
    {
        char a[2000][8];
        for(int i=0;i<2000;i++)
        {
            for(int j=0;j<8;j++)
            {
               a[i][j]='0';
            }
        }
        for(int i=0;i<2000;i++)
        {
            int k=0;
            char a1[3];
            for(int j=0;j<8;j++)
            {
                    a1[k] =a[i][j];
                    if(k<1)
                    {
                         k++;
                    }
                    else{
                        a1[2]='\0';
                        //ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
                        int val = ui->tableWidget_2->rowCount()-1;
                        ui->tableWidget_2->setItem(val,j/2+1,new QTableWidgetItem(a1));
                        k=0;
                    }


            }
            int val1 = ui->tableWidget_2->rowCount()-1;
            string ci = to_string((i-1)*4);
            ui->tableWidget_2->setItem(val1,0,new QTableWidgetItem(QString::fromStdString(ci)));
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
        }
        tim2 =1;
    }
    else if(index == 0)
        tim2 = 0;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(tim3==0)
     {   phase2 pha2;
        string str[32];
        for(int i=0;i<32;i++)
        {
            str[i] = to_string( pha2.register_file[i]);
        }
        ui->val_x0->setText(QString::fromStdString(str[0]));
        ui->val_x1->setText(QString::fromStdString(str[1]));
        ui->val_x2->setText(QString::fromStdString(str[2]));
        ui->val_x3->setText(QString::fromStdString(str[3]));
        ui->val_x4->setText(QString::fromStdString(str[4]));
        ui->val_x5->setText(QString::fromStdString(str[5]));
        ui->val_x6->setText(QString::fromStdString(str[6]));
        ui->val_x7->setText(QString::fromStdString(str[7]));
        ui->val_x8->setText(QString::fromStdString(str[8]));
        ui->val_x9->setText(QString::fromStdString(str[9]));
        ui->val_x10->setText(QString::fromStdString(str[10]));
        ui->val_x11->setText(QString::fromStdString(str[11]));
        ui->val_x12->setText(QString::fromStdString(str[12]));
        ui->val_x13->setText(QString::fromStdString(str[13]));
        ui->val_x14->setText(QString::fromStdString(str[14]));
        ui->val_x15->setText(QString::fromStdString(str[15]));
        ui->val_x16->setText(QString::fromStdString(str[16]));
        ui->val_x17->setText(QString::fromStdString(str[17]));
        ui->val_x18->setText(QString::fromStdString(str[18]));
        ui->val_x19->setText(QString::fromStdString(str[19]));
        ui->val_x20->setText(QString::fromStdString(str[20]));
        ui->val_x21->setText(QString::fromStdString(str[21]));
        ui->val_x22->setText(QString::fromStdString(str[22]));
        ui->val_x23->setText(QString::fromStdString(str[23]));
        ui->val_x24->setText(QString::fromStdString(str[24]));
        ui->val_x25->setText(QString::fromStdString(str[25]));
        ui->val_x26->setText(QString::fromStdString(str[26]));
        ui->val_x27->setText(QString::fromStdString(str[27]));
        ui->val_x28->setText(QString::fromStdString(str[28]));
        ui->val_x29->setText(QString::fromStdString(str[29]));
        ui->val_x30->setText(QString::fromStdString(str[30]));
        ui->val_x31->setText(QString::fromStdString(str[31]));
        for(int i=0;i<2000;i++)
        {
            int k=0;
            char a1[3];
            for(int j=0;j<8;j++)
            {
                    a1[k] =pha2.memy[i][j];
                    if(k<1)
                    {
                         k++;
                    }
                    else{
                        a1[2]='\0';
                        //ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
                        int val = ui->tableWidget_2->rowCount()-1;
                        ui->tableWidget_2->setItem(val,j/2+1,new QTableWidgetItem(a1));
                        k=0;
                    }


            }
            int val1 = ui->tableWidget_2->rowCount()-1;
            string ci = to_string((i-1)*4);
            ui->tableWidget_2->setItem(val1,0,new QTableWidgetItem(QString::fromStdString(ci)));
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
        }
        tim3 =1 ;
    }

}
