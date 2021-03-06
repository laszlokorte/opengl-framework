//
//  first_person_movement.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 10.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "./first_person_movement.h"

namespace lkogl {
    namespace input {
        namespace movement {

            FirstPersonMovement::FirstPersonMovement()
            {
            }
            
            void FirstPersonMovement::rotateHorizontally(scene::EntityTransformation& cam, float radians) const
            {
                auto q = math::angleAxis(-radians, up_);
                
                cam.setRotation(math::normalize(q * cam.rotation()));
            }
            
            void FirstPersonMovement::rotateVertically(scene::EntityTransformation& cam, float radians) const
            {
                auto q = math::angleAxis(-radians, sideward_);
                
                math::Quat<float> newRot = math::normalize(cam.rotation() * q);
                
                if(math::dot(newRot * up_, up_) > 0) {
                    cam.setRotation(newRot);
                }
            }
            
            void FirstPersonMovement::move(scene::EntityTransformation& cam, math::Vec2<float> dir2d, float amount) const
            {
                if(math::length(math::normalize(dir2d)) == 0) return;

                auto dir = cam.rotation() * -math::Vec3<float>(dir2d.x, 0, dir2d.y);
                if(!fly_) {
                    dir.y = 0;
                }
                auto newPos = cam.translation() + amount*math::normalize(dir);
                cam.setTranslation(newPos);
            }
            
            void FirstPersonMovement::lookAt(scene::EntityTransformation& cam, math::Vec3<float> p) const
            {
                math::Vec3<float> direction = math::normalize(p - cam.translation());
                
                math::Quat<float> rot1 = math::rotation(-forward_, direction);
                // Recompute desiredUp so that it's perpendicular to the direction
                // You can skip that part if you really want to force desiredUp
                math::Vec3<float> right = math::cross(direction, up_);
                math::Vec3<float> desiredUp = math::normalize(math::cross(right, direction));
                
                
                // Because of the 1rst rotation, the up is probably completely screwed up.
                // Find the rotation between the "up" of the rotated object, and the desired up
                math::Vec3<float> newUp = rot1 * up_;
                math::Quat<float> rot2 = math::rotation(newUp, desiredUp);
                cam.setRotation(rot2 * rot1);
            }
            
            void FirstPersonMovement::setFly(bool allowFly)
            {
                fly_ = allowFly;
            }
            
            bool FirstPersonMovement::canFly() const
            {
                return fly_;
            }
            
        }
    }
}
