#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
  QPushButton *addTaskButton;
  QLabel *tasksLabel;
  QVBoxLayout *mainLayout;
  QHBoxLayout *toolbarLayout;
  QVBoxLayout *tasksLayout;

  void setupMainUi();
};

#endif // MAINWINDOW_H
