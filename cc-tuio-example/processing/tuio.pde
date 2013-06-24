import java.util.Vector;
import TUIO.*;

TuioProcessing tuioClient;

void setup()
{
  size(640, 480);
  fill(0);
  
  loop();
  frameRate(60);
  
  tuioClient = new TuioProcessing(this);
}

void draw()
{
  background(128, 128, 196);
  Vector<TuioCursor> tuioCursorList = tuioClient.getTuioCursors();
  
  for (int i = 0; i < tuioCursorList.size(); i++)
  {
    TuioCursor cur = tuioCursorList.elementAt(i);
    fill(255);
    ellipse (cur.getScreenX(width), cur.getScreenY(height), 15, 15);
  }
  
  Vector<TuioObject> tuioObjectList = tuioClient.getTuioObjects();
  for (int i = 0; i < tuioObjectList.size(); i++)
  {
    TuioObject obj = tuioObjectList.elementAt(i);
    fill (255);
    rect (obj.getScreenX(width) - 30, obj.getScreenY(height) - 30, 30, 30, 10);
  }
}

// called when an object is added to the scene
void addTuioObject(TuioObject tobj) {
  println("add object "+tobj.getSymbolID()+" ("+tobj.getSessionID()+") "+tobj.getX()+" "+tobj.getY()+" "+tobj.getAngle());
}

// called when an object is removed from the scene
void removeTuioObject(TuioObject tobj) {
  println("remove object "+tobj.getSymbolID()+" ("+tobj.getSessionID()+")");
}

// called when an object is moved
void updateTuioObject (TuioObject tobj) {
  println("update object "+tobj.getSymbolID()+" ("+tobj.getSessionID()+") "+tobj.getX()+" "+tobj.getY()+" "+tobj.getAngle()
          +" "+tobj.getMotionSpeed()+" "+tobj.getRotationSpeed()+" "+tobj.getMotionAccel()+" "+tobj.getRotationAccel());
}

// called when a cursor is added to the scene
void addTuioCursor(TuioCursor tcur) {
  println("add cursor "+tcur.getCursorID()+" ("+tcur.getSessionID()+ ") " +tcur.getX()+" "+tcur.getY());
}

// called when a cursor is moved
void updateTuioCursor (TuioCursor tcur) {
  println("update cursor "+tcur.getCursorID()+" ("+tcur.getSessionID()+ ") " +tcur.getX()+" "+tcur.getY()
          +" "+tcur.getMotionSpeed()+" "+tcur.getMotionAccel());
}

// called when a cursor is removed from the scene
void removeTuioCursor(TuioCursor tcur) {
  println("remove cursor "+tcur.getCursorID()+" ("+tcur.getSessionID()+")");
}

// called after each message bundle
// representing the end of an image frame
void refresh(TuioTime bundleTime) { 
}
