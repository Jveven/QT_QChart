#include "dialogpen.h"
#include "ui_dialogpen.h"
#include <QColorDialog>
#include <QPalette>
#include <QPushButton>

QPen DialogPen::getPen()
{
    m_pen.setStyle(Qt::PenStyle(ui->comboPenStyle_2->currentIndex()));
    m_pen.setWidth(ui->spinWidth_2->value());

    QColor  color;
    color=ui->btnColor_2->palette().color(QPalette::Button);
    m_pen.setColor(color);
    return  m_pen;
}

QPen DialogPen::getPen(QPen iniPen, bool &ok)
{
    DialogPen *dlg=new DialogPen;
    QPen pen;
    dlg->setPen(iniPen);
    int ret=dlg->exec();
    if(ret==QDialog::Accepted)
    {
        pen=dlg->getPen();
        ok=true;
    }
    else
    {
        pen=iniPen;
        ok=false;
    }
    delete dlg;
    return pen;

}

void DialogPen::setPen(const QPen &pen)
{
    m_pen=pen;

    ui->spinWidth_2->setValue(pen.width());
    int i=static_cast<int>(pen.style());
    ui->comboPenStyle_2->setCurrentIndex(i);

    QColor  color=pen.color();
    ui->btnColor_2->setAutoFillBackground(true);
    QString str=QString::asprintf("background-color: rgb(%d, %d, %d);",
                                    color.red(),color.green(),color.blue());
    ui->btnColor_2->setStyleSheet(str);

}

DialogPen::DialogPen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPen)
{
    ui->setupUi(this);
    ui->comboPenStyle_2->clear();
    ui->comboPenStyle_2->addItem("NoPen",0);
    ui->comboPenStyle_2->addItem("SolidLine",1);
    ui->comboPenStyle_2->addItem("DashLine",2);
    ui->comboPenStyle_2->addItem("DotLine",3);
    ui->comboPenStyle_2->addItem("DashDotLine",4);
    ui->comboPenStyle_2->addItem("DashDotDotLine",5);
    ui->comboPenStyle_2->addItem("CustomDashLine",6);
    ui->comboPenStyle_2->setCurrentIndex(1);

}

DialogPen::~DialogPen()
{
    delete ui;
}

void DialogPen::on_btnColor_2_clicked()
{
    QColor  color=QColorDialog::getColor();
    if (color.isValid())
    {
        QString str=QString::asprintf("background-color: rgb(%d, %d, %d);",
                                        color.red(),color.green(),color.blue());
        ui->btnColor_2->setStyleSheet(str);
    }

}

