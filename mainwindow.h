#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actZoomOut_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomReset_triggered();

    void on_actDraw_triggered();

    void on_btnSetTitleFont_2_clicked();

    void on_btnSetTitle_2_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_chkLegendVisible_2_clicked(bool checked);

    void on_chkBoxLegendBackground_2_clicked(bool checked);

    void on_btnLegendFont_2_clicked();

    void on_btnLegendlabelColor_2_clicked();

    void on_btnSetMargin_2_clicked();

    void on_cBoxAnimation_2_currentIndexChanged(int index);

    void on_cBoxTheme_2_currentIndexChanged(int index);

    void on_radioSeries0_2_clicked();

    void on_radioSeries1_2_clicked();

    void on_btnSeriesName_2_clicked();

    void on_chkSeriesVisible_2_clicked();

    void on_chkPointVisible_2_clicked(bool checked);

    void on_btnSeriesColor_2_clicked();

    void on_btnSeriesPen_2_clicked();

    void on_sliderSeriesOpacity_2_valueChanged(int value);

    void on_chkPointLabelVisible_2_clicked(bool checked);

    void on_btnSeriesLabColor_2_clicked();

    void on_btnSeriesLabFont_2_clicked();

    void on_radioSeriesLabFormat0_2_clicked();

    void on_radioSeriesLabFormat1_2_clicked();

    void on_radioX_2_clicked();

    void on_radioY_2_clicked();

    void on_chkBoxVisible_2_clicked(bool checked);

    void on_btnSetAxisRange_2_clicked();

    void on_btnAxisSetTitle_2_clicked();

    void on_chkBoxAxisTitle_2_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_btnAxisLabelColor_2_clicked();

    void on_btnAxisLabelFont_2_clicked();

    void on_chkBoxLabelsVisible_2_clicked(bool checked);

    void on_chkGridLineVisible_2_clicked(bool checked);

    void on_btnGridLineColor_2_clicked();

    void on_pushButton_11_clicked();

    void on_spinTickCount_2_valueChanged(int arg1);

    void on_spinMinorTickCount_2_valueChanged(int arg1);

    void on_chkAxisLineVisible_2_clicked(bool checked);

    void on_btnAxisLinePen_2_clicked();

    void on_btnAxisLinePenColor_2_clicked();

    void on_chkMinorTickVisible_2_clicked(bool checked);

    void on_btnMinorColor_2_clicked();

    void on_btnMinorPen_2_clicked();

    void on_btnAxisSetTitleFont_2_clicked();

private:
    Ui::MainWindow *ui;

    void createChartA();
    void prepareDataA();
    void updateFromChartA();

    QLineSeries *curSeries;
    QValueAxis *curAxis;
};
#endif // MAINWINDOW_H
