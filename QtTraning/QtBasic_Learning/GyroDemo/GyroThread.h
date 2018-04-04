#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QGyroscope>


class GyroThread : public QThread
{
    Q_OBJECT
signals:
    void transData(double x, double y, double z);
    void transDataM(double x, double y, double z, int button);
public slots:
    void sendRightClick();
    void sendLeftClick();
public:
    explicit GyroThread(QObject *parent = 0);
    ~GyroThread();

    void start(Priority p = QThread::NormalPriority);
    void pause();

    void run();
    void setT(const int &k);
    int getT();

private:
    QGyroscope gs1;
    QGyroscopeReading *gsreader;

    bool flag;
    double X, Y, Z;
    int t;
};

#endif // THREAD_H
