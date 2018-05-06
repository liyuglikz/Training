#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QPointF>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

#include <QVBoxLayout>

// a Chart struct: for chart's parts
struct Chart{
	QtCharts::QValueAxis axisX;
	QtCharts::QValueAxis axisY;

	QtCharts::QChartView chartview;
	QtCharts::QChart chart_main;	// main chart in widget
	QtCharts::QLineSeries line_series;

	int range_max = 0;
};


//
class ChartWidget : public QWidget
{
	Q_OBJECT
	public:
		ChartWidget( QWidget *parent = 0);
		~ChartWidget();

		void append(QPointF point);

		// X setup:
		void setXRange( const int &left, const int &right);
		void setXLabelFormat( const char *s = NULL);
		void setXLabelFormat( const QString &s);
		void setXTitleText( const char *s = NULL);
		void setXTitleText( const QString &s);

		// Y setup:
		void setYRange( const int &left, const int &right);
		void setYLabelFormat( const char *s = NULL);
		void setYLabelFormat( const QString &s);
		void setYTitleText( const char *s = NULL);
		void setYTitleText( const QString &s);

	private:
		Chart *chart;
		QVBoxLayout *layout_main;
};

#endif
