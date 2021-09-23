#ifndef TASK_H
#define TASK_H

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QPushButton;
class QCheckBox;

class Task : public QWidget {
  Q_OBJECT
public:
  explicit Task(const QString &text = "undefined", QWidget *parent = nullptr);
  bool isDone();

signals:
  void taskRemoved(Task *task);
  void statusChanged();

private slots:
  void editTask();

private:
  QHBoxLayout *taskLayout;
  QPushButton *editButton;
  QPushButton *removeButton;
  QLabel *noteLabel;
  QCheckBox *doneCheckBox;
};

#endif // TASK_H
