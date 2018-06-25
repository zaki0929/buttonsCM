#include "ofApp.h"

//--------------------------------------------------------------
ofApp::Button::Button(){
  initButton(100, int(ofGetHeight()/2), 40);
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
  center_x = int(ofGetWidth()/2);
  center_y = int(ofGetHeight()/2);

  ofBackground(30, 30, 30);
  
  b[0].initButton(-200, center_y-160, 40);
  b[1].initButton(-100, center_y-80, 40);
  b[2].initButton(0, center_y, 40);
  b[3].initButton(-100, center_y+80, 40);
  b[4].initButton(-200, center_y+160, 40);
  
} 

//--------------------------------------------------------------
void ofApp::update(){
  for(int i=0; i<5; i++){
    if(b[0].x < 1200){
      b[i].x++;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  
  for(int i=0; i<5; i++){
    b[i].drawButton();
  }

  for(int i=1; i<=3; i++){
    if(b[0].x > i*300){
      b[0+(i*5)].initButton(i*300-200, center_y-160, 40);
      b[1+(i*5)].initButton(i*300-100, center_y-80, 40);
      b[2+(i*5)].initButton(i*300, center_y, 40);
      b[3+(i*5)].initButton(i*300-100, center_y+80, 40);
      b[4+(i*5)].initButton(i*300-200, center_y+160, 40);

      for(int j=0; j<5; j++){
        b[j+(i*5)].drawButton();
      }
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
