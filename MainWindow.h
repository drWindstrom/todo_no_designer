#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QWidget>

class QHBoxLayout;
class QLabel;
class QPushButton;
class QVBoxLayout;
class Task;

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

public slots:
  void removeTask(Task *task);

private slots:
  void addTask();

signals:

private:
  QPushButton *addTaskButton;
  QLabel *tasksLabel;
  QVBoxLayout *mainLayout;
  QHBoxLayout *toolbarLayout;
  QVBoxLayout *tasksLayout;

  QVector<Task *> _tasks;

  void setupMainUi();
  void updateLabel();
};

#endif // MAINWINDOW_H
