#ifndef INOBITEC_TEST_TASK_BINFILEWRITER_H
#define INOBITEC_TEST_TASK_BINFILEWRITER_H

#include <QFile>
#include "interfaces/IWriter.h"

class BinFileWriter: public IWriter {
    QString path;
    QFile *pFile;
public:
    BinFileWriter() = default;
    BinFileWriter(const QString& path): path(path), pFile(new QFile(path)) {};
    inline ~BinFileWriter() { delete pFile; }

    inline void setPath(const QString& path) { delete pFile; this->path = path; pFile = new QFile(this->path); }
    inline QString getPath() { return path; }
    void write(const char *pBuffer, const quint32 size) override;
};


#endif //INOBITEC_TEST_TASK_BINFILEWRITER_H
