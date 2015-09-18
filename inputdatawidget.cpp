#include "inputdatawidget.h"
#include "ui_inputdatawidget.h"
#include "serverwidget.h"

InputDataWidget::InputDataWidget(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputDataWidget)
{
    ui->setupUi(this);
    ui->titleLabel->setText(title);
}

InputDataWidget::~InputDataWidget() {
    delete ui;
}

void InputDataWidget::on_continueButton_clicked() {
    int port;
    ServerWidget* sw;

    port = ui->lineEdit->text().toInt();
    sw = new ServerWidget(port);
    connect(sw, SIGNAL(destroyed()), this, SLOT(close()));
    this->hide();
    sw->show();
}
