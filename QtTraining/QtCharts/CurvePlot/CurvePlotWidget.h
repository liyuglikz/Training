#ifndef CURVEPLOTWIDGET_H
#define CURVEPLOTWIDGET_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartGlobal>

class CurvePlotWidget : public QWidget
{
		Q_OBJECT
	public:
			explicit CurvePlotWidget(QWidget *parent = 0);

	private:
			QtCharts::QChart *chart_main;
			QtCharts::QLineSeries *line_series;
};

#endif
