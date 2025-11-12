#include "MainWindow.hpp"
#include "SecondWindow.hpp"

#include <QDate>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QRegularExpression>
#include <QRegularExpressionValidator>


/*
 * Construct the main application window.
 *
 * This constructor initializes all widgets, layouts, and signal-slot connections
 * that make up the main interface of the ZeroClassGenerator program.
 *
 * The user can define a class name, parent class, choose generation options,
 * add comments, and specify attributes for the generated C++ class.
 */

MainWindow::MainWindow(): QWidget() {

    // === Group Box 1: Class Definition ===
    gb1 = new QGroupBox("Define the class", this);

    // Create input fields for class name and parent class
    name = new QLineEdit;
    parent = new QLineEdit;

    // Layout for class definition section
    formLayout = new QFormLayout;
    formLayout->addRow("Class &Name:", name);
    formLayout->addRow("Class &Parent:", parent);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    // Apply layout to group box
    gb1->setLayout(formLayout);

    // === Group Box 2: Class options ===
    gb2 = new QGroupBox("Options", this);

    // checkboxes for generation options
    b1 = new QCheckBox("Protect the &header from multiple inclusions");
    b2 = new QCheckBox("Generate a default &constructor");
    b3 = new QCheckBox("Generate a &destructor");

    // Header guard QLineEdit (disabled by default)
    headerGuard = new QLineEdit;
    headerGuard->setEnabled(false);

    // Layout for the options section
    vbox2 = new QVBoxLayout;
    vbox2->addWidget(b1);
    vbox2->addWidget(headerGuard);
    vbox2->addWidget(b2);
    vbox2->addWidget(b3);
    gb2->setLayout(vbox2);


    // === Group Box 3: Comments section ===
    gb3 = new QGroupBox("add comments", this);
    gb3->setCheckable(true);
    gb3->setChecked(false);


    author = new QLineEdit;
    date = new QDateEdit(QDate::currentDate(), this);
    role = new QTextEdit;

    formLayout1 = new QFormLayout;
    formLayout1->addRow("&Author :", author);
    formLayout1->addRow("Da&te of creation :", date);
    formLayout1->addRow("&Role of the class :", role);
    formLayout1->setLabelAlignment(Qt::AlignLeft);
    formLayout1->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    gb3->setLayout(formLayout1);

    // ---------- Attribute Section ---------
    gbAttr = new QGroupBox("Class attribut ", this);
    listAttr = new QListWidget; // create a list Widgets
    addListAttr = new QPushButton("add attributes");


    QVBoxLayout* vattr = new QVBoxLayout;
    vattr->addWidget(listAttr);
    vattr->addWidget(addListAttr);
    gbAttr->setLayout(vattr);

    // ---------- Buttons ---------
    button1 = new QPushButton("Generate", this);
    button2 = new QPushButton("Exit");

    hLayout = new QHBoxLayout;
    hLayout->addStretch(1);
    hLayout->addWidget(button1);
    hLayout->addWidget(button2);
    hLayout->setSpacing(5);   // space between buttons

    // ---------- Main Layout ---------
    vbox1 = new QVBoxLayout;
    vbox1->addWidget(gb1);
    vbox1->addWidget(gb2);
    vbox1->addWidget(gb3);
    vbox1->addWidget(gbAttr);
    vbox1->addLayout(hLayout);

    setLayout(vbox1);

    // ---------- Connections ---------
    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(generateCode()));
    QObject::connect(button2, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(b1, SIGNAL(toggled(bool)), headerGuard, SLOT(setEnabled(bool)));
    QObject::connect(name, SIGNAL(textChanged(QString)), this, SLOT(updateHeaderGuard()));
    QObject::connect(addListAttr, SIGNAL(clicked()), this, SLOT(addAttribut()));

    // Validator: ensures class name is valid (no spaces, accents, etc.)
    QRegularExpression rx("^[A-Za-z_][A-Za-z0-9_]*$");
    QValidator* validator = new QRegularExpressionValidator(rx, this);
    name->setValidator(validator);

}

/*
 * @brief Update the header guard text dynamically when the class name changes.
 *
 * This slot listens to the QLineEdit `name` textChanged() signal and automatically
 * generates a header guard in uppercase (e.g., HEADER_MYCLASS).
 */

void MainWindow::updateHeaderGuard() {
    QString text = name->text().toUpper();
    if(!text.isEmpty()) {
        headerGuard->setText("HEADER_" + text);
    }
    else{
        headerGuard->clear();
    }

}

/*
 * @brief Add a new attribute to the list of class attributes.
 *
 * Each new attribute is editable in place by the user. The user is expected
 * to type both type and name (e.g., "int age" or "QString name").
 */

