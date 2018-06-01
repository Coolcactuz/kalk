#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QString>

#include <cmath>
#include <iostream>

using namespace std;

class Widget : public QWidget
{
public:

    void paintEvent(QPaintEvent* event)
    {
        QPainter p;

        p.begin(this);

        p.setRenderHint(QPainter::Antialiasing);
        p.setPen(QPen(Qt::black, 5, Qt::SolidLine));

        p.drawLine(QWidget::width() / 2, QWidget::height() / 12, QWidget::width() / 2, (QWidget::height() * 11) / 12);
        p.drawLine(QWidget::width() / 12, QWidget::height() / 2, (QWidget::width() * 11) / 12, QWidget::height() / 2);

        p.drawText((QWidget::width() / 2) + 5, (QWidget::height() / 2) + 20, "0");


        double reale = -0.481;
        double immaginaria = 6.594;

        if((reale >= 1 || reale <= -1) && (immaginaria >= 1 || immaginaria <=-1)){

          int intero_reale = abs(static_cast<int>(reale));
          int intero_imm = abs(static_cast<int>(immaginaria));

          p.drawText((QWidget::width() / 2) + 5, (QWidget::height() / 2) + 20, "0");

            p.drawText(
              ((QWidget::width() * 11) / 12),
              (QWidget::height() / 2) + 20,
              QString::number(intero_reale * 2)
            );
            p.drawText(
              (QWidget::width() / 12),
              (QWidget::height() / 2) + 20,
              QString::number(intero_reale * -2)
            );

            p.drawText(
              QWidget::width() / 2 + 5,
              QWidget::height() / 12,
              QString::number(intero_imm * 2)
            );
            p.drawText(
              QWidget::width() / 2 + 5,
              (QWidget::height() * 11) / 12,
              QString::number(intero_imm * -2)
            );

            int x = 0;
            int y = 0;

            int sizex = ((QWidget::width() * 11) / 12) - QWidget::width()/2;
            int sizey = ((QWidget::height() * 11) / 12) - QWidget::height()/2;

            if(reale > 0)
              x = QWidget::width()/2 + sizex/2;
            else
              x = QWidget::width()/12 + sizex/2;

            if(immaginaria > 0)
              y = QWidget::height()/12 + sizey/2;
            else
              y = QWidget::height()/2 + sizey/2;

            p.setPen(QPen(Qt::green, 12, Qt::SolidLine, Qt::RoundCap));
            p.drawPoint(x, y);

            p.setPen(QPen(Qt::black, 5, Qt::SolidLine));
            p.drawText(x + 10,
              y + 10,
              QString('(').append(QString::number(reale)).append(QString(',')).append(QString::number(immaginaria)).append(QString(')'))
            );
        }
        else{

          
        }


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
