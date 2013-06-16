#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <vector>

class Particle {
 public:
  Particle();
  Particle( ci::Vec2f, float radius=10.0f );

  void update();
  void update( const ci::Channel32f &channel );
  void draw();
  
  ci::Vec2f     mLoc;     // Position
  ci::Vec2f     mDir;     // Direction
  float         mVel;     //
  
  float	        mRadius;  //

  int           mLife;    // Life Level
  
  ci::Color     mColor;   // Color 
};
