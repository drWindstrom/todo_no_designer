#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  setupMainUi();
  connect(addTaskButton, &QPushButton::clicked, QApplication::instance(),
          &QApplication::quit);
}

void MainWindow::setupMainUi() {
  // Toolbar
  toolbarLayout = new QHBoxLayout();

  addTaskButton = new QPushButton("Add Task");
  tasksLabel = new QLabel("0 done / 0 tasks");

  toolbarLayout->addWidget(tasksLabel);
  toolbarLayout->addStretch();
  toolbarLayout->addWidget(addTaskButton);
  // Main Layout
  mainLayout = new QVBoxLayout();
  mainLayout->addLayout(toolbarLayout);

  tasksLayout = new QVBoxLayout();
  mainLayout->addLayout(tasksLayout);
  mainLayout->addStretch();

  setLayout(mainLayout);
}
