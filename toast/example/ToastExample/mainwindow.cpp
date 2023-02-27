#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../auto_close_float_tip.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_message_btn_clicked()
{
    AutoCloseFloatTip::message(window(), "hahaha.");
}


void MainWindow::on_success_btn_clicked()
{
    AutoCloseFloatTip::success(window(), "Shared link coped.");
}


void MainWindow::on_error_btn_clicked()
{
    AutoCloseFloatTip::error(window(), "Network error, please try again.");
}

