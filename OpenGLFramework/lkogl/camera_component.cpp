//
//  camera_component.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 10.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include <iostream>

#include "camera_component.h"

namespace lkogl {
    namespace scene {
        namespace components {
            CameraComponent::CameraComponent(camera::Camera cam) : camera_(cam)
            {
            }
            
            void CameraComponent::update(TreeTransformation& transformation) const
            {
            }
            
            void CameraComponent::render(const TreeTransformation& transformation, const graphics::Program& program) const
            {
                graphics::CameraMatrixUse(program, camera_.viewProjectionMatrix(), camera_.position());
            }
            
            camera::Camera& CameraComponent::camera()
            {
                return camera_;
            }
        
            CameraComponent::~CameraComponent()
            {
            }
        }
    }
}
