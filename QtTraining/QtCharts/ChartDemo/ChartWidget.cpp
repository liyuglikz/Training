#include "ChartWidget.h"
#include <QVector>

ChartWidget::ChartWidget(QWidget *parent ) : QWidget(parent)
{
	this->chart = new Chart();
	this->chart->range_max = 1000;

	// 1 chart & chartview init:
	this->chart->chartview.setChart( &(this->chart->chart_main) );

	// 2 axis init:
	this->setXRange( 0, 100);
	this->setXLabelFormat( "%g" );
	this->setXTitleText("Time");

	this->setYRange(0, 100);
	this->setYLabelFormat("%g");
	this->setYTitleText("Value");

	// 4 add axis to chart
	this->chart->chart_main.addSeries( &(this->chart->line_series) );
	this->chart->chart_main.setAxisX( &(this->chart->axisX), &(this->chart->line_series) );	
	this->chart->chart_main.setAxisY( &(this->chart->axisY), &(this->chart->line_series) );	
	this->chart->chart_main.legend()->hide ();
	this->chart->chart_main.setTitle("Real Time Data");

	// 5 layout init:
	this->layout_main = new QVBoxLayout();
	this->layout_main->addWidget( &(this->chart->chartview ));
	this->setLayout( this->layout_main );
}

ChartWidget::~ChartWidget()
{
	delete this->chart;
	delete this->layout_main;
}

void ChartWidget::append( QPointF point)
{
	QVector<QPointF> points = this->chart->line_series.pointsVector();
	if( points.count() >= this->chart->range_max )
	{
		points.pop_front();
	}
	points.push_back( point );
	this->chart->line_series.replace( points );
}

// X axis setup: range, label format, Title
void ChartWidget::setXRange( const int &left, const int &right)
{	this->chart->axisX.setRange( left, right);}

void ChartWidget::setXLabelFormat( const char *s )
{ 	this->setXTitleText( QString(s) );}

void ChartWidget::setXLabelFormat( const QString &s )
{	this->chart->axisX.setLabelFormat( s );}

void ChartWidget::setXTitleText( const char *s )
{	this->setXTitleText( QString(s) );}

void ChartWidget::setXTitleText( const QString &s )
{	this->chart->axisX.setTitleText( s );}

// X axis setup: range, label format, Title

void ChartWidget::setYRange( const int &left, const int &right)
{	this->chart->axisY.setRange(left, right);} 

void ChartWidget::setYLabelFormat( const char *s )
{ 	this->setYTitleText( QString(s) );}

void ChartWidget::setYLabelFormat( const QString &s )
{	this->chart->axisY.setLabelFormat( s );}

void ChartWidget::setYTitleText( const char *s )
{	this->setXTitleText( QString(s) );}

void ChartWidget::setYTitleText( const QString &s )
{	this->chart->axisY.setTitleText( s );}
