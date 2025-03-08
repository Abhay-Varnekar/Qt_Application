# Define source files
sources = [
  'main.cpp',
  'mainwindow.cpp',
]

# Define headers to be processed with moc
headers = [
  'mainwindow.hpp',
]

# Process the headers with Qt's moc
processed = qt5.preprocess(
  moc_headers: headers,
  dependencies: qt5_dep
)

# Build the executable
executable('qtapplication',
  sources: sources + processed,
  dependencies: qt5_dep,
  include_directories: include_directories('.')
)