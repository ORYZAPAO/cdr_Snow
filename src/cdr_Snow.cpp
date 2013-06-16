#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"


#include "ParticleController.h"

#include "cinder/gl/Texture.h"

/*
#include "cinder/Channel.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"
#include "cinder/Rand.h"
#include "cinder/Font.h"
*/


using namespace ci;
using namespace ci::app;
using namespace std;

class cdr_Snow : public AppNative {
  public:
  void setup();
  void mouseMove( MouseEvent event );	
  void update();
  void draw();
  
  gl::Texture myImage;
	

  ParticleController myParticles;
  //Surface            mySurface;
};

//------------------------------------------------------------
//--
//------------------------------------------------------------
void cdr_Snow::setup()
{
	setFrameRate(20);

	myParticles.addParticles(100);
}

//------------------------------------------------------------
//--
//------------------------------------------------------------
void cdr_Snow::mouseMove( MouseEvent event )
{
  cinder::Vec2i  pos = event.getPos();

  myParticles.addParticle( pos.x, pos.y, 10 );
}

//------------------------------------------------------------
//--
//------------------------------------------------------------
void cdr_Snow::update()
{
	myParticles.update();
}

//------------------------------------------------------------
//--
//------------------------------------------------------------
void cdr_Snow::draw()
{  
  // clear out the window with black
  gl::clear( Color( 0, 0, 0.2f ) );
  myParticles.draw();
}

CINDER_APP_NATIVE( cdr_Snow, RendererGl )
