#pragma once

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QTabWidget>
#include <QWidget>
#include <QFileDialog>

class SecondWindow: public QDialog {

    Q_OBJECT

public:
    SecondWindow(const QString& codeH, const QString& codeC,  QWidget *parent = nullptr);

private slots:
    void saveFile();




private:
    QTextEdit* codeGenerate;
    QTextEdit* codeGenerate1;
    QPushButton* close;
    QPushButton* reg;
    QTabWidget* onglet;
    QWidget* page1;
    QWidget* page2;

};
