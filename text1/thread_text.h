#ifndef THREAD_TEXT_H
#define THREAD_TEXT_H
#include "QThread"

class thread_text : public QThread
{
public:
    thread_text();
    void run();
    int count = 0;
};

#endif // THREAD_TEXT_H
