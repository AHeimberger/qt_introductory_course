#include "style_sheet.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>


namespace {

struct StyleMapping {
    const char* key;
    const char* value;
};


static const StyleMapping MAPPINGS[] =
    {
// Fonts
    { "#COMMON_FONT_FAMILY#", "Sans" },
    { "#BIG_FONT_SIZE#", "28pt" },
    { "#MED_FONT_SIZE#", "20px" },
    { "#SMALL_FONT_SIZE#", "16px" },

// Colors
    { "#COMMON_FONT_COLOR#", "black"   },
    { "#WHITE#", "white"   },
    { "#WHITE_SMOKE#", "#F5F5F5" },
    { "#SILVER#", "silver"  }
};

}  // namespace


bool StyleSheet::load(const QString &file_name)
{
    bool res = false;
    QFile file(file_name);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        _style_sheet = prepare(stream.readAll());
        res = true;
    }
    else
    {
        qDebug() << "Cannot open stylesheet " << file_name;
    }

    return res;
}

const QString &StyleSheet::getStyleSheet() const
{
    return _style_sheet;
}


QString StyleSheet::prepare(const QString &style_sheet)
{
    QString result = style_sheet;

    for (const auto& mapping : MAPPINGS)
    {
        result.replace(mapping.key, mapping.value);
    }

    return result;
}
