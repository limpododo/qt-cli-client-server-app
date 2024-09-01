#include "BinFileWriter.h"

void BinFileWriter::write(const char *pData, quint32 size) {
    if(pFile->open(QIODevice::Append)) {
        pFile->write(pData, size);
        pFile->close();
    }
}
