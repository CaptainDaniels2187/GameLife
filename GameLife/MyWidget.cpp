#include "MyWidget.h"

void MyWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 12));
	qDebug() << this->pos() << " | " << this->pos() + QPoint(this->width(), this->height());
	painter.drawRect(QRect(this->pos(), this->pos() + QPoint(this->width(), this->height())));
}
