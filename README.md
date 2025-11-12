# 🧙‍♂️ ZeroClassGenerator
ZeroClassGenerator is a **C++ Qt** application that 
automatically generates **basic C++ class code** (`.h` and `.cpp` files) from an intuitive graphical interface.

---

## Overview
<img width="921" height="814" alt="Screenshot 2025-11-12 at 07 34 17" src="https://github.com/user-attachments/assets/32cd586d-dd99-486e-ada4-a4c912d63b0c" />

![ScreenRecording2025-11-12at06 49 34-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/8b386ef0-60a2-464e-a2ae-1b69b673957f)

---

## 🚀 Project objective

The aim of this project is to put into practice the basics of programming with **Qt Widgets**, while building a concrete and useful tool:  
a user-configurable **automatic C++ class generator**.

The programme allows you to:
* enter the name and parent class of a class,
* add attributes and generate their accessors,
* add header comments,
* protect the header from multiple inclusions,
* automatically generate `.h` and `.cpp` files,
* and finally **save the generated code**.

---

##  🛠️ Tech Stack
* C++17
* Qt6
*  `QApplication`, QWidget`, `QDialog`, `QGroupBox`, `QTabWidget`, `QTextEdit`, `QFormLayout`, `QVBoxLayout`, `QHBoxLayout`,
`QLineEdit`, `QListWidget`, `QListWidgetItem`, `QString`, `QPushButton`, `QCheckBox`, `QDateEdit`,
`QFile`, `QFileDialog`, `QMessageBox`, `QRegularExpressionValidator`, `QTextStream`, `QStyleFactory`.
* Qt Creator
* Git + GitHub

---

## 🧱 Project Structure

```
ZeroClassGenerator/
├── .gitignore
├── ClassGenerator.pro  # Qt project configuration file used by qmake, the build system that comes with Qt. It tells qmake how to build your application — which source files, headers, libraries, and modules to include.
├── main.cpp  # Program entry point, launches the main window.          
├── MainWindow.cpp / MainWindow.hpp # inherits from `QWidget`. Allows you to configure and generate the class.                         
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



