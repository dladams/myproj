// MyToolInterface.h

#ifndef MyToolInterface_H
#define MyToolInterface_H

class MyToolInterface {
public:
  virtual ~MyToolInterface() { }
  virtual float transform(float x) const =0;
};

#endif
