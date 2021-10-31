#ifndef WIDGETSKELETON_H
#define WIDGETSKELETON_H

#include <QApplication>
#include <QLabel>
#include <QLineEdit>


class WidgetSkeleton : public QWidget {
    
  Q_OBJECT

  public:
    explicit WidgetSkeleton(QWidget *parent = 0);

  private slots:
    void sayHello();

  private:
    QLineEdit* m_nameEntry;
    QLabel* m_output;

};

#endif
