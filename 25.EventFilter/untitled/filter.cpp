#include "filter.h"

Filter::Filter(QObject *parent) : QObject(parent)
{

}
bool Filter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::WhatsThisClicked)
    {
        QWhatsThisClickedEvent* wtcEvent=static_cast<QWhatsThisClickedEvent*>(event);
        emit linkClicked(wtcEvent->href());
        return true;
    }
    return false;
}
