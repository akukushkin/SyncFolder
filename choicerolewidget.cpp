#include "choicerolewidget.h"
#include "ui_choicerolewidget.h"

#include "inputdatawidget.h"

#define CLIENT_TITLE "Enter IP Adress:"
#define SERVER_TITLE "Enter port:"

ChoiceRoleWidget::ChoiceRoleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoiceRoleWidget)
{
    ui->setupUi(this);
}

ChoiceRoleWidget::~ChoiceRoleWidget() {
    delete ui;
}

void ChoiceRoleWidget::on_backButton_clicked() {
    this->hide();
}

void ChoiceRoleWidget::on_continueButton_clicked() {
    bool isCheckedServer = ui->serverRadioButton->isChecked();
    QString title = isCheckedServer ? SERVER_TITLE : CLIENT_TITLE;

    this->hide();
    InputDataWidget* iw = new InputDataWidget(title);
    connect(iw, SIGNAL(destroyed()), this, SLOT(close()));
    iw->show();
}
