#include <ofMain.h>
#include <ofxOBJModel.h>

//========================================================================
int main( ){
  // for some reason without calling this, the data root path doesn't get
  // set up properly and i don't feel like figuring out why
  ofSetupOpenGL(1024,1024,OF_WINDOW);
  
  ofSetLogLevel(OF_LOG_VERBOSE);
  ofxOBJModel model;
  model.load("bowl_walls.obj");
  for (auto& name : model.getGroupNames()) {
    ofLogVerbose() << "group: " << name;
  }
  for (const auto& group : model.groups) {
    int i = 0;
    for (const auto& face : group.faces) {
      ofFbo fbo;
      fbo.allocate(1024, 1024);
      fbo.begin();
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
