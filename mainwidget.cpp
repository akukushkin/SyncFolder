#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QFileDialog>
#include <choicerolewidget.h>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::on_cancelButton_clicked() {
    this->close();
}

void MainWidget::on_browseButton_clicked() {
    QString path = QFileDialog::getExistingDirectory(this,
                                                     tr("Choose folder"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks
                                                    );

    ui->pathFolderEdit->setText(path);
}

void MainWidget::on_continueButton_clicked() {
    if (ui->pathFolderEdit->text().isEmpty())
        return;
    this->hide();
    ChoiceRoleWidget* rw = new ChoiceRoleWidget();
    rw->show();
    connect(rw, SIGNAL(destroyed()), this, SLOT(close()));
}
