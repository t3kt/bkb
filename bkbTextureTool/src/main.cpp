#include <ofMain.h>
#include <ofxOBJModel.h>
#include <sstream>
#include <iomanip>

static void generateImage(const ofxOBJFace& face, int i) {
  ofFbo fbo;
  fbo.allocate(1024, 1024);
  fbo.begin();
  ofClear(ofFloatColor(0, 0, 0, 0));
  ofPath path;
  path.setColor(ofFloatColor(1, 1, 1, 1));
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
  std::ostringstream name;
  name << "segment_";
  name << std::setw(3) << std::setfill('0') << std::right << i;
  name << ".tif";
  ofFile file(name.str(), ofFile::WriteOnly, true);
  if (file.exists())
    file.remove();
  ofLogVerbose() << "writing image: " << file.path();
  image.saveImage(file);
}

static void generateImages(const ofxOBJGroup& group, int& i) {
  ofLogVerbose() << "writing group images: " << group.name;
  for (const auto& face : group.faces) {
    generateImage(face, i);
    i++;
  }
}

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
  int i = 0;
  generateImages(*model.getGroup("left_wall"), i);
  generateImages(*model.getGroup("right_wall"), i);
  generateImages(*model.getGroup("middle_wall"), i);
}
