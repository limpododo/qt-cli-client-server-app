#ifndef INOBITEC_TEST_TASK_BINFILEWRITER_H
#define INOBITEC_TEST_TASK_BINFILEWRITER_H

#include <QFile>
#include "interfaces/IWriter.h"

class BinFileWriter: public IWriter {
    QFile *pFile;

public:
    explicit BinFileWriter(const QString& path): pFile(new QFile(path)) {};
    inline ~BinFileWriter() { pFile->deleteLater(); }

    inline void setPath(const QString& path) { pFile->deleteLater(); pFile = new QFile(path); }
    inline QString getPath() { return pFile->fileName(); }

    void write(const char* pData, quint32 size) override;
};


#endif //INOBITEC_TEST_TASK_BINFILEWRITER_H
