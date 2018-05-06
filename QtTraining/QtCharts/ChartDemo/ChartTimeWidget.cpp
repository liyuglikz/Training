#include "ChartTimeWidget.h"
#include <QVector>
#include <QDebug>

ChartTimeWidget::ChartTimeWidget(QWidget *parent ) : QWidget(parent)
{
    this->chart = new ChartTime();
    this->chart->range_max = 1000;

    // 1 chart & chartview init:
    this->chart->chartview.setChart( &(this->chart->chart_main) );

    // 2 axis init:
//    this->setXFormat("YYYY MMM HH:MM:SS");
    this->setXFormat("hh:mm:ss");
    this->setXTitleText("Time");
    this->setXTickCount(10);

    this->setYRange(0, 100);
    this->setYLabelFormat( "%g" );
    this->setYTitleText("Value");

    // 4 add axis to chart
    this->chart->chart_main.addSeries( &(this->chart->line_series) );

    this->chart->chart_main.setAxisX( &(this->chart->axisX), &(this->chart->line_series) );
    this->chart->chart_main.setAxisY( &(this->chart->axisY), &(this->chart->line_series) );

//    this->chart->line_series.attachAxis( &(this->chart->axisX) );
//    this->chart->line_series.attachAxis( &(this->chart->axisY) );

    this->chart->chart_main.legend()->hide ();
    this->chart->chart_main.setTitle("Real Time Data");

    // 5 layout init:
    this->layout_main = new QVBoxLayout();
    this->layout_main->addWidget( &(this->chart->chartview ));
    this->setLayout( this->layout_main );
}

ChartTimeWidget::~ChartTimeWidget()
{
    delete this->chart;
    delete this->layout_main;
}

void ChartTimeWidget::append( const double &k)
{
    /*
    QVector<QPointF> points = this->chart->line_series.pointsVector();
    if( points.count() >= this->chart->range_max )
    {
        points.pop_front();
    }
    points.push_back( QPointF( (QDateTime::currentDateTime()).toMSecsSinceEpoch(), k) );
    this->chart->line_series.replace( points );
    */
    this->chart->line_series.append( (QDateTime::currentDateTime()).toMSecsSinceEpoch(),
                                     k);
}

// X axis setup: range, label format, Title
void ChartTimeWidget::setXRange( QDateTime left, QDateTime right)
{	this->chart->axisX.setRange( left, right);}

void ChartTimeWidget::setXFormat( const char *s )
{ 	this->setXTitleText( QString(s) );}

void ChartTimeWidget::setXFormat( const QString &s )
{	this->chart->axisX.setFormat( s );}

void ChartTimeWidget::setXTitleText( const char *s )
{	this->setXTitleText( QString(s) );}

void ChartTimeWidget::setXTitleText( const QString &s )
{	this->chart->axisX.setTitleText( s );}

void ChartTimeWidget::setXTickCount(const int &k)
{	this->chart->axisX.setTickCount(k);}

int ChartTimeWidget::getXTickCount() const
{	return this->chart->axisX.tickCount();}

// X axis setup: range, label format, Title

void ChartTimeWidget::setYRange( const int &left, const int &right)
{	this->chart->axisY.setRange(left, right);}

void ChartTimeWidget::setYLabelFormat( const char *s )
{ 	this->setYLabelFormat( QString(s) );}

void ChartTimeWidget::setYLabelFormat( const QString &s )
{	this->chart->axisY.setLabelFormat( s );}

void ChartTimeWidget::setYTitleText( const char *s )
{	this->setYTitleText( QString(s) );}

void ChartTimeWidget::setYTitleText( const QString &s )
{	this->chart->axisY.setTitleText( s );}

void ChartTimeWidget::setYTickCount(const int &k)
{	this->chart->axisY.setTickCount(k);}

int ChartTimeWidget::getYTickCount() const
{	return this->chart->axisY.tickCount();}


// chart setup:
void ChartTimeWidget::setChartTitle( const char *s)
{	this->setChartTitle( QString(s) );}

void ChartTimeWidget::setChartTitle(const QString &s)
{	this->chart->chart_main.setTitle( s );}


void ChartTimeWidget::slot_test()
{
    double k = (qrand() % 1000) / 10.0;
    qDebug() << "debug :" << k;
    this->append( k );
}
