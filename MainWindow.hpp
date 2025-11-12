#pragma once

#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>


class MainWindow: public QWidget {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void generateCode();
    void updateHeaderGuard();
    void addAttribut();

private:
    QGroupBox* gb1;
    QGroupBox* gb2;
    QGroupBox* gb3;
    QGroupBox* gbAttr;
    QLineEdit* name;
    QLineEdit* parent;
    QLineEdit* author;
    QDateEdit* date;
    QTextEdit* role;
    QVBoxLayout* vbox1;
    QVBoxLayout* vbox2;
    QVBoxLayout* vbox3;
    QFormLayout* formLayout;
    QFormLayout* formLayout1;
    QCheckBox* b1;
    QCheckBox* b2;
    QCheckBox* b3;
    QLineEdit* headerGuard;


    QPushButton* button1;
    QPushButton* button2;
    QPushButton* addListAttr;
    QListWidget* listAttr;

    QHBoxLayout* hLayout;

};
