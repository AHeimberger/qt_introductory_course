#include "label_aspect_ratio.h"


LabelAspectRatio::LabelAspectRatio(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{}

void LabelAspectRatio::setPixmap(const QPixmap& pm)
{
    pixmap_width = pm.width();
    pixmap_height = pm.height();

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
    if (pixmap_width <= 0 || pixmap_height <= 0)
        return;

    int w = this->width();
    int h = this->height();

    if (w <= 0 || h <= 0)
        return;

    if (w * pixmap_height > h * pixmap_width)
    {
        int m = (w - (pixmap_width * h / pixmap_height)) / 2;
        setContentsMargins(m, 0, m, 0);
    }
    else
    {
        int m = (h - (pixmap_height * w / pixmap_width)) / 2;
        setContentsMargins(0, m, 0, m);
    }
}
