#ifndef EXTINF_H
#define EXTINF_H
#include <QString>

class EXTINF
{

public:
    EXTINF();
    QString m3u8;
    QString dir;
    int index;
    QString ts;
    QString tsName;
    bool encrypt;

};
#endif // EXTINF_H
