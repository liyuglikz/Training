#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>

#include <QMessageBox>

#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>

class MainWindow : public QDialog
{
    Q_OBJECT

signals:

public slots:
    void pop_inputdialog();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    static const int SIZE = 32;
    int n;

    QPushButton s[SIZE];
    QVBoxLayout *layout;

    QInputDialog *p;
};

#endif // MAINWINDOW_H
