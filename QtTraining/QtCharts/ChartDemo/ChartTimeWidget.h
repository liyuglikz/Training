#ifndef CHARTTIMEWIDGET_H
#define CHARTTIMEWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QPointF>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>

#include <QVBoxLayout>

// a Chart struct: for chart's parts
struct ChartTime{
    QtCharts::QDateTimeAxis axisX;
    QtCharts::QValueAxis axisY;

    QtCharts::QChartView chartview;
    QtCharts::QChart chart_main;	// main chart in widget
    QtCharts::QLineSeries line_series;

    int range_max = 0;
};


// ChartTimeWidget for show the chart
// struct: QValueAxis->QLineSeries->QChart->QChartView -> QVBoxLayout
// struct: axisX/Y 	-> line_series->chart_main->chartview->layout_main->widget(self)

class ChartTimeWidget : public QWidget
{
    Q_OBJECT
    public slots:
        void slot_test();
    public:
        ChartTimeWidget( QWidget *parent = 0);
        ~ChartTimeWidget();

        void append( const double &k);

        // X setup:
        void setXRange( QDateTime left, QDateTime right);
        void setXFormat( const char *s = NULL);
        void setXFormat( const QString &s);
        void setXTitleText( const char *s = NULL);
        void setXTitleText( const QString &s);

        void setXTickCount( const int &k);
        int getXTickCount() const;

        // Y setup:
        void setYRange( const int &left, const int &right);
        void setYLabelFormat( const char *s = NULL);
        void setYLabelFormat( const QString &s);
        void setYTitleText( const char *s = NULL);
        void setYTitleText( const QString &s);

        void setYTickCount( const int &k);
        int getYTickCount() const;

        // chart setup:
        void setChartTitle( const char *s = NULL);
        void setChartTitle( const QString &s);

    private:
        ChartTime *chart;
        QVBoxLayout *layout_main;
};

#endif
