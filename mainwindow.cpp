#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("EmmcHaccGui");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonBox_rejected()
{
    this->close();
}


void MainWindow::on_buttonBox_accepted()
{
    std::string cmd = "..\\emmchaccgen.exe --fw " + fw + " --keys " + keys + " "
                       + exfat + verbose + nca + autorcm + mariko;
    system(cmd.c_str());
    this->close();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    arg1 == 2 ? exfat = " " : exfat = " --no-exfat ";
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    arg1 == 2 ? mariko = " --mariko " : mariko = " ";
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(mariko == " ") {
        arg1 == 2 ? autorcm = " " : autorcm = " --no-autorcm ";
    } else {
        autorcm = " --no-autorcm ";
    }
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    arg1 == 2 ? hashes = " --fix-hashes " : hashes = " ";
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    arg1 == 2 ? verbose = " --verbose " : verbose = " ";
}

void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    arg1 == 2 ? nca = " --show-nca-index " : nca = " ";
}

void MainWindow::on_toolButton_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    QString path = QFileDialog::getExistingDirectory(this, tr("Choose folder"), QDir::currentPath(), QFileDialog::ReadOnly);
    fw = path.toStdString();
    ui->plainTextEdit->setPlainText(path);
}


void MainWindow::on_toolButton_2_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString path = QFileDialog::getOpenFileName(this, tr("Choose folder"), QDir::currentPath());
    keys = path.toStdString();
    ui->plainTextEdit_2->setPlainText(path);
}
