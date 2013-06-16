#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle( Vec2f loc, float radius)
{
  mLoc	  = loc;
  mDir	  = Rand::randVec2f();
  mVel	  = 1.0f;
  mRadius = radius;
  mLife   = 255;

  mColor  = Color( 1.0f, 1.0f, 1.0f );
}	


void Particle::update()
{
  //mRadius = channel.getValue( mLoc ) * 7.0f;
  //  
  //float gray = channel.getValue( mLoc );
  //mColor = Color( gray, gray, gray );
  
  mLoc += mDir * mVel;

  // Life Counter
  mLife-=1;
  if( (mLife) < 0 ){ mLife=0; }        

  // 
  if( ((mLife%3)==0) && (mLife > 0) ){
    mRadius -= 0.1f;
  }
  
}


void Particle::update( const Channel32f &channel )
{
  mRadius = channel.getValue( mLoc ) * 7.0f;

  //float gray = channel.getValue( mLoc );
  
  mLoc += mDir * mVel;
}


void Particle::draw()
{
  gl::color( mColor );
  gl::drawSolidCircle( mLoc, mRadius );
}
