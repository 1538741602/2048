#include "qresetbutton.h"

QResetButton::QResetButton( QWidget* parent) : QLabel(parent)
{
    setText("Try again!");
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QResetButton { background-color: rgb(51, 122, 99); border-radius: 10px; font: bold; color: white; }");
}

void QResetButton::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
