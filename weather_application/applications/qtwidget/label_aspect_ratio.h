#ifndef LABELASPECTRATIO_H
#define LABELASPECTRATIO_H

#include <QLabel>

class QPixamp;


class LabelAspectRatio : public QLabel
{
    Q_OBJECT

public:
    explicit LabelAspectRatio(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

public slots:
    void setPixmap(const QPixmap& pm);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void updateMargins();

    int _pixmap_width = 0;
    int _pixmap_height = 0;
};

#endif // LABELASPECTRATIO_H
