project('qt-simple-demo', 'cpp',
  version : '0.1.0',
  default_options : [
    'warning_level=3',
    'cpp_std=c++20',
    'buildtype=release'
  ]
)

# Check for Qt dependency
qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Gui', 'Widgets'])

# Include the source directory
subdir('src')
