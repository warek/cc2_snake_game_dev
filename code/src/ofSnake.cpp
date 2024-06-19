#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    colorIO.set(255);
}

ofSnake::~ofSnake() {

}

void ofSnake::updateSnake() {

    myPos.x = myPos.x + xSpeed * cell_size;
    myPos.y = myPos.y + ySpeed * cell_size;

    //min-max range maped to canvas
    myPos.x = ofClamp(myPos.x, 0, ofGetWidth() - cell_size);
    myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - cell_size);

}


void ofSnake::drawSnake() {

    ofSetColor(colorIO);
    ofDrawRectangle(myPos.x, myPos.y, cell_size, cell_size);
    
}


void ofSnake::setDir(int x, int y) {
    
    xSpeed = x;
    ySpeed = y;

    
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < cell_size) {
        
        std::cout << " eat !" << std::endl;

        return true;
    }

    return false;

}
