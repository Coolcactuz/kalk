#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QString>

#include <cmath>

class Widget : public QWidget
{
protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter p;

        p.begin(this);

        p.setRenderHint(QPainter::Antialiasing);

        p.setPen(QPen(Qt::black, 5, Qt::SolidLine));
        p.drawLine(QWidget::width() / 4, QWidget::height() / 2, (3*QWidget::width()) / 4, QWidget::height() / 2);

        p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
        p.drawPoint(QWidget::width() / 4, QWidget::height() / 2);
        p.drawPoint((3 * QWidget::width()) / 4, QWidget::height() / 2);

        double d = 3.01;

        int pavimento = floor(d);
        int soffitto = ceil(d);

        double decimal_part = d - pavimento;

        int size = QWidget::width() / 2;
        int offset = QWidget::width() / 4;

        p.setPen(QPen(Qt::black, 12, Qt::SolidLine));

        p.drawText(QWidget::width() / 4 , QWidget::height() / 2 + 20, QString::number(pavimento));
        p.drawText((3 * QWidget::width()) / 4, QWidget::height() / 2 + 20, QString::number(soffitto));

        p.setPen(QPen(Qt::green, 12, Qt::SolidLine, Qt::RoundCap));
        p.drawPoint((size * decimal_part) + offset, QWidget::height() / 2);

        p.end();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget w;
    w.show();

    return app.exec();
}
