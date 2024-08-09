#ifndef TXT2PLY_H
#define TXT2PLY_H
#include <qdebug.h>
#include <qstring.h>
#include <QThread>

#include <vector>

using namespace std;
struct Vertex
{
    float x, y, z;
};


class Txt2Ply: public QThread {
    Q_OBJECT
private:
    vector<Vertex> readVerticesFromTxt(const QString &filename);
    void writeVerticesToPly(const vector<Vertex> &vertices, const QString &fileName);
signals:
    void processingFinished();
public:
    Txt2Ply(){};
    void translate(const QString &inputFilename,const QString &outputFileName);
};
#endif // TXT2PLY_H
