#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setWindowTitle("Todo App without Designer");

    QPushButton *addTaskButton = new QPushButton(&w);
    addTaskButton->setText("Add Task");

    addTaskButton->setGeometry(50, 50, 100, 40);

    QLabel *taskLabel = new QLabel(&w);
    taskLabel->setText("Tasks");
    taskLabel->setGeometry(0, 50, 100, 20);


    w.show();
    return a.exec();
}
