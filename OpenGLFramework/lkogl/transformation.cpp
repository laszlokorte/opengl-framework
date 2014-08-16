//
//  transform.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 08.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "transformation.h"

namespace lkogl {
    namespace geometry {
        const Transformation::Mat4 Transformation::matrix() const
        {
            Mat4 result = math::translate(Mat4(), translation);
            result = math::rotate(result, rotation);
            result = math::scale(result, scale);

            return result;
        }
    }
}