#include "widgetskeleton.h"
#include <QGridLayout>
#include <QPushButton>

WidgetSkeleton::WidgetSkeleton(QWidget *parent): QWidget(parent)
{
  QPushButton* sendBtn = new QPushButton("send", this);
  QLabel *lbl = new QLabel("Your Name:", this);
  m_nameEntry = new QLineEdit();
  m_output = new QLabel("", this);
  
  QGridLayout *grid = new QGridLayout(this);
  grid->addWidget(lbl, 0, 0); // row, column
  grid->addWidget(m_nameEntry, 0, 1);
  grid->addWidget(sendBtn, 0, 2);
  grid->addWidget(m_output, 1, 1);
  setLayout(grid);  
  
  // Signal -> slot
  connect(sendBtn, &QPushButton::clicked, this, &WidgetSkeleton::sayHello);
}

void WidgetSkeleton::sayHello() 
{
    m_output->setText("Hi " + m_nameEntry->text() + "!");
}


