#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>

#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::string exfat   = " ";
    std::string mariko  = " ";
    std::string verbose = " ";
    std::string hashes  = " ";
    std::string autorcm = " ";
    std::string nca     = " ";
    std::string fw;
    std::string keys;
};
#endif // MAINWINDOW_H
