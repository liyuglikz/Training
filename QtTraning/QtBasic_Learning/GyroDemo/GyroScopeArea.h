#ifndef GYROSCOPEAREA_H
#define GYROSCOPEAREA_H

#include <QWidget>

#include "GyroThread.h"

class GyroScopeArea : public QWidget
{
    Q_OBJECT
signals:
    void emitData(double x, double y, double z);
    void emitDataM(double x, double y, double z, int button_state);
private slots:
    void transData(double x, double y, double z);
    void transDataM(double x, double y, double z, int button_state);

public slots:
    void Start();
    void Pause();

public:
    explicit GyroScopeArea(QWidget *parent = 0);
    ~GyroScopeArea();

    GyroThread *getGyroThread();

    // set sensive
    double get_xk();
    void set_xk(const double &k);

    double get_yk();
    void set_yk(const double &k);

    double get_zk();
    void set_zk(const double &k);

    // set T
    int get_T();
    void set_T(const int &k);
private:
    GyroThread *gyrothread;
    double xk, yk,zk;
};

#endif // GYROSCOPEAREA_H
