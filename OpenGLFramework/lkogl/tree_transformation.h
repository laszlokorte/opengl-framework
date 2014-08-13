//
//  tree_transform.h
//  OpenGLFramework
//
//  Created by Laszlo Korte on 12.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#ifndef __OpenGLFramework__tree_transform__
#define __OpenGLFramework__tree_transform__

#include "transformation.h"

namespace lkogl {
    namespace scene {
        
        typedef lkogl::math::Quat<GLfloat> Quat;
        typedef lkogl::math::Mat4<GLfloat> Mat4;
        typedef lkogl::math::Vec3<GLfloat> Vec3;
        
        class TreeTransformation {
            geometry::Transformation relativTransform_;
            const TreeTransformation* parent_;
            mutable Mat4 selfMat_;
            mutable Mat4 mat_;
            mutable bool dirty_;
            
        public:
            TreeTransformation();
            TreeTransformation(const TreeTransformation&);
            ~TreeTransformation();
            
            void setParent(const TreeTransformation* p) {
                parent_ = p;
            }
                        
            const Vec3& translation() const;
            const Vec3& scale() const;
            const Quat& rotation() const;
            
            void setTranslation(const Vec3&);
            void setScale(const Vec3&);
            void setRotation(const Quat&);
            
            void add(const geometry::Transformation& t);
            
            const Mat4 matrix() const;
        
            
        private:
            bool isDirty() const;
        };
    }
}

#endif /* defined(__OpenGLFramework__tree_transform__) */