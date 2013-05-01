/*
 * ofxBezierWarp.h
 *
 * Copyright 2013 (c) Matthew Gingold http://gingold.com.au
 * Adapted from: http://forum.openframeworks.cc/index.php/topic,4002.0.html
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 * If you're using this software for something cool consider sending 
 * me an email to let me know about your project: m@gingold.com.au
 *
 */

#ifndef _H_OFXBEZIERWARP
#define _H_OFXBEZIERWARP

#include "ofFbo.h"
#include "ofGraphics.h"
#include "ofEvents.h"
#include "ofxXmlSettings.h"

class ofxBezierWarp {
    
public:
	
    ofxBezierWarp();
    ~ofxBezierWarp();
    
    void allocate(int w, int h);
    void allocate(int w, int h, int numXPoints, int numYPoints, float pixelsPerGridDivision);
    
    void begin();
    void end();
    
    void draw();
    void draw(float x, float y);
    void draw(float x, float y, float w, float h);
    
    void setWarpGrid(int numXPoints, int numYPoints, bool forceReset = false);
    void setWarpGridPosition(float x, float y, float w, float h);
    
    void setWarpGridResolution(float pixelsPerGridDivision);
    void setWarpGridResolution(int gridDivisionsX, int gridDivisionsY);
    
    void resetWarpGrid();
    void resetWarpGridPosition();
    
    float getWidth();
    float getHeight();
    
    int getNumXPoints();
    int getNumYPoints();
    
    int getGridDivisionsX();
    int getGridDivisionsY();
    
    void toggleShowWarpGrid();
    void setShowWarpGrid(bool b);
    bool getShowWarpGrid();
    
    ofFbo& getFBO();
    
    ofTexture& getTextureReference();
    
    void setControlPoints(vector<GLfloat> controlPoints);
    
    vector<GLfloat> getControlPoints();
    vector<GLfloat>& getControlPointsReference();
    
    void mouseMoved(ofMouseEventArgs & e);
    void mouseDragged(ofMouseEventArgs & e);
    void mousePressed(ofMouseEventArgs & e);
    void mouseReleased(ofMouseEventArgs & e);
    
    
    string xmlFileName;
    bool loadXMLWithFileName(string);
    bool loadXML();
    void loadPointsFromXML();
    bool saveXMLWitfhFileName(string);
    bool saveXML();

    int selectedPointIndex;
    void selectNextPointIndex();
    void selectPrevPointIndex();
   
    void setSelectedPointPosition(float x, float y);
    void moveSelectedPointPositionUp();
    void moveSelectedPointPositionDown();
    void moveSelectedPointPositionLeft();
    void moveSelectedPointPositionRight();
    
protected:
	
    void drawWarpGrid(float x, float y, float w, float h);
    
    bool bShowWarpGrid;
    bool bWarpPositionDiff;
    
    ofFbo fbo;
    
    float width;
    float height;
    
    float warpWidth;
    float warpHeight;
    float warpX;
    float warpY;
    
    int currentCntrlX;
    int currentCntrlY;
    
    int numXPoints;
    int numYPoints;
    
    int gridDivX;
    int gridDivY;
    
    vector<GLfloat> cntrlPoints;
    
    ofxXmlSettings XML;
    void savePointsToXML();
    
private:
	
};

#endif
