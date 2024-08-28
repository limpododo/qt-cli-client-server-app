#include "BinFileWriter.h"

void BinFileWriter::write(const char *pBuffer, const quint32 size) {
    if(pFile->open(QIODevice::WriteOnly)) {
        QDataStream stream(pFile);
        stream.writeBytes(pBuffer, size);
    }
}
