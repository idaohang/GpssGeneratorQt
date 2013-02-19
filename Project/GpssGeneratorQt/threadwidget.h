#ifndef THREADWIDGET_H
#define THREADWIDGET_H
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <vector>

using std::vector;

namespace GeneratorGpss
{

class ThreadWidget : public QWidget
{
    Q_OBJECT

public:
    ThreadWidget(QWidget *parent=0);
    virtual ~ThreadWidget();
private:
    vector<QWidget*> curParams;     //текущие параметры потока
    QHBoxLayout *mainLayout;
    QComboBox *threadType;
    QComboBox *threadFunc;
    QLineEdit *param1;
    QLineEdit *param2;
    QLineEdit *param3;
    QComboBox *priorityType;
    QLineEdit *priorityValue;
    QLabel *threadFuncLbl;
    QLabel *param1Lbl;
    QLabel *param2Lbl;
    QLabel *param3Lbl;

public slots:
    void typeChanged(int i);
    void funcChanged(int i);
};
}
#endif // THREADWIDGET_H
