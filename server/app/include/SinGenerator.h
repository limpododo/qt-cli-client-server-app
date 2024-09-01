#ifndef INOBITEC_TEST_TASK_SINGENERATOR_H
#define INOBITEC_TEST_TASK_SINGENERATOR_H


#include <QByteArray>
#include <QIODeviceBase>
#include <QDataStream>

#include "interfaces/IDataGenerator.h"

#define NB_OF_SAMPLES 32
#define OFFSET        3276
#define AMPLITUDE     32767

class SinGenerator: public IDataGenerator {
    double angle;
public:
    SinGenerator(): angle(0) {};
    ~SinGenerator() = default;

    QByteArray getData() override;
};


#endif //INOBITEC_TEST_TASK_SINGENERATOR_H
