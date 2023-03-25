#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QSpinBox>
class Delegate : public QItemDelegate
{
    Q_OBJECT
public:
    Delegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    setModelData(QWidget * );
};

#endif // DELEGATE_H
