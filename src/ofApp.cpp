#include "ofApp.h"

//--------------------------------------------------------------
ofApp::Button::Button(){
  initButton(100, 100, 40);
}

//--------------------------------------------------------------
void ofApp::Button::initButton(int set_x, int set_y, int set_r){
  x = set_x;
  y = set_y;
  r = set_r;
}

//--------------------------------------------------------------
void ofApp::Button::drawButton(){
  // 円の解像度の指定
  ofSetCircleResolution(64);

  // 本体の描画 
  ofSetColor(220, 220, 220);
  ofCircle(x, y, r);

  // 穴の描画
  ofSetColor(30, 30, 30);
  ofCircle(x-(r/5), y-(r/5), r/8);
  ofCircle(x+(r/5), y-(r/5), r/8);
  ofCircle(x-(r/5), y+(r/5), r/8);
  ofCircle(x+(r/5), y+(r/5), r/8); 
} 

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(30, 30, 30);
  //initButton(0, 0, 100);
} 

//--------------------------------------------------------------
void ofApp::update(){
  b[0].x++;
  b[0].y++;
}

//--------------------------------------------------------------
void ofApp::draw(){
  b[0].drawButton();
  for(int i=1; i<20; i++){
    if(b[0].x > i*100){
      b[i].initButton(i*100, i*100, 40);
      b[i].drawButton();
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

} 

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
