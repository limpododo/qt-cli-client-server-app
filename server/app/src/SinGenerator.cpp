#include "SinGenerator.h"

QByteArray SinGenerator::getData() {
    QByteArray data;
    QDataStream stream(&data, QIODeviceBase::WriteOnly);

    for (int i = 0; i < NB_OF_SAMPLES; i++)
    {
        stream << int(AMPLITUDE * sin(angle) + OFFSET);
        angle += (2 * M_PI) / NB_OF_SAMPLES;
    }

    return data;
}

