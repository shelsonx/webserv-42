#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include "defines.hpp"
#include "Headers.hpp"
#include "StringUtils.hpp"

struct MultiPartData
{
  MultiPartData();
  std::string name;
  std::string fileName;
  std::string contentDisposition;
  std::string contentType;
  std::string data;
  bool bodyParsed;
  bool headersParsed;
  bool dataHasStarted;
  bool parseHeaders(std::vector<std::string> &headers);
  bool parseBody(std::string line, ssize_t contentLengthNbr, std::string boundary);
  void setContentDisposition(std::string contentDisposition);
  bool hasFoundBoundaryEnd(std::string line, std::string boundary);
  bool isFileData();
};

class Body
{
  public:
    Body();
    virtual ~Body();
    Body(const Body &other);
    Body &operator=(const Body &other);
    std::string getBody() const;
    void setBody(std::string body);
    void clearBody();
    void clear();
    void setBodyFullyRead(bool bodyFullyRead);
    bool getBodyFullyRead() const;
    virtual bool parseBody(std::string line, ssize_t contentLength);
    virtual bool parseChunkedBody(std::string line);
    std::string parseChunkedBodyLine(std::string chunkData, ssize_t chunkSize);
    std::string sliceChuckedBody(std::string line);
    virtual bool parseMultiPartBody(std::string line, ssize_t contentLength, std::string boundary);
    MultiPartData getMultiPartData() const;
    std::string &getBodyUnparsed();
  	void resetMultiPartData();

  private:
    std::string body;
    std::string bodyUnparsed;
    MultiPartData multiPartData;
    bool bodyFullyRead;
    std::string findBoundaryStart(std::string line, std::string boundary);
};
