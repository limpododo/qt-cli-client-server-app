#include "BinFileWriter.h"

void BinFileWriter::write(const char *data, const quint32 size) {
    if(pFile->open(QIODevice::Append)) {
        pFile->write(data, size);
        pFile->close();
    }
}
