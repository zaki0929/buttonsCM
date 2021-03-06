#include "ofApp.h"

//--------------------------------------------------------------
ofApp::Button::Button(){
  // とりあえず左端にボタンを避けておく
  initButton(-100, int(ofGetHeight()/2), 40);
}

//--------------------------------------------------------------
// ボタンの位置と半径を初期化する関数
void ofApp::Button::initButton(int set_x, int set_y, int set_r){
  x = set_x;
  y = set_y;
  r = set_r;
}

//--------------------------------------------------------------
// ボタンを描画する関数
void ofApp::Button::drawButton(int red, int green, int blue){
  // 円の解像度の指定
  ofSetCircleResolution(64);

  // 本体の描画 
  ofSetColor(red, green, blue);
  ofCircle(x, y, r);

  // 穴の描画
  ofSetColor(30, 30, 30);
  ofCircle(x-(r/5), y-(r/5), r/8);
  ofCircle(x+(r/5), y-(r/5), r/8);
  ofCircle(x-(r/5), y+(r/5), r/8);
  ofCircle(x+(r/5), y+(r/5), r/8); 
} 

//--------------------------------------------------------------
// mode1 を描画するための準備をする関数
void ofApp::setupMode1(){
  mode1_flag = 0;
  b[0].initButton(-300, center_y-160, 40);
  b[1].initButton(-200, center_y-80, 40);
  b[2].initButton(-100, center_y, 40);
  b[3].initButton(-200, center_y+80, 40);
  b[4].initButton(-300, center_y+160, 40);
}

//--------------------------------------------------------------
// mode1 の描画を更新するための関数
void ofApp::updateMode1(){
  switch(mode1_flag){
    case 0:    // ">>>>" 入場
      for(int i=0; i<5; i++){
        if(b[2].x < 1200){
          b[i].x += 10;
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

    case 1:    // ">>>>" 退場 
      for(int i=15; i<20; i++){
        b[i].x += 10;
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
// mode2 を描画するための準備をする関数
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
// mode2 の描画を更新するための関数
void ofApp::updateMode2(){
  switch(mode2_flag){
    case 0:    // "|||||" 入場
      for(int i=0; i<4; i++){
        if(b[mode2_step*4].x < 1160-(mode2_step*100)){
          b[mode2_step*4+i].x += 10;
        }else{
          if(mode2_step < 4){
            mode2_step++;
          }else{
            mode2_flag = 1;
          }
        }
      }
      break;

    case 1:    // "|||||" 退場 
      for(int i=0; i<4; i++){
        if(b[mode2_step2*4].x < 2000){
          b[mode2_step2*4+i].x += 10;
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
// mode3 を描画するための準備をする関数
void ofApp::setupMode3(){
  mode3_flag = 0;
  mode3_step = 0;
  mode3_r = 200;    // ボタンの半径
  for(int i=0; i<20; i++){
    b[i].initButton(-mode3_r-(i*500), center_y*2-mode3_r, mode3_r);
  }
}

//--------------------------------------------------------------
// mode3 の描画を更新するための関数
void ofApp::updateMode3(){
  switch(mode3_flag){
    case 0:
      for(int i=0; i<20; i++){
        // 右に移動
        if(b[i].y == center_y*2-mode3_r && b[i].x < center_x*2-mode3_r){
          b[i].x += 10;
    	}
        // 上に移動
        if(b[i].x == center_x*2-mode3_r && b[i].y > mode3_r){
          b[i].y -= 10;
    	}
        // 左に移動
        if(b[i].y == mode3_r && b[i].x > mode3_r){
          b[i].x -= 10;
    	}
        // 下に移動
        if(b[i].x == mode3_r && b[i].y < center_y*2-mode3_r){
          b[i].y += 10;
    	  if(b[i].y == center_y*2-mode3_r){    // 少しずらしてループから抜ける
            b[i].y += 10;                      // ここでずらさなかったらもう一周する
          }
    	}
        // 下にフェードアウト
        if(b[i].x == mode3_r && b[i].y > center_y*2-mode3_r){
          b[i].y += 10;
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
  // ウィンドウサイズを 1920 x 1080 とする 
  ofSetWindowShape(1920, 1080);
  ofSetFrameRate(60);
  ofBackground(30, 30, 30);

  // XMLファイルの読み込み
  if(!XML.loadFile("settings.xml")){
    ofLogError("Position file did not load!");
  }
  // パラメータの読み込み
  anime_num = XML.getValue("settings:anime_num", 3);
  order.push_back(XML.getValue("settings:order1", 1));
  order.push_back(XML.getValue("settings:order2", 2));
  order.push_back(XML.getValue("settings:order3", 3));
  time = XML.getValue("settings:time", 30);
  style = XML.getValue("settings:style", 0);

  // 描画開始時間を取得
  starttime = ofGetSeconds() + (ofGetMinutes()*60) + (ofGetHours()*360);

  // ウィンドウの中心座標を取得
  center_x = int(ofGetWidth()/2);
  center_y = int(ofGetHeight()/2);

  // 描画を制御するための変数を初期化
  now = 0;
  mode1_flag = -1;
  mode2_flag = -1;
  mode3_flag = -1;
} 

//--------------------------------------------------------------
void ofApp::update(){
  // 指定された順番の通りに描画する
  switch(order[now]){    // order[now]: 描画中の mode番号
    case 1:    // mode1
      if(mode1_flag == -1){
        setupMode1();
      }
      updateMode1();
      if(mode1_flag == 2){    // mode1 終了
        now++;                // 次のキューへ
      }
      break;

    case 2:    // mode2
      if(mode2_flag == -1){
        setupMode2();
      }
      updateMode2();
      if(mode2_flag == 2){    // mode2 終了
        now++;                // 次のキューへ
      }
      break;

    case 3:    // mode3
      if(mode3_flag == -1){
        setupMode3();
      }
      updateMode3();
      if(mode3_flag == 2){    // mode3 終了
        now++;                // 次のキューへ 
      }
      break;
  }

  // すべてのアニメーションの描画が終了
  if(now == anime_num){
    // また始めから描画するために変数を初期化
    now = 0;
    mode1_flag = -1;
    mode2_flag = -1;
    mode3_flag = -1;
  }

  // 現在の時間を取得
  nowtime = ofGetSeconds() + (ofGetMinutes()*60) + (ofGetHours()*360);
  
  // 描画開始からの経過時間を取得
  int diff = nowtime - starttime;

  // 経過時間が指定された時間を過ぎたら描画を終了
  if(diff > time){
    ofExit();
    ofLogNotice("exit!!");
  }

  // ログをはいておく
  ofLogNotice("time: " + ofToString(diff));
  ofLogNotice("fps: " + ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
  // ボタンの描画
  switch(style){    // 指定されたスタイルにならって色を変える
    case 0:    // style: mono
      for(int i=0; i<20; i++){
        b[i].drawButton(220, 220, 220);
      }
      break;

    case 1:    // style: color
      for(int i=0; i<5; i++){
        b[i*4].drawButton(41, 128, 185);
        b[1+i*4].drawButton(243, 156, 18);
        b[2+i*4].drawButton(26, 188, 156);
        b[3+i*4].drawButton(155, 89, 182);
      }
      break;
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
