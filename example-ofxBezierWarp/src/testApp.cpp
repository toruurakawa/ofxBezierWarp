#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    bUseWarp = true;
    
    // load a movie for testing purposes
    vid.loadMovie("wall.mov");
    vid.play();
    
    // allocate the warp with width, height, numXControlPoints,  
    // numYControlPoints, and the resolution of grid divisions in pixels
    
    // NB: the bezier warp needs to use only power of 2 sizes internallyxr
    // but can use any width/height passed during allocation (internally
    // we scale the fbo we are warping) - so it's good to sometimes use
    // sizes a little smaller than normal if efficieny is your thing
    // eg., 1920 x 1080 will force the use of 2048 x 2048 internal fbo
    // but an 1820 x 1024 size will only use a 2048 x 1024 internal fbo ;)
    
    warp.allocate(ofGetWidth(), ofGetHeight(), 5, 4, 80);
    if (warp.loadXMLWithFileName("mySettings.xml")){
        cout << "XML has been loaded!" << endl;
        warp.loadPointsFromXML();
    }
    
    ofBackground(0, 0, 0);
    bShowVideo = true;
}

//--------------------------------------------------------------
void testApp::update(){
    
    vid.update();
    
    if(bUseWarp){
        
        // use the bezier warp like an fbo by calling 
        // begin() and end() around anything you want warped
        
        warp.begin();
        {
            if(bShowVideo) vid.draw(0, 0, ofGetWidth(), ofGetHeight());
            
        }
        warp.end();
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(bUseWarp){
        // draw using the bezier warp
        warp.draw();
    }else{
        // draw the video without the warp
        vid.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    if (bShowText) {
        // show some info
        ostringstream os;
        os << "Press 'w' to toggle using warp" << endl;
        os << "Press 'r' to reset the warp grid" << endl;
        os << "Press 'g' to show the warp grid" << endl;
        os << "Press 'f' to fetch points from a XML file" << endl;
        os << "Press 's' to save current settings to the XML file" << endl;
        os << "Press 'z' to select next point" << endl;
        os << "Press 'x' to select previous point" << endl;
        os << "Press 'j,k,h,l' to move selected point Down/Up/Left/Right" << endl;
        os << "Use arrow keys to increase/decrease number of warp control points" << endl;
        os << endl;
        os << "FPS: " << ofGetFrameRate();
        ofDrawBitmapString(os.str(), 20, 20);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'w':
            bUseWarp = !bUseWarp;
            break;
        case 'r':
            warp.resetWarpGrid();
            break;
        case 's':
            warp.saveXML();
            break;
//        case 'p':
//            warp.setWarpGridPosition(100, 100, (ofGetWidth() - 200), (ofGetHeight() - 200));
//            break;
        case OF_KEY_UP:
            warp.setWarpGrid(warp.getNumXPoints(), warp.getNumYPoints() + 1);
            break;
        case OF_KEY_RIGHT:
            warp.setWarpGrid(warp.getNumXPoints() + 1, warp.getNumYPoints());
            break;
        case OF_KEY_DOWN:
            warp.setWarpGrid(warp.getNumXPoints(), warp.getNumYPoints() - 1);
            break;
        case OF_KEY_LEFT:
            warp.setWarpGrid(warp.getNumXPoints() - 1, warp.getNumYPoints());
            break;
        case 'f':
            warp.loadXML();
            warp.loadPointsFromXML();
            break;
//        case 'f':
//            warp.loadPointsFromXML();
//            break;
        case 'g':
            warp.toggleShowWarpGrid();
            break;
        case 'z':
            warp.selectPrevPointIndex();
            break;
        case 'x':
            warp.selectNextPointIndex();
            break;
        case 'j':
            if(warp.isAdjustingRow || warp.isAdjustingColumn)  warp.moveSelectedLineDown();
            else warp.moveSelectedPointPositionDown();
            break;
        case 'k':
            if(warp.isAdjustingRow || warp.isAdjustingColumn)  warp.moveSelectedLineUp();
            else warp.moveSelectedPointPositionUp();
            break;
        case 'h':
            if(warp.isAdjustingRow || warp.isAdjustingColumn)  warp.moveSelectedLineLeft();
            warp.moveSelectedPointPositionLeft();
            break;
        case 'l':
            if(warp.isAdjustingRow || warp.isAdjustingColumn)  warp.moveSelectedLineRight();
            warp.moveSelectedPointPositionRight();
            break;
        case 'p':
            warp.adjustByPoint();
            break;
        case 'c':
            warp.adjustByRow();
            break;
        case ',':
            warp.adjustByColumn();
            break;
        case 'v':
            bShowVideo = !bShowVideo;
            break;
        case 't':
            bShowText = !bShowText;
            break;
        case '1':
            ofToggleFullscreen();
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}