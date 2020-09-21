#include "label_aspect_ratio.h"


LabelAspectRatio::LabelAspectRatio(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{}

void LabelAspectRatio::setPixmap(const QPixmap& pm)
{
    _pixmap_width = pm.width();
    _pixmap_height = pm.height();

    updateMargins();
    QLabel::setPixmap(pm);
}

void LabelAspectRatio::resizeEvent(QResizeEvent* event)
{
    updateMargins();
    QLabel::resizeEvent(event);
}

void LabelAspectRatio::updateMargins()
{
    if (_pixmap_width <= 0 || _pixmap_height <= 0)
        return;

    int w = this->width();
    int h = this->height();

    if (w <= 0 || h <= 0)
        return;

    if (w * _pixmap_height > h * _pixmap_width)
    {
        int m = (w - (_pixmap_width * h / _pixmap_height)) / 2;
        setContentsMargins(m, 0, m, 0);
    }
    else
    {
        int m = (h - (_pixmap_height * w / _pixmap_width)) / 2;
        setContentsMargins(0, m, 0, m);
    }
}
