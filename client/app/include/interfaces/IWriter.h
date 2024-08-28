#ifndef INOBITEC_TEST_TASK_IWRITER_H
#define INOBITEC_TEST_TASK_IWRITER_H

#include <QString>

class IWriter {
public:
    virtual void write(const char*, const quint32) = 0;
};

#endif //INOBITEC_TEST_TASK_IWRITER_H
