#include <QWidget>
#include <QPainter>
#include <QApplication>

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
