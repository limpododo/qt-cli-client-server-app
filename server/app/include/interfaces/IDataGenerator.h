#ifndef INOBITEC_TEST_TASK_IDATAGENERATOR_H
#define INOBITEC_TEST_TASK_IDATAGENERATOR_H

class IDataGenerator {
public:
    virtual QByteArray getData() = 0;
};

#endif //INOBITEC_TEST_TASK_IDATAGENERATOR_H
