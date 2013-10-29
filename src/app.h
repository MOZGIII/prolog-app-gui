#ifndef APP_H
#define APP_H

#include <QWidget>

namespace Ui {
class App;
}

class App : public QWidget
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

private:
    Ui::App *ui;

public slots:
    void writeLog(const QString &text);
    void writePayload(const QString &text);

private slots:
    void on_payloadCalculate_clicked();
};

#endif // APP_H