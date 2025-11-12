#include "SecondWindow.hpp"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

/*
 * @brief Construct a new SecondWindow dialog.
 *
 * This window displays the generated C++ code (.hpp and .cpp) in two tabs.
 * It allows the user to view, copy, or save the generated files to disk.
 */


SecondWindow::SecondWindow(const QString& codeH, const QString& codeC, QWidget *parent): QDialog(parent) {


    setWindowTitle("Code generate ");
    resize(500, 600);

     // --- Create the tab widget (for .hpp and .cpp views) ---
    onglet = new QTabWidget(this);

    // =======================
    // --- Header (.hpp) tab ---
    // =======================

    page1 = new QWidget;

    // Display for the generated header file
    codeGenerate = new QTextEdit;
    codeGenerate->setPlainText(codeH);
    codeGenerate->setReadOnly(true);
    codeGenerate->setFont(QFont("Courier New"));         // Monospace font for code readability
    codeGenerate->setLineWrapMode(QTextEdit::NoWrap);    // Prevent line wrapping

    QVBoxLayout *layoutH = new QVBoxLayout;
    layoutH->addWidget(codeGenerate);
    page1->setLayout(layoutH);

    // =======================
    // --- Source (.cpp) tab ---
    // =======================
    page2 = new QWidget;

    // Display for the generated source file
    codeGenerate1 = new QTextEdit;
    codeGenerate1->setPlainText(codeC);
    codeGenerate1->setReadOnly(true);
    codeGenerate1->setFont(QFont("Courier New"));
    codeGenerate1->setLineWrapMode(QTextEdit::NoWrap);

    QVBoxLayout *layoutC = new QVBoxLayout;
    layoutC->addWidget(codeGenerate1);
    page2->setLayout(layoutC);

    // --- Add both tabs to the QTabWidget ---
    onglet->addTab(page1, "Magicien.hpp");
    onglet->addTab(page2, "Magicien.cpp");

    // =======================
    // --- Global Buttons ---
    // =======================
    reg = new QPushButton("Save");
    close = new QPushButton("Close");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->addStretch();
    boutonsLayout->addWidget(reg);
    boutonsLayout->addWidget(close);

    // =======================
    // --- Main Layout ---
    // =======================
    QVBoxLayout *layoutGlobal = new QVBoxLayout(this);
    layoutGlobal->addWidget(onglet);
    layoutGlobal->addLayout(boutonsLayout);

    // =======================
    // --- Signal/Slot Connections ---
    // =======================
    connect(close, SIGNAL(clicked()), this, SLOT(accept()));   // close the dialog
    connect(reg, SIGNAL(clicked()), this, SLOT(saveFile()));   // save selected code file
}

/*
 * @brief Save the generated code to disk.
 *
 * This function allows the user to save either the header file (.hpp)
 * or the source file (.cpp), depending on the currently selected tab.
 *
 * The user selects a folder via QFileDialog, and the corresponding file
 * is written using QFile and QTextStream.
 */
void SecondWindow::saveFile(){

    // Get currently selected tab index (0 = .hpp, 1 = .cpp)
    int index = onglet->currentIndex();

    QString dir = QFileDialog::getExistingDirectory(this, "choose a folder to save the code");
    if (dir.isEmpty())
        return;   // User canceled the dialog

    // --- Save Header File (.hpp) ---
    if(index == 0) {
        QFile fileH(dir + "/Magicien.hpp");
        if (fileH.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&fileH);
            out << codeGenerate->toPlainText();
            fileH.close();
        }
    }

    // --- Save Source File (.cpp) ---
    else if (index == 1) {
        QFile fileC(dir + "/Magicien.cpp");
        if (fileC.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&fileC);
            out << codeGenerate1->toPlainText();
            fileC.close();
        }
    }

}
