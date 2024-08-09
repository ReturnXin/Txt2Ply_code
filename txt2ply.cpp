#include "txt2ply.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <synchapi.h>
#include <QDebug>

#include "txt2ply.h"

vector<Vertex> Txt2Ply::readVerticesFromTxt(const QString &QFilename)
{
    vector<Vertex> vertices;
    string filename = QFilename.toStdString();
    ifstream file(filename);
    if (!file.is_open())
    {
        qDebug() << "Unable to open file: " << filename << "\n";
        return vertices; // 文件无法打开时返回-1
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        Vertex vertex;
        if (iss >> vertex.x >> vertex.y >> vertex.z)
        {
            vertices.push_back(vertex);
        }
    }

    file.close();
    return vertices;
}

void Txt2Ply::writeVerticesToPly(const vector<Vertex> &vertices, const QString &QFilename)
{
    string filename = QFilename.toStdString();
    ofstream outfile(filename);

    if (outfile.is_open())
    {
        outfile << "ply\n";
        outfile << "format ascii 1.0\n";
        outfile << "element vertex " << vertices.size() << "\n";
        outfile << "property float x\n";
        outfile << "property float y\n";
        outfile << "property float z\n";
        outfile << "end_header\n";
        for (const auto &vertex : vertices)
        {
            outfile << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
        }
    }
    else
    {
        qDebug() << "Failed to create file.\n";
        return;
    }
}

void Txt2Ply::translate(const QString &inputFilename,const QString &outputFileName){

    qDebug()<<"begin\n";
    vector<Vertex> vertices = readVerticesFromTxt(inputFilename);
    writeVerticesToPly(vertices, outputFileName);
    //Sleep(1000);
    qDebug()<<"end";
    emit processingFinished();
}
