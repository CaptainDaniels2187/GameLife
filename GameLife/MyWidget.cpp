#include "MyWidget.h"
#include <QDebug>

#define FIELD_RIGHT_MARGIN 50
#define FIELD_BOTTOM_MARGIN 20



void MyWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 2));
	qDebug() << this->pos() << " | " << this->pos() + QPoint(this->width() - FIELD_RIGHT_MARGIN, this->height() - FIELD_BOTTOM_MARGIN)<< "|";
	painter.drawRect(QRect(this->pos(), this->pos() + QPoint(this->width() - FIELD_RIGHT_MARGIN, this->height() - FIELD_BOTTOM_MARGIN)));
}
