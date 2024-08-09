#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "txt2ply.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class a;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void isProcessing(bool);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void startProcessing();
    void finishProcessing();

private:
    Ui::a *ui;
    Txt2Ply *fileProcessor;

};
#endif // WIDGET_H
