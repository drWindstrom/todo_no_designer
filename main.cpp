
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow mainWindow;
  mainWindow.setWindowTitle("Todo no designer");
  mainWindow.show();
  return a.exec();
}
