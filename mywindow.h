#ifndef MYWINDOW
#define MYWINDOW
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

class MyWindow : public QDialog {
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);

private:
    QLabel *lbl;
    QLineEdit *line;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton *close;

private slots:
    void OkClicked();
    void TextChanged(QString str);
signals:
    void Simple(QString str);
    void Register(QString str);
    void Inverse(QString str);
    void InverseAndRegister(QString str);
};
class str:public QObject{
    Q_OBJECT
public slots:
    void Simple(QString str){
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
    void Inversion(QString str){
        QString result = str;
        for(int i = str.length() - 1, j = 0; i >= 0; i--, j++)
            result[j] = str[i];
        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
    void Register(QString str){
        str = str.toUpper();
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
    void InverseAndRegister(QString str){
        QString result = str;
        for(int i = str.length() - 1, j = 0; i >= 0; i--, j++)
            result[j] = str[i];
        result = result.toUpper();
        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
};

#endif // MYWINDOW

