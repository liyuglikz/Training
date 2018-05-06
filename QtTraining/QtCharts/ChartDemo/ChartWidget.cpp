#include "ChartWidget.h"
#include <QVector>
#include <QDebug>

ChartWidget::ChartWidget(QWidget *parent ) : QWidget(parent)
{
	this->chart = new Chart();
	this->chart->range_max = 1000;

	// 1 chart & chartview init:
	this->chart->chartview.setChart( &(this->chart->chart_main) );
    this->chart->chartview.setRenderHint( QPainter::Antialiasing);

	// 2 axis init:
	this->setXRange( 0, 100);
	this->setXLabelFormat( "%g" );
	this->setXTitleText("Time");
    this->setXTickCount(11);

	this->setYRange(0, 100);
	this->setYLabelFormat("%g");
	this->setYTitleText("Value");
    this->setYTickCount(11);


	// 4 add axis to chart
	this->chart->chart_main.addSeries( &(this->chart->line_series) );
	this->chart->chart_main.setAxisX( &(this->chart->axisX), &(this->chart->line_series) );	
	this->chart->chart_main.setAxisY( &(this->chart->axisY), &(this->chart->line_series) );	
    this->chart->chart_main.legend()->hide ();
	this->chart->chart_main.setTitle("Real Time Data");
    this->chart->chart_main.setAnimationOptions(QtCharts::QChart::AllAnimations);

	// 5 layout init:
	this->layout_main = new QVBoxLayout();
	this->layout_main->addWidget( &(this->chart->chartview ));
	this->setLayout( this->layout_main );

    this->chart->x_unit = (this->chart->axisX.max() - this->chart->axisX.min()) / (this->getXTickCount() - 1);
}

ChartWidget::~ChartWidget()
{
	delete this->chart;
	delete this->layout_main;
}

void ChartWidget::append( QPointF point)
{
    this->chart->line_series.append( point );
}

void ChartWidget::append_scroll( double y)
{
    // width would change dynamic
    this->chart->x_unit_plot = this->chart->chart_main.plotArea().width() / (this->getXTickCount() - 1);
    static int x = 50;
    x += this->chart-> x_unit;

    this->chart->line_series.append( QPointF(x, y) );
    this->chart->chart_main.scroll(this->chart->x_unit_plot, 0);
}

// X axis setup: range, label format, Title
void ChartWidget::setXRange( const int &left, const int &right)
{	this->chart->axisX.setRange( left, right);}

void ChartWidget::setXLabelFormat( const char *s )
{ 	this->setXLabelFormat(QString(s) );}

void ChartWidget::setXLabelFormat( const QString &s )
{	this->chart->axisX.setLabelFormat( s );}

void ChartWidget::setXTitleText( const char *s )
{	this->setXTitleText( QString(s) );}

void ChartWidget::setXTitleText( const QString &s )
{	this->chart->axisX.setTitleText( s );}

void ChartWidget::setXTickCount(const int &k)
{	this->chart->axisX.setTickCount(k);}

int ChartWidget::getXTickCount() const
{	return this->chart->axisX.tickCount();}

// X axis setup: range, label format, Title

void ChartWidget::setYRange( const int &left, const int &right)
{	this->chart->axisY.setRange(left, right);} 

void ChartWidget::setYLabelFormat( const char *s )
{ 	this->setYLabelFormat( QString(s) );}

void ChartWidget::setYLabelFormat( const QString &s )
{	this->chart->axisY.setLabelFormat( s );}

void ChartWidget::setYTitleText( const char *s )
{	this->setYTitleText( QString(s) );}

void ChartWidget::setYTitleText( const QString &s )
{	this->chart->axisY.setTitleText( s );}

void ChartWidget::setYTickCount(const int &k)
{	this->chart->axisY.setTickCount(k);}

int ChartWidget::getYTickCount() const
{	return this->chart->axisY.tickCount();}

// chart setup:
void ChartWidget::setChartTitle( const char *s)
{	this->setChartTitle( QString(s) );}

void ChartWidget::setChartTitle(const QString &s)
{	this->chart->chart_main.setTitle( s );}

void ChartWidget::slot_test()
{
    double y = qrand() % 100;
    this->append_scroll(y);
}
