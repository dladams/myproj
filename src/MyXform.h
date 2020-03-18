// MyXform.h

#ifndef MyXform_H
#define MyXform_H

class MyXform {

public:

  MyXform(float scale);

  float transform(float x);

private:

  float m_scale;

};

#endif
