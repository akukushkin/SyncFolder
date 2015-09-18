#ifndef INPUTDATAWIDGET_H
#define INPUTDATAWIDGET_H

#include <QWidget>

namespace Ui {
class InputDataWidget;
}

class InputDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputDataWidget(const QString &title, QWidget *parent = 0);
    ~InputDataWidget();

private slots:
    void on_continueButton_clicked();

private:
    Ui::InputDataWidget *ui;
};

#endif // INPUTDATAWIDGET_H
