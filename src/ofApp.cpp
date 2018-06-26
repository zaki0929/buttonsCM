#include "ofApp.h"

//--------------------------------------------------------------
ofApp::Button::Button(){
  initButton(-100, int(ofGetHeight()/2), 40);
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
void ofApp::setupMode1(){
  mode1_flag = 0;
  b[0].initButton(-300, center_y-160, 40);
  b[1].initButton(-200, center_y-80, 40);
  b[2].initButton(-100, center_y, 40);
  b[3].initButton(-200, center_y+80, 40);
  b[4].initButton(-300, center_y+160, 40);
}

//--------------------------------------------------------------
void ofApp::updateMode1(){
  switch(mode1_flag){
    // ">>>>" 入場
    case 0:
      for(int i=0; i<5; i++){
        if(b[2].x < 1200){
          b[i].x++;
        }else{
          mode1_flag = 1;
        }
      }
      for(int i=1; i<=3; i++){
        if(b[2].x > i*300){
          b[20-(i*5)].initButton(i*300-200, center_y-160, 40);
          b[21-(i*5)].initButton(i*300-100, center_y-80, 40);
          b[22-(i*5)].initButton(i*300, center_y, 40);
          b[23-(i*5)].initButton(i*300-100, center_y+80, 40);
          b[24-(i*5)].initButton(i*300-200, center_y+160, 40);
        }
      }
      break;

    // ">>>>" 退場 
    case 1:
      for(int i=15; i<20; i++){
        b[i].x++;
      }
      for(int i=1; i<=4; i++){
        if(b[17].x > i*300){
          for(int j=0; j<5; j++){
            b[20+j-(i*5)].x = b[15+j].x;
          }
        }
      }
      if(b[17].x > 2000){
        mode1_flag = 2;    // mode1 終了 
      }
      break;
  }
}

//--------------------------------------------------------------
void ofApp::setupMode2(){
  mode2_flag = 0;
  mode2_step = 0;
  mode2_step2 = 0;
  for(int j=0; j<5; j++){
    for(int i=0; i<4; i++){
      b[i+(j*4)].initButton(-100, center_y-120+(i*100), 40);
    }
  }
}

//--------------------------------------------------------------
void ofApp::updateMode2(){
  switch(mode2_flag){
    // "|||||" 入場
    case 0:
      for(int i=0; i<4; i++){
        if(b[mode2_step*4].x < 1160-(mode2_step*100)){
          b[mode2_step*4+i].x++;
        }else{
          if(mode2_step < 4){
            mode2_step++;
          }else{
            mode2_flag = 1;
          }
        }
      }
      break;

    // "|||||" 退場 
    case 1:
      for(int i=0; i<4; i++){
        if(b[mode2_step2*4].x < 2000){
          b[mode2_step2*4+i].x++;
        }else{
          if(mode2_step2 < 4){
            mode2_step2++;
          }else{
            mode2_flag = 2;    // mode2 終了 
          }
        }
      }
      break;
  }
}

//--------------------------------------------------------------
void ofApp::setupMode3(){
  mode3_flag = 0;
  mode3_step = 0;
  mode3_r = 200;
  for(int i=0; i<20; i++){
    b[i].initButton(-mode3_r-(i*500), center_y*2-mode3_r, mode3_r);
  }
}

//--------------------------------------------------------------
void ofApp::updateMode3(){
  switch(mode3_flag){
    case 0:
      for(int i=0; i<20; i++){
        // 右に移動
        if(b[i].y == center_y*2-mode3_r && b[i].x < center_x*2-mode3_r){
          b[i].x++;
	}
        // 上に移動
        if(b[i].x == center_x*2-mode3_r && b[i].y > mode3_r){
          b[i].y--;
	}
        // 左に移動
        if(b[i].y == mode3_r && b[i].x > mode3_r){
          b[i].x--;
	}
        // 下に移動
        if(b[i].x == mode3_r && b[i].y < center_y*2-mode3_r){
          b[i].y++;
	  if(b[i].y == center_y*2-mode3_r){    // 少しずらしてループから抜ける
            b[i].y++;
          }
	}
        // 下にフェードアウト
        if(b[i].x == mode3_r && b[i].y > center_y*2-mode3_r){
          b[i].y++;
	}
      }
      
      if(b[19].y > center_y*2+mode3_r){
        mode3_flag = 2;    // mode3 終了 
      }
      break;
  }
}

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(1920, 1080);
  ofBackground(30, 30, 30);

  center_x = int(ofGetWidth()/2);
  center_y = int(ofGetHeight()/2);

  now = 0;
  anime_num = 3;

  mode1_flag = -1;
  mode2_flag = -1;
  mode3_flag = -1;

  order.push_back(3);
  order.push_back(2);
  order.push_back(1);
} 

//--------------------------------------------------------------
void ofApp::update(){
  if(order[now] == 1){
    if(mode1_flag == -1){
      setupMode1();
    }
    updateMode1();
    if(mode1_flag == 2){
      now++;
    }
  }

  if(order[now] == 2){
    if(mode2_flag == -1){
      setupMode2();
    }
    updateMode2();
    if(mode2_flag == 2){
      now++;
    }
  }

  if(order[now] == 3){
    if(mode3_flag == -1){
      setupMode3();
    }
    updateMode3();
    if(mode3_flag == 2){
      now++;
    }
  }

  if(now == anime_num){
    now = 0;
    mode1_flag = -1;
    mode2_flag = -1;
    mode3_flag = -1;
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  for(int i=0; i<20; i++){
    b[i].drawButton();
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
