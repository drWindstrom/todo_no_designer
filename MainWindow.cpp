#include "MainWindow.h"
#include "Task.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  setupMainUi();
  connect(addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

void MainWindow::removeTask(Task *task) {
  _tasks.removeOne(task);
  delete task;
  updateLabel();
}

void MainWindow::addTask() {
  bool ok;
  QString text = QInputDialog::getText(this, tr("Create new task"),
                                       tr("Task description:"),
                                       QLineEdit::Normal, tr("undefined"), &ok);
  if (ok) {
    Task *newTask = new Task(text);
    tasksLayout->addWidget(newTask);
    _tasks.append(newTask);
    connect(newTask, &Task::taskRemoved, this, &MainWindow::removeTask);
    connect(newTask, &Task::statusChanged, this, &MainWindow::updateLabel);
    updateLabel();
  }
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

void MainWindow::updateLabel() {
  int totalTasks = _tasks.size();
  int doneTasks = 0;
  for (const auto task : _tasks) {
    if (task->isDone()) {
      doneTasks++;
    }
  }
  QString statusLabel =
      QString("%1 done / %2 tasks").arg(doneTasks).arg(totalTasks);
  tasksLabel->setText(statusLabel);
}
