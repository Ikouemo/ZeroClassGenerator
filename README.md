# 🧙‍♂️ ZeroClassGenerator
ZeroClassGenerator is a **C++ / Qt** application that 
automatically generates **basic C++ class code** (`.h` and `.cpp` files) from an intuitive graphical interface.

---

## Overview
<img width="600" height="500" alt="Screenshot 2025-11-12 at 07 34 17" src="https://github.com/user-attachments/assets/32cd586d-dd99-486e-ada4-a4c912d63b0c" />

![ScreenRecording2025-11-12at06 49 34-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/8b386ef0-60a2-464e-a2ae-1b69b673957f)

---

## 🚀 Project objective

The goal of this project is to practice Qt Widgets programming by building a concrete and useful tool:
a user-configurable automatic C++ class generator.

The programme allows you to:
* Define a class name and parent class
* Add attributes and automatically generate getters/setters
* Add author and creation date comments
* Protect headers from multiple inclusions
* Generate .hpp and .cpp code
* Save the generated files locally

---

##  🛠️ Tech Stack
* Language: C++17
* Framework: Qt6
* Widgets:
QApplication, QWidget, QDialog, QGroupBox, QTabWidget, QTextEdit, QFormLayout, QVBoxLayout, QHBoxLayout,
QLineEdit, QListWidget, QListWidgetItem, QString, QPushButton, QCheckBox, QDateEdit,
QFile, QFileDialog, QMessageBox, QRegularExpressionValidator, QTextStream, QStyleFactory.
* IDE: Qt Creator
* Version  Control: Git + GitHub

---

## 🧱 Project Structure

```
ZeroClassGenerator/
├── .gitignore
├── ClassGenerator.pro                   # Qt project configuration file (used by qmake.
├── main.cpp                             # Program entry point.          
├── MainWindow.cpp / MainWindow.hpp      # inherits from `QWidget`. Allows you to configure and generate the class.                         
├── SecondWindow.cpp / SecondWindow.hpp  # inherits from `QDialog`. Displays the generated code with the option to save it.     
├── RRADME.md

```
--- 

## 🧑‍💻 Author

**Ivan Wilfried Kouemo**
📧 [ivanovkouemo@gmail.com](mailto:ivanovkouemo@gmail.com)
🔗 [GitHub: IKouemo](https://github.com/IKouemo)

---

## 📝 License

This project is licensed under the **MIT License** — feel free to use, modify, and distribute it freely.



