# Qt Application

A small Qt application demonstrating good C++20 practices and Meson build system integration.

## Features

- Simple UI with a button that changes a text label when clicked
- Modern C++20 code style and features
- Well-documented code with consistent formatting
- Meson build system configuration

## Requirements

- C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 19.28+)
- Qt 5.15.0 or newer
- Meson 0.56.0 or newer
- Ninja build system (recommended)

## Installing Dependencies

Before you can build and run this application, you need to install several dependencies. Below are the steps for installing the necessary tools and libraries.

### 1. Install Qt

Qt is a popular framework for developing graphical user interfaces and applications. You will need to install Qt libraries and development tools to compile and run Qt-based applications. 

#### On Ubuntu/Debian-based systems:
   ```
  sudo apt update
  sudo apt install qttools5-dev-tools qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
   ```  
### 2. Install Meson, Ninja, Pkg-config

Before starting with the actual build, you’ll need **Meson**, **Ninja**, and **pkg-config** for managing the build process and fetching flags for libraries.

#### On Ubuntu/Debian-based systems:
   ```
  sudo apt update
  sudo apt install meson ninja-build pkg-config
   ```

## Building the Project

1. Clone the repository
   ```
   git clone https://github.com/Abhay-Varnekar/Qt_Application.git
   cd Qt_Application
   ```
2. Configure the build:
   ```
   meson setup build # Creates the build directory. "build" is just a suggestion; you can use any name.
   ```
3. Build the project:
   ```
   meson compile -C build
   ```
4. Run the application:
   ```
   ./build/src/qtapplication
   ```

## **📂 File Structure**

Here's the organized file structure for the project:

```plaintext
📦 Qt Application
│
├── meson.build           # Root build configuration
├── 📁 src               # Source code directory
│   ├── main.cpp          # Application entry point
│   ├── mainwindow.cpp    # Implementation of the MainWindow class
│   ├── mainwindow.h      # Declaration of the MainWindow class
│   ├── meson.build       # Build configuration for the src directory
│   └── 📁 resources      # Application resources
│       └── styles.qss    # Stylesheet for the application
├── README.md             # Project documentation 
```
## Code Style

This project follows the Google C++ Style Guide with minor modifications.

## License

MIT License
