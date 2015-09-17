#include "choicerolewidget.h"
#include "ui_choicerolewidget.h"

ChoiceRoleWidget::ChoiceRoleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoiceRoleWidget)
{
    ui->setupUi(this);
}

ChoiceRoleWidget::~ChoiceRoleWidget()
{
    delete ui;
}

void ChoiceRoleWidget::on_backButton_clicked()
{
    this->hide();
}
