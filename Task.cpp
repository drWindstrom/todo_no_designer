#include "Task.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>

Task::Task(const QString &text, QWidget *parent) : QWidget(parent) {
  doneCheckBox = new QCheckBox();
  noteLabel = new QLabel(text);
  editButton = new QPushButton("Edit");
  removeButton = new QPushButton("Remove");

  taskLayout = new QHBoxLayout();
  taskLayout->addWidget(doneCheckBox);
  taskLayout->addWidget(noteLabel);
  taskLayout->addStretch();
  taskLayout->addWidget(editButton);
  taskLayout->addWidget(removeButton);

  setLayout(taskLayout);

  connect(removeButton, &QPushButton::clicked,
          [this] { emit taskRemoved(this); });
  connect(editButton, &QPushButton::clicked, this, &Task::editTask);
  connect(doneCheckBox, &QCheckBox::stateChanged,
          [this] { emit statusChanged(); });
}

bool Task::isDone() { return doneCheckBox->isChecked(); }

void Task::editTask() {
  bool ok;
  QString newText =
      QInputDialog::getText(this, tr("Edit task"), tr("Task description:"),
                            QLineEdit::Normal, noteLabel->text(), &ok);

  if (ok) {
    noteLabel->setText(newText);
  }
}
