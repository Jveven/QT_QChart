#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValueAxis>
#include <QtCharts>
#include <QTime>
#include "dialogpen.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createChartA();
    prepareDataA();
    updateFromChartA();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actZoomOut_triggered()
{
    ui->chartView->chart()->zoom(0.8);
}


void MainWindow::on_actZoomIn_triggered()
{
    ui->chartView->chart()->zoom(1.2);
}


void MainWindow::on_actZoomReset_triggered()
{
    ui->chartView->chart()->zoomReset();
}

void MainWindow::createChartA()
{
    QChart *chart=new QChart();
    chart->setTitle("简单的曲线");
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    QLineSeries *series0=new QLineSeries;
    QLineSeries *series1=new QLineSeries;
    series0->setName("Sin曲线");
    series1->setName("Cos曲线");
    curSeries=series0;

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    series1->setPen(pen);

    chart->addSeries(series0);
    chart->addSeries(series1);

    QValueAxis *axisX =new QValueAxis;
    QValueAxis *axisY=new QValueAxis;
    curAxis=axisX;

    axisX->setRange(0,10);
    axisX->setLabelFormat("%.1f");
    axisX->setTickCount(11);
    axisX->setMinorTickCount(4);
    axisX->setTitleText("time(secs)");

    axisY->setRange(-1.5,1.5);
    axisY->setTickCount(3);
    axisY->setMinorTickCount(4);
    axisY->setTitleText("value");

    //弃用
    // chart->setAxisX((axisX,series0);
    // chart->setAxisX(axisX,series1);
    // chart->setAxisY(axisY,series0);
    // chart->setAxisY(axisY,series1);

    chart->addAxis(axisX,Qt::AlignBottom);
    series0->attachAxis(axisX);
    chart->addAxis(axisX,Qt::AlignBottom);
    series1->attachAxis(axisX);

    chart->addAxis(axisY,Qt::AlignLeft);
    series0->attachAxis(axisY);
    chart->addAxis(axisY,Qt::AlignLeft);
    series1->attachAxis(axisY);
}

void MainWindow::prepareDataA()
{
    QLineSeries *series0=(QLineSeries *)ui->chartView->chart()->series().at(0);
    QLineSeries *series1=(QLineSeries *)ui->chartView->chart()->series().at(1);
    int cnt=100;
    series0->clear();
    series1->clear();
    srand(QTime::currentTime().second());
    qreal t=0,y1,y2,intv=0.1;
    qreal rd;
    for(int i=0;i<cnt;i++)
    {
        rd=(rand()%10)-5;
        y1=qSin(t)+rd/50;
        series0->append(t,y1);
        y2=qCos(t)+rd/50;
        series1->append(t,y2);
        t=t+intv;
    }
}

void MainWindow::updateFromChartA()
{
    QChart *chart=ui->chartView->chart();
    ui->editTitle_2->setText(chart->title());
    QMargins mg=chart->margins();
    ui->spinMarginBottom_2->setValue(mg.bottom());
    ui->spinMarginLeft_2->setValue(mg.left());
    ui->spinMarginRight_2->setValue(mg.right());
    ui->spinMarginTop_2->setValue(mg.top());
}


void MainWindow::on_actDraw_triggered()
{
    prepareDataA();
}


void MainWindow::on_btnSetTitleFont_2_clicked()
{
    QFont font=ui->chartView->chart()->titleFont();
    bool ok=false;
    font=QFontDialog::getFont(&ok,font);
    if(ok)
    {
        ui->chartView->chart()->setTitleFont(font);
    }
}


void MainWindow::on_btnSetTitle_2_clicked()
{
    QChart *chart=ui->chartView->chart();
    chart->setTitle(ui->editTitle_2->text());
}


void MainWindow::on_radioButton_5_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignTop);
}


void MainWindow::on_radioButton_6_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
}


void MainWindow::on_radioButton_7_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_radioButton_8_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignRight);
}


void MainWindow::on_chkLegendVisible_2_clicked(bool checked)
{
    ui->chartView->chart()->legend()->setVisible(checked);
}


void MainWindow::on_chkBoxLegendBackground_2_clicked(bool checked)
{
    ui->chartView->chart()->legend()->setBackgroundVisible(checked);
}


void MainWindow::on_btnLegendFont_2_clicked()
{
    QFont font=ui->chartView->chart()->legend()->font();
    bool ok=false;
    font=QFontDialog::getFont(&ok,font);
    if(ok)
    {
        ui->chartView->chart()->legend()->setFont(font);
    }
}


