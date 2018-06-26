#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  int center_x;
  int center_y;

  int mode1_flag;
  int mode2_flag;
  int mode2_step;
  int mode2_step2;
  
  void setupMode1();
  void setupMode2();
  void updateMode1();
  void updateMode2();

  class Button{
  
  public:
    Button();
    int x;
    int y;
    int r;
    void initButton(int set_x, int set_y, int set_r);
    void drawButton();
  };

  Button b[20];
};

