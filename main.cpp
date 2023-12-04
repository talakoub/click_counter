#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

using namespace Qt;


void handleClick(QLabel *l, int *pc);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int counter = 0;
    int *pcounter = &counter;

    QWidget *mainWindow         = new QWidget();
    mainWindow->setGeometry(200, 200, 500, 500);
    mainWindow->setWindowTitle("Click Counter App");

    QVBoxLayout *mainLayout     = new QVBoxLayout();

    QPushButton *btn            = new QPushButton("Click Me!");

    QLabel *label               = new QLabel("0");
    label->setAlignment(AlignCenter);

    mainLayout->addWidget(label);
    mainLayout->addWidget(btn);

    mainWindow->setLayout(mainLayout);


    QObject::connect(btn, &QPushButton::clicked, [=](){ handleClick(label, pcounter); });

    mainWindow->show();

    return a.exec();
}




void handleClick(QLabel *l, int *pc)
{
    (*pc)++;

    QString myStr       = QString::number((*pc));
    l->setText(myStr);


    return;
}