void MainWindow::on_btnLegendlabelColor_2_clicked()
{
    QColor color=ui->chartView->chart()->legend()->labelColor();
    color=QColorDialog::getColor(color);
    if(color.isValid())
    {
        ui->chartView->chart()->legend()->setLabelColor(color);
    }
}


void MainWindow::on_btnSetMargin_2_clicked()
{
    QMargins mgs;
    mgs.setBottom(ui->spinMarginBottom_2->value());
    mgs.setLeft(ui->spinMarginLeft_2->value());
    mgs.setRight(ui->spinMarginRight_2->value());
    mgs.setTop(ui->spinMarginTop_2->value());
    ui->chartView->chart()->setMargins(mgs);
}


void MainWindow::on_cBoxAnimation_2_currentIndexChanged(int index)
{
    ui->chartView->chart()->setAnimationOptions((QChart::AnimationOption)index);
}


void MainWindow::on_cBoxTheme_2_currentIndexChanged(int index)
{
    ui->chartView->chart()->setTheme(QChart::ChartTheme(index));
}


void MainWindow::on_radioSeries0_2_clicked()
{
    if(ui->radioSeries0_2->isChecked())
    {
        curSeries=(QLineSeries*)ui->chartView->chart()->series().at(0);
    }
    else
    {
        curSeries=(QLineSeries*)ui->chartView->chart()->series().at(1);
    }

    ui->editSeriesName_2->setText(curSeries->name());
    ui->chkSeriesVisible_2->setChecked(curSeries->isVisible());
    ui->chkPointVisible_2->setChecked(curSeries->pointsVisible());
    ui->sliderSeriesOpacity_2->setValue(curSeries->opacity()*10);
    ui->chkPointLabelVisible_2->setChecked(curSeries->pointLabelsVisible());
}

void MainWindow::on_radioSeries1_2_clicked()
{
    on_radioSeries0_2_clicked();
}


void MainWindow::on_btnSeriesName_2_clicked()
{
    curSeries->setName(ui->editSeriesName_2->text());
}


void MainWindow::on_chkSeriesVisible_2_clicked()
{
    curSeries->setVisible(ui->chkSeriesVisible_2->isChecked());
}


void MainWindow::on_chkPointVisible_2_clicked(bool checked)
{
    curSeries->setPointsVisible(checked);
}


void MainWindow::on_btnSeriesColor_2_clicked()
{
    QColor color=curSeries->color();
    color=QColorDialog::getColor(color);
    if(color.isValid())
    {
        curSeries->setColor(color);
    }
}


void MainWindow::on_btnSeriesPen_2_clicked()
{
    bool ok=false;
    QPen pen=curSeries->pen();
    pen=DialogPen::getPen(pen,ok);
    if(ok)
    {
        curSeries->setPen(pen);
    }
}


void MainWindow::on_sliderSeriesOpacity_2_valueChanged(int value)
{
    curSeries->setOpacity(value/10.0);
}


void MainWindow::on_chkPointLabelVisible_2_clicked(bool checked)
{
    curSeries->setPointLabelsVisible(checked);
}


void MainWindow::on_btnSeriesLabColor_2_clicked()
{
    QColor color=curSeries->pointLabelsColor();
    color=QColorDialog::getColor(color);
    if(color.isValid())
    {
        curSeries->setPointLabelsColor(color);
    }
}


void MainWindow::on_btnSeriesLabFont_2_clicked()
{
    QFont font=curSeries->pointLabelsFont();
    bool ok=false;
    font=QFontDialog::getFont(&ok,font);
    if(ok)
    {
       curSeries->setPointLabelsFont(font);
    }
}


void MainWindow::on_radioSeriesLabFormat0_2_clicked()
{
    if(ui->radioSeriesLabFormat0_2->isChecked())
    {
        curSeries->setPointLabelsFormat("@yPoint");
    }
    else
    {
        curSeries->setPointLabelsFormat("(@xPoint,@yPoint)");
    }
}


void MainWindow::on_radioSeriesLabFormat1_2_clicked()
{
    on_radioSeriesLabFormat0_2_clicked();
}


