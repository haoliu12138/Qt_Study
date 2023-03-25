#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QtCore>
#include <QtGui>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = 0);

signals:
    void linkClicked(const QString&);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

public slots:
};

#endif // FILTER_H
