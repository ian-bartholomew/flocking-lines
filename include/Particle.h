//
//  Particle.h
//  FlockingLines2
//
//  Created by HUGE | Ian Bartholomew on 9/30/13.
//
//

#pragma once

#include "cinder/Vector.h"
#include "cinder/Thread.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Particle {
  public:
	Particle();
    Particle( ci::Vec3f pos, ci::Vec3f vel, bool followed );
    
    void pullToCenter( const ci::Vec3f &center );
	virtual void update( bool flatten );
	virtual void draw();
    void shutdown();
	virtual void limitSpeed();
	void addNeighborPos( ci::Vec3f pos );
    
    ci::Vec3f	mPos;
	ci::Vec3f	mTailPos;
	ci::Vec3f	mVel;
	ci::Vec3f	mVelNormal;
	ci::Vec3f	mAcc;
	
	ci::Vec3f	mNeighborPos;
	int			mNumNeighbors;    	
    
	float		mDecay;
	float		mRadius;
	float		mLength;
	float		mMaxSpeed, mMaxSpeedSqrd;
	float		mMinSpeed, mMinSpeedSqrd;
	float		mFear;
	float		mCrowdFactor;
    
	bool		mIsDead;
	bool		mFollowed;
    
    ci::Color	mColor;
    
    const float DIST_THRESH     = 200.0f;
    const float PULL_STRENGTH   = 0.00025f;
private:
    std::vector<shared_ptr<thread>>		mThreads;
};
