//
//  NoiseBall.hpp
//  FinalProject2
//
//  Created by 王钰 on 17/03/2023.
//

#ifndef NoiseBall_hpp
#define NoiseBall_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Ball.hpp"

class NoiseBall : public Ball
{
    
public:
    void update();
    void interact(int distance);
    
    float range = 0;
};

#endif /* NoiseBall_hpp */
