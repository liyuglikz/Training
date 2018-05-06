#include "ChartTimeWidget.h"
#include <QVector>
#include <QDebug>

ChartTimeWidget::ChartTimeWidget(QWidget *parent ) : QWidget(parent)
{
    this->chart = new ChartTime();
    this->chart->range_max = 1000;

    // 1 chart & chartview init:
    this->chart->chartview.setChart( &(this->chart->chart_main) );
    this->chart->chartview.setRenderHint( QPainter::Antialiasing);

    // 2 axis init:
    this->setXFormat("hh:mm:ss");
    this->chart->axisX.setMax(QDateTime::currentDateTime().addMSecs(+5500));
    this->chart->axisX.setMin(QDateTime::currentDateTime().addMSecs(-4500));
    this->setXTitleText("Time");
    this->setXTickCount(11);

    this->setYRange(0, 100);
    this->setYTickCount(11);
    this->setYLabelFormat( "%g" );
    this->setYTitleText("Value");

    // 4 add axis to chart
    this->chart->chart_main.addSeries( &(this->chart->line_series) );

    this->chart->chart_main.setAxisX( &(this->chart->axisX), &(this->chart->line_series) );
    this->chart->chart_main.setAxisY( &(this->chart->axisY), &(this->chart->line_series) );


    this->chart->chart_main.setAnimationOptions(QtCharts::QChart::AllAnimations);
    this->chart->chart_main.legend()->hide ();
    this->chart->chart_main.setTitle("Real Time Data");

    // 5 layout init:
    this->layout_main = new QVBoxLayout();
    this->layout_main->addWidget( &(this->chart->chartview ));
    this->setLayout( this->layout_main );

    this->chart->x_unit = (this->chart->axisX.max().toSecsSinceEpoch() - this->chart->axisX.min().toSecsSinceEpoch()) / (this->getXTickCount() - 1);
}

ChartTimeWidget::~ChartTimeWidget()
{
    delete this->chart;
    delete this->layout_main;
}

void ChartTimeWidget::append( const double &k)
{
    this->chart->x_unit_plot = this->chart->chart_main.plotArea().width() / (this->getXTickCount() - 1);
    if( this->chart->line_series.count() > 0)
    {
        QPointF point_time_last = this->chart->line_series.at( this->chart->line_series.count() - 1);
        qint64 last_t = qint64( point_time_last.rx() );
        qint64 now_t = QDateTime::currentDateTime().toMSecsSinceEpoch();

        double time_diff_msec = now_t - last_t;
        time_diff_msec /= 1000.0;
        time_diff_msec = 1.0;
        this->chart->chart_main.scroll( this->chart->x_unit_plot * time_diff_msec, 0);
        qDebug() << now_t << "_" << last_t << time_diff_msec;
        this->chart->line_series.append( now_t,k);
    }
    else
        this->chart->chart_main.scroll( this->chart->x_unit_plot , 0);
        //this->chart->line_series.append( (QDateTime::currentDateTime()).toSecsSinceEpoch(),k);
    this->chart->line_series.append( (QDateTime::currentDateTime()).toMSecsSinceEpoch(),k);
}



// X axis setup: range, label format, Title
void ChartTimeWidget::setXRange( QDateTime left, QDateTime right)
{	this->chart->axisX.setRange( left, right);}

void ChartTimeWidget::setXFormat( const char *s )
{ 	this->setXFormat( QString(s) );}

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


void ChartTimeWidget::slot_update()
{
    this->chart->last_value += (qrand() % 10);
    this->append( this->chart->last_value);
}


void ChartTimeWidget::slot_setValue(const double &k)
{	this->setValue(k);}

void ChartTimeWidget::setValue(const double &k)
{    this->chart->last_value = k;}

double ChartTimeWidget::getValue() const
{    return this->chart->last_value;}
