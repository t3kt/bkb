//
//  TextureToolApp.h
//  bkbTextureTool
//
//  Created by tekt on 1/27/15.
//
//

#ifndef __bkbTextureTool__TextureToolApp__
#define __bkbTextureTool__TextureToolApp__

#include <ofMain.h>
#include <ofxOBJModel.h>

class TextureToolApp : public ofBaseApp {
public:
  void setup() override;
  void update() override;
  void draw() override;
private:
  ofxOBJModel _model;
  int _groupIndex;
  int _faceIndex;
};

#endif /* defined(__bkbTextureTool__TextureToolApp__) */
