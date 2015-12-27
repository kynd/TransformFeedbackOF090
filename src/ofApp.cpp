#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    initBuffers();
    
    // Set up shaders
    renderShader.load("render.vert", "render.frag");
    
    feedbackShader.setupShaderFromFile(GL_VERTEX_SHADER, "feedback.vert");
    const GLchar* feedbackVaryings[] = {"o_position"};
    glTransformFeedbackVaryings(feedbackShader.getProgram(),1, feedbackVaryings, GL_SEPARATE_ATTRIBS);
    feedbackShader.linkProgram();
}


//--------------------------------------------------------------
void ofApp::initBuffers(){
    // Set initial vertex positions in the Buffer Objects
    ofVec4f verts[3] = {
        ofVec4f(0, 24, 0, 1.0),
        ofVec4f(24, 48, 0, 1.0),
        ofVec4f(0, 72, 0, 1.0)
    };
    positionBuffers[0].allocate();
    positionBuffers[0].setData(sizeof(ofVec4f) * 3, &verts[0].x, GL_DYNAMIC_DRAW);
    positionBuffers[1].allocate();
    positionBuffers[1].setData(sizeof(ofVec4f) * 3, &verts[0].x, GL_DYNAMIC_DRAW);
    
    // Call pingPong() once to assign Buffer Objects
    pingPong();
}

//--------------------------------------------------------------
void ofApp::update(){
    // Use transform feedback to update the Buffer Object
    glEnable(GL_RASTERIZER_DISCARD); // disable screen rendering
    feedbackShader.begin();
    glBeginTransformFeedback(GL_POINTS);
    vbo.draw(GL_POINTS, 0, 3);
    glEndTransformFeedback();
    feedbackShader.end();
    glDisable(GL_RASTERIZER_DISCARD);
    
    // Call pingPong to swap Buffer Objects
    pingPong();
}

//--------------------------------------------------------------
void ofApp::pingPong() {
    int feedbackTargetBuffer = 1 - currentAttributeBuffer;
    vbo.setVertexBuffer(positionBuffers[currentAttributeBuffer], 4, 0); // set one of the ofBufferObject as an attribute for the vertex shader
    glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, positionBuffers[feedbackTargetBuffer].getId()); // set the other ofBuffer as the target of the transform feedback
    currentAttributeBuffer = feedbackTargetBuffer;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Render normally on the screen
    renderShader.begin();
    vbo.draw(GL_TRIANGLES, 0, 3);
    renderShader.end();
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