void MainWindow::on_radioX_2_clicked()
{
    //获取当前坐标轴
    // 在Qt 5.12.1中编译时提示 QChart::axisX()和QChart::axisY()函数过时，应使用 QChart::axes()函数
    //    if (ui->radioX->isChecked())
    //        curAxis=(QValueAxis*)ui->chartView->chart()->axisX();
    //    else
    //        curAxis=(QValueAxis*)ui->chartView->chart()->axisY();

    //  下面是针对Qt 5.12.1修改的代码
    QList<QAbstractAxis*> axes;
    if (ui->radioX_2->isChecked())
        axes=ui->chartView->chart()->axes(Qt::Horizontal);
    else
        axes=ui->chartView->chart()->axes(Qt::Vertical);
    curAxis=(QValueAxis*)axes[0];


    //获取坐标轴的各种属性，显示到界面上
    ui->spinAxisMin_2->setValue(curAxis->min());
    ui->spinAxisMax_2->setValue(curAxis->max());

    ui->editAxisTitle_2->setText(curAxis->titleText());
    ui->chkBoxAxisTitle_2->setChecked(curAxis->isTitleVisible());

    ui->editAxisLabelFormat_2->setText(curAxis->labelFormat());
    ui->chkBoxLabelsVisible_2->setChecked(curAxis->labelsVisible());

    ui->chkGridLineVisible_2->setChecked(curAxis->isGridLineVisible());
    ui->chkAxisLineVisible_2->setChecked(curAxis->isLineVisible());

    ui->spinTickCount_2->setValue(curAxis->tickCount());
    ui->chkAxisLineVisible_2->setChecked(curAxis->isLineVisible());

    ui->spinMinorTickCount_2->setValue(curAxis->minorTickCount());
    ui->chkMinorTickVisible_2->setChecked(curAxis->isMinorGridLineVisible());
}


void MainWindow::on_radioY_2_clicked()
{
    on_radioX_2_clicked();
}


void MainWindow::on_chkBoxVisible_2_clicked(bool checked)
{
    curSeries->setVisible(checked);
}


void MainWindow::on_btnSetAxisRange_2_clicked()
{
    curAxis->setRange(ui->spinAxisMin_2->value(),
                      ui->spinAxisMax_2->value());
}


void MainWindow::on_btnAxisSetTitle_2_clicked()
{
    curAxis->setTitleText(ui->editAxisTitle_2->text());
}


void MainWindow::on_chkBoxAxisTitle_2_clicked(bool checked)
{
    curAxis->setTitleVisible(checked);
}


void MainWindow::on_pushButton_2_clicked()
{
    curAxis->setLabelFormat(ui->editAxisLabelFormat_2->text());
}


void MainWindow::on_btnAxisLabelColor_2_clicked()
{
    QColor   color=curAxis->labelsColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
        curAxis->setLabelsColor(color);
}


void MainWindow::on_btnAxisLabelFont_2_clicked()
{
    QFont   font=curAxis->labelsFont();

    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        curAxis->setLabelsFont(font);
}


void MainWindow::on_chkBoxLabelsVisible_2_clicked(bool checked)
{
    curAxis->setLabelsVisible(checked);
}


void MainWindow::on_chkGridLineVisible_2_clicked(bool checked)
{
    curAxis->setGridLineVisible(checked);
}


void MainWindow::on_btnGridLineColor_2_clicked()
{
    QColor   color=curAxis->gridLineColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
        curAxis->setGridLineColor(color);
}


void MainWindow::on_pushButton_11_clicked()
{
    QPen    pen;
    pen=curAxis->gridLinePen();

    bool    ok=false;
    pen=DialogPen::getPen(pen,ok);

    if (ok)
        curAxis->setGridLinePen(pen);
}


void MainWindow::on_spinTickCount_2_valueChanged(int arg1)
{
    curAxis->setTickCount(arg1);
}


void MainWindow::on_spinMinorTickCount_2_valueChanged(int arg1)
{
    curAxis->setMinorTickCount(arg1);
}


void MainWindow::on_chkAxisLineVisible_2_clicked(bool checked)
{
    curAxis->setLineVisible(checked);
}


void MainWindow::on_btnAxisLinePen_2_clicked()
{
    QPen    pen;
    pen=curAxis->linePen();

    bool    ok=false;
    pen=DialogPen::getPen(pen,ok);

    if (ok)
        curAxis->setLinePen(pen);
}


void MainWindow::on_btnAxisLinePenColor_2_clicked()
{
    QColor   color=curAxis->linePenColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
        curAxis->setLinePenColor(color);
}


void MainWindow::on_chkMinorTickVisible_2_clicked(bool checked)
{
    curAxis->setMinorGridLineVisible(checked);
}


void MainWindow::on_btnMinorColor_2_clicked()
{
    QColor   color=curAxis->linePenColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
        curAxis->setLinePenColor(color);
}


void MainWindow::on_btnMinorPen_2_clicked()
{
    QPen    pen;
    pen=curAxis->minorGridLinePen();

    bool    ok=false;
    pen=DialogPen::getPen(pen,ok);

    if (ok)
        curAxis->setMinorGridLinePen(pen);
}


void MainWindow::on_btnAxisSetTitleFont_2_clicked()
{
    QFont   font=curAxis->titleFont();

    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        curAxis->setTitleFont(font);
}

