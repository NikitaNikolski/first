#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow *window = new MyWindow();
    str *n = new str;
    QObject::connect(window, SIGNAL(Simple(QString)), n, SLOT(Simple(QString)));
    QObject::connect(window, SIGNAL(Inverse(QString)), n, SLOT(Inversion(QString)));
    QObject::connect(window, SIGNAL(Register(QString)), n, SLOT(Register(QString)));
    QObject::connect(window, SIGNAL(InverseAndRegister(QString)), n, SLOT(InverseAndRegister(QString)));
    /*MainWindow w;
    w.show();*/

    /*QPushButton *pb = new QPushButton("close");
    pb->show();
    QObject::connect(pb, SIGNAL(clicked()), &a, SLOT(quit()));
    */
    /*QSpinBox *sb = new QSpinBox;
    //sb->show();
    QSlider *sl = new QSlider(Qt::Horizontal);
    sb->setMaximum(100);
    sl->setMaximum(100);
    //sl->show();
    QWidget *window = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(sb);
    layout->addWidget(sl);

    window ->setLayout(layout);

    window->show();

    QObject::connect(sb, SIGNAL(valueChanged(int)), sl, SLOT(setValue(int)));
    QObject::connect(sl, SIGNAL(valueChanged(int)), sb, SLOT(setValue(int)));*/
    window->show();

    return a.exec();
}
