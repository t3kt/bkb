//
//  TextureToolApp.cpp
//  bkbTextureTool
//
//  Created by tekt on 1/27/15.
//
//

#include "TextureToolApp.h"

void TextureToolApp::setup() {
  ofSetLogLevel(OF_LOG_VERBOSE);
  _model.load("bowl_walls.obj");
//  ofSetColor(ofFloatColor::white);
  for (auto& name : _model.getGroupNames()) {
    ofLogVerbose() << "group: " << name;
  }
  for (const auto& group : _model.groups) {
    int i = 0;
    for (const auto& face : group.faces) {
      ofFbo fbo;
      fbo.allocate(1024, 1024);
      fbo.begin();
//      ofClearAlpha();
      ofClear(ofFloatColor(0, 0, 0, 0));
      ofPath path;
      path.setColor(ofFloatColor(1, 0, 0, 1));
      bool first = true;
      for (const auto& uv : face.texCoords) {
        if (first) {
          path.moveTo(uv.x * 1024, uv.y * 1024);
          first = false;
        } else {
          path.lineTo(uv.x * 1024, uv.y * 1024);
        }
      }
      path.setFilled(true);
      path.close();
      path.draw();
      fbo.end();
      ofImage image;
      image.allocate(1024, 1024, OF_IMAGE_COLOR_ALPHA);
      fbo.readToPixels(image.getPixelsRef());
      image.saveImage("segment_" + group.name + "_" + ofToString(i) + ".tif");
      i++;
    }
  }
}

void TextureToolApp::update() {
  
}

void TextureToolApp::draw() {
//  const auto& group = _model.groups.front();
//  const auto& face = group.faces.front();
  
}
