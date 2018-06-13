#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QString>

#include <cmath>
#include <iostream>

using namespace std;

class Widget : public QWidget{

public:

    void paintEvent(QPaintEvent* event)
    {
        QPainter p;
        p.begin(this);

        //assi cartesiani

        p.setRenderHint(QPainter::Antialiasing);
        p.setPen(QPen(Qt::black, 5, Qt::SolidLine));

        p.drawLine(QWidget::width() / 2, QWidget::height() / 12, QWidget::width() / 2, (QWidget::height() * 11) / 12);
        p.drawLine(QWidget::width() / 12, QWidget::height() / 2, (QWidget::width() * 11) / 12, QWidget::height() / 2);

        p.drawText((QWidget::width() / 2) + 5, (QWidget::height() / 2) + 20, "0");

        //numero complesso cartesiano

        double reale = -0.234;
        double immaginaria = 0.31;

        //indici e posizione parte reale

        int x = 0;
        int ipx = -1;
        int inx = 1;

        double abs_reale = abs(reale);

        if(abs_reale >= 1){

          int aux1 = static_cast<int>(abs_reale);

          ipx = aux1*2;
          inx = aux1*(-2);

          if(reale > 0)
            x = ((QWidget::width()*5)/8) + QWidget::width()/12;
          else
            x = ((QWidget::width()*5)/24) + QWidget::width()/12;
        }
        else if (abs_reale == 0){

          inx = -1;
          ipx = 1;

          cout << "qui1" << endl;


          x = QWidget::width()/2;
        }
        else{

          inx = -1;
          ipx = 1;

          cout << "qui2" << endl;

          if(reale > 0)
            x = (((QWidget::width()*5)/12 *reale)) + QWidget::width()/2;
          else
            x = ((QWidget::width()*5)/12 *(1+reale)) + QWidget::width()/12;
        }


        //indici e posizione parte immaginaria

        int y = 0;
        int ipy = -1;
        int iny = 1;

        double abs_immaginaria = abs(immaginaria);

        if(abs_immaginaria >= 1){

          int aux1 = static_cast<int>(abs_immaginaria);

          ipy = aux1*2;
          iny = aux1*(-2);

          if(immaginaria > 0)
            y = ((QWidget::height()*5)/24) + QWidget::height()/12;
          else
            y = ((QWidget::height()*5)/8) + QWidget::height()/12;

        }
        else if (abs_immaginaria == 0){

          iny = -1;
          ipy = 1;

          cout << "sono qui" << endl;

          y = QWidget::height()/2;
        }
        else{

          iny = -1;
          ipy = 1;

          cout << "ciao" << endl;

          if(immaginaria > 0){
            y = (((QWidget::height()*5)/12) * (1 - immaginaria)) + QWidget::height()/12;
            cout << "immaginaria positiva" << endl;
          }
          else
            y = (((QWidget::height()*5)/12) *immaginaria) + QWidget::height()/2;
        }

        //disegno punto e indici

        p.drawText((QWidget::width()*11)/12,
                    QWidget::height()/2 + 15,
                    QString::number(ipx));
        p.drawText( QWidget::width()/12,
                    QWidget::height()/2 + 15,
                    QString::number(inx));

        p.drawText(QWidget::width()/2 + 5,
                    QWidget::height()/12,
                    QString::number(ipy));
        p.drawText( QWidget::width()/2 + 5,
                    (QWidget::height()*11)/12,
                    QString::number(iny));

        p.setPen(QPen(Qt::green, 12, Qt::SolidLine, Qt::RoundCap));
        p.drawPoint(x,y);

        cout << QWidget::width() << endl;
        cout << x << endl;

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
