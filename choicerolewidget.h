#ifndef CHOICEROLEWIDGET_H
#define CHOICEROLEWIDGET_H

#include <QWidget>

namespace Ui {
class ChoiceRoleWidget;
}

class ChoiceRoleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChoiceRoleWidget(QWidget *parent = 0);
    ~ChoiceRoleWidget();

private slots:
    void on_backButton_clicked();

private:
    Ui::ChoiceRoleWidget *ui;
};

#endif // CHOICEROLEWIDGET_H
