#include "textclass.h"
#include <QDebug>
textclass::textclass()
{
    value1 = 1;
    value2 = true;
}



void textclass::getvalue2()
{
    //print_text();
    qDebug() << value1;
    qDebug() << value2;
}