void MainWindow::addAttribut() {
    QListWidgetItem* item = new QListWidgetItem("New Attribut");
    item->setFlags(item->flags() | Qt::ItemIsEditable);   // Make item editable
    listAttr->addItem(item);
    listAttr->editItem(item);   // Focus on the new item for immediate editing

}

/*
 * @brief Generate the C++ class code based on user inputs.
 *
 * This method collects all entered information (class name, options, comments,
 * attributes) and generates both the `.hpp` and `.cpp` code. The result is
 * displayed in a secondary dialog window (`SecondWindow`).
 */

void MainWindow::generateCode() {

    // --- Validate mandatory field: class name ---
    if(name->text().isEmpty()){
        QMessageBox::critical(this, "Error", "Please enter at least the name of the class");
        return;
    }


    QString code;       // For .hpp content
    QString code1;     // For .cpp content

    QString nClass = name->text();
    QString pClass = parent->text();

    // --- Comments section ---
    if (gb3->isChecked()) {
        code += "/*\n";
        code += "Author : " + author->text() + "\n";
        code += "Date of creation : " + date->date().toString("ddd dd MMM yyyy") + "\n\n";
        code += "Role : \n" + role->toPlainText() + "\n";
        code += "*/\n\n";
    }

    // --- Header (.h) ---
    // Protection against multiple inclusions
    if (b1->isChecked()) {
        QString define = headerGuard->text();
        code += "#ifndef " + define + "\n";
        code += "#define " + define + "\n\n";
    }

    // Class declaration
    code += "class " + nClass;

    if (!pClass.isEmpty())
        code += " : public " + pClass + " {\n";

    code += "\npublic:\n";

    // Constructor and destructor declaration
    if (b2->isChecked()) {
        code += "    " + nClass + "();\n";

    }
    if (b3->isChecked()) {
        code += "    ~" + nClass + "();\n";
    }

    // Accessor methods generation
    if(b2->isChecked()) {
        for (int i = 0; i < listAttr->count(); ++i) {
            QString attr = listAttr->item(i)->text();
            QStringList parts = attr.split(" ", Qt::SkipEmptyParts);

            if(parts.size() < 2)
                continue;

            QString type = parts.first();
            QString str = parts.last().replace(";", "");

            if(!str.isEmpty())
                str[0] = str[0].toUpper();

            code += "    " + type + " get" + str + "() const;\n";
            code += "    void set" + str + "(const " + type + "& value);\n";
        }
        code += "\n";
    }

    // Attributes section
    code += "protected:\n\n";
    code += "private:\n";
    for(int i = 0; i <listAttr->count(); i++) {
        code += "  " + listAttr->item(i)->text() + ";" + "\n";
    }
    code += "\n};\n\n";

    if (b1->isChecked()) {
        code += "#endif\n";
    }

    // --- Source (.cpp) ---
    // Constructor definition
    code1 += nClass + "::" + nClass + "() {\n";
    for (int i = 0; i < listAttr->count(); i++) {
        QString attr = listAttr->item(i)->text().trimmed();
        QStringList parts = attr.split(" ", Qt::SkipEmptyParts);
        if (parts.size() >= 2) {
            QString type = parts[0];
            QString str1 = parts[1].replace(";", "");
            if (type == "int")
                code1 += "    " + str1 + " = 0;\n";
            else if (type == "double" || type == "float")
                code1 += "    " + str1 + " = 0.0;\n";
            else
                code1 += "    " + str1 + " = " + type + "();\n";
        }
    }
    code1 += "}\n\n";

    // Destructor definition
    code1 += nClass + "::~" + nClass + "() {\n";
    code1 += "    // Nothing to clear yet \n";
    code1 += "}\n\n";

    // getters and setters definition
    for (int i = 0; i < listAttr->count(); i++) {
        QString attr = listAttr->item(i)->text().trimmed();
        QStringList parts = attr.split(" ", Qt::SkipEmptyParts);
        if (parts.size() < 2)
            continue;

        QString type = parts[0];
        QString str2 = parts[1].replace(";", "");
        QString capName = str2;
        capName[0] = capName[0].toUpper();

        // Getter
        code1 += type + " " + nClass + "::get" + capName + "() const {\n";
        code1 += "    return " + str2 + ";\n";
        code1 += "}\n\n";

        // Setter
        code1 += "void " + nClass + "::set" + capName + "(const " + type + "& value) {\n";
        code1 += "    " + str2 + " = value;\n";
        code1 += "}\n\n";
    }

    // --- Display the generated code in a new dialog window ---
    SecondWindow *windowCode = new SecondWindow(code, code1, this);
    windowCode->exec();
}
