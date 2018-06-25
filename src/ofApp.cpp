#include "ofApp.h"

//--------------------------------------------------------------
void drawButton(int x, int y, int r){
  // 円の解像度の指定
  ofSetCircleResolution(64);

  // 本体の描画 
  ofSetColor(200, 200, 200);
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
  bx = 0;
  by = 0;
  br = 100;
} 

//--------------------------------------------------------------
void ofApp::update(){
  bx++;
  by++;
}

//--------------------------------------------------------------
void ofApp::draw(){
  drawButton(bx, by, br);
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
